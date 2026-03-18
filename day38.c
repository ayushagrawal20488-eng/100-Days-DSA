#include <stdio.h>
#include <stdbool.h>
#define MAX 100

int dq[MAX];
int front = -1, rear = -1;

bool empty() {
    return front == -1;
}

bool full() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

void push_front(int x) {
    if (full()) return;
    if (empty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }
    dq[front] = x;
}

void push_back(int x) {
    if (full()) return;
    if (empty()) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }
    dq[rear] = x;
}

void pop_front() {
    if (empty()) return;
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

void pop_back() {
    if (empty()) return;
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

int front_element() {
    if (empty()) return -1;
    return dq[front];
}

int back_element() {
    if (empty()) return -1;
    return dq[rear];
}

int size() {
    if (empty()) return 0;
    if (rear >= front) return rear - front + 1;
    return MAX - front + rear + 1;
}

void display() {
    if (empty()) {
        printf("Deque is empty\n");
        return;
    }
    int i = front;
    while (1) {
        printf("%d ", dq[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);
    display();              // 5 10 20 30
    pop_front();
    pop_back();
    display();              // 10 20
    printf("Front: %d\n", front_element());
    printf("Back: %d\n", back_element());
    printf("Size: %d\n", size());
    return 0;
}