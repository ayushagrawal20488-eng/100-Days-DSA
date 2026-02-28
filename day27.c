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

int length(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = length(head1);
    int len2 = length(head2);

    int diff = len1 - len2;
    if (diff > 0) {
        while (diff--) head1 = head1->next;
    } else if (diff < 0) {
        diff = -diff;
        while (diff--) head2 = head2->next;
    }

    while (head1 != NULL && head2 != NULL) {
        if (head1->data == head2->data) 
            return head1;
        head1 = head1->next;
        head2 = head2->next;
    }
    return NULL;
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

    struct Node* inter = findIntersection(head1, head2);

    if (inter == NULL) {
        printf("No Intersection\n");
    } else {
        printf("%d\n", inter->data);
    }

    struct Node* cur = head1;
    while (cur != NULL) {
        struct Node* tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    cur = head2;
    while (cur != NULL) {
        struct Node* tmp = cur;
        cur = cur->next;
        free(tmp);
    }

    return 0;
}
