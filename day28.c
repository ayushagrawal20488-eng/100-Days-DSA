#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        node->data = x;
        node->next = NULL;

        if (head == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    if (tail != NULL) {
        tail->next = head;
    }

    if (head != NULL) {
        struct Node* cur = head;
        do {
            printf("%d ", cur->data);
            cur = cur->next;
        } while (cur != head);
    }

    if (head != NULL) {
        struct Node* cur = head->next;
        head->next = NULL;
        while (cur != NULL) {
            struct Node* tmp = cur;
            cur = cur->next;
            free(tmp);
        }
        free(head);
    }

    return 0;
}
