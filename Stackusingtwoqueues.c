#include <stdio.h>
#define SIZE 100

int q1[SIZE], q2[SIZE];
int f1 = 0, r1 = -1;
int f2 = 0, r2 = -1;


void enqueue(int q[], int *rear, int value) {
    q[++(*rear)] = value;
}


int dequeue(int q[], int *front) {
    return q[(*front)++];
}


void push(int value) {
   
    enqueue(q2, &r2, value);

    
    while (f1 <= r1) {
        enqueue(q2, &r2, dequeue(q1, &f1));
    }

   
    int temp;
    temp = f1; f1 = f2; f2 = temp;
    temp = r1; r1 = r2; r2 = temp;
}


void pop() {
    if (f1 > r1) {
        printf("Stack is empty\n");
    } else {
        printf("Popped element: %d\n", dequeue(q1, &f1));
    }
}

int main() {
    push(10);
    push(20);
    push(30);

    pop();
    pop();

    return 0;
}
