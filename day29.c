#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

int getLength(struct Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

struct Node* rotateRight(struct Node* head, int k) {
    if (!head || !head->next) return head;
    
    int n = getLength(head);
    k = k % n;
    if (k == 0) return head;
    
    struct Node* tail = head;
    struct Node* newTail = head;
    
    for (int i = 0; i < n - k - 1; i++) newTail = newTail->next;
    for (int i = 0; i < k; i++) tail = tail->next;
    
    head = newTail->next;
    newTail->next = NULL;
    tail->next = NULL;
    
    return head;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    
    struct Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        insertEnd(&head, x);
    }
    
    int k;
    scanf("%d", &k);
    
    head = rotateRight(head, k);
    printList(head);
    
    return 0;
}
