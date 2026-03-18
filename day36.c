#include <stdio.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int data) {
    if ((rear + 1) % MAX_SIZE == front) return;
    
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = data;
}

int dequeue() {
    if (front == -1) return -1;
    
    int data = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    return data;
}

void display() {
    if (front == -1) {
        printf("Empty\n");
        return;
    }
    
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue[rear]);
}

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }
    
    int m;
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
        dequeue();
    }
    
    display();
    return 0;
}
