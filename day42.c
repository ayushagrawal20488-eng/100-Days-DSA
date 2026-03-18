#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);
    
    int q[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }
    
    int stack[MAX];
    int top = -1;
    
    for (int i = 0; i < n; i++) {
        stack[++top] = q[i];
    }
    
    int idx = 0;
    while (top != -1) {
        q[idx++] = stack[top--];
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");
    
    return 0;
}
