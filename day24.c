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

struct Node* deleteFirstOccur(struct Node* head, int key) {
    if (head == NULL) return head;

    if (head->data == key) {
        struct Node* tmp = head;
        head = head->next;
        free(tmp);
        return head;
    }

    struct Node* prev = head;
    struct Node* cur = head->next;

    while (cur != NULL) {
        if (cur->data == key) {
            prev->next = cur->next;
            free(cur);
            break;
        }
        prev = cur;
        cur = cur->next;
    }
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

    head = deleteFirstOccur(head, key);

    struct Node* cur = head;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }

    cur = head;
    while (cur != NULL) {
        struct Node* tmp = cur;
        cur = cur->next;
        free(tmp);
    }

    return 0;
}
