#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void push(struct Node** top, int data) {
    struct Node* node = createNode(data);
    node->next = *top;
    *top = node;
}

int pop(struct Node** top) {
    if (*top == NULL) return 0;
    struct Node* temp = *top;
    int data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}

int evaluatePostfix(char* exp) {
    struct Node* stack = NULL;
    
    for (int i = 0; exp[i]; i++) {
        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            i--;
            push(&stack, num);
        } else {
            int b = pop(&stack);
            int a = pop(&stack);
            
            switch (exp[i]) {
                case '+': push(&stack, a + b); break;
                case '-': push(&stack, a - b); break;
                case '*': push(&stack, a * b); break;
                case '/': push(&stack, a / b); break;
            }
        }
    }
    
    return pop(&stack);
}

int main() {
    char exp[100];
    scanf("%s", exp);
    printf("%d\n", evaluatePostfix(exp));
    return 0;
}
