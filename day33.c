#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int main() {
    char infix[100];
    scanf("%s", infix);
    
    char postfix[100] = {0};
    int k = 0;
    
    for (int i = 0; infix[i]; i++) {
        char c = infix[i];
        
        if (c >= 'A' && c <= 'Z') {
            postfix[k++] = c;
        } else if (isOperator(c)) {
            while (top >= 0 && precedence(peek()) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (peek() != '(') {
                postfix[k++] = pop();
            }
            pop();
        }
    }
    
    while (top >= 0) {
        postfix[k++] = pop();
    }
    
    printf("%s\n", postfix);
    return 0;
}
