#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

int pq[MAX_SIZE];
int size = 0;

void insert(int x) {
    pq[size] = x;
    int i = size;
    
    while (i > 0 && pq[i] < pq[i-1]) {
        int temp = pq[i];
        pq[i] = pq[i-1];
        pq[i-1] = temp;
        i--;
    }
    size++;
}

int deleteMin() {
    if (size == 0) return -1;
    int min = pq[0];
    for (int i = 0; i < size - 1; i++) {
        pq[i] = pq[i+1];
    }
    size--;
    return min;
}

int peek() {
    return size > 0 ? pq[0] : -1;
}

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        char op[10];
        scanf("%s", op);
        
        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "delete") == 0) {
            printf("%d\n", deleteMin());
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }
    
    return 0;
}
