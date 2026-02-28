#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertEnd(struct Node* head, int x) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = x;
    node->next = NULL;
    if (head == NULL) return node;
    struct Node* cur = head;
    while (cur->next != NULL) cur = cur->next;
    cur->next = node;
    return head;
}

int main() {
    int n, key, x;
    struct Node* head = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }
    scanf("%d", &key);

    int count = 0;
    struct Node* cur = head;
    while (cur != NULL) {
        if (cur->data == key) count++;
        cur = cur->next;
    }

    printf("%d\n", count);

    cur = head;
    while (cur != NULL) {
        struct Node* tmp = cur;
        cur = cur->next;
        free(tmp);
    }

    return 0;
}
