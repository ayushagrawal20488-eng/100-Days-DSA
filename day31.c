#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
    if (top < MAX_SIZE - 1) {
        stack[++top] = value;
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return -1;
}

void display() {
    if (top == -1) {
        printf("Stack empty\n");
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int op;
        scanf("%d", &op);
        
        if (op == 1) {
            int value;
            scanf("%d", &value);
            push(value);
        } else if (op == 2) {
            int popped = pop();
            if (popped != -1) {
                printf("%d\n", popped);
            } else {
                printf("Stack Underflow\n");
            }
        } else if (op == 3) {
            display();
        }
    }
    
    return 0;
}
