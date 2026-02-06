#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int arr[10000];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    if(n == 0) return 0; 
    int i = 0;
    for(int j = 1; j < n; j++) {
        if(arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j];
        }
    }
    int k = i + 1;
    for(int j = 0; j < k; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n");
    return 0;
}