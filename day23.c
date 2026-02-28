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

struct Node* mergeLists(struct Node* a, struct Node* b) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (a != NULL && b != NULL) {
        if (a->data <= b->data) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    if (a != NULL) tail->next = a;
    else tail->next = b;

    return dummy.next;
}

int main() {
    int n, m, x;
    struct Node *head1 = NULL, *head2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head1 = insertEnd(head1, x);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        head2 = insertEnd(head2, x);
    }

    struct Node* merged = mergeLists(head1, head2);

    struct Node* cur = merged;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }

    cur = merged;
    while (cur != NULL) {
        struct Node* tmp = cur;
        cur = cur->next;
        free(tmp);
    }

    return 0;
}
