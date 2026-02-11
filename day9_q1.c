#include <stdio.h>
#include <string.h>
int main() {
    char s[1001];
    scanf("%s", s);
    int len = strlen(s);
    int left = 0, right = len - 1;
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
    printf("%s\n", s);
    return 0;
}