// QUEUE DOUBLE ENDED

#include<stdio.h>
#include<stdlib.h>

struct deque {
    int size;
    int f;
    int r;
    int* arr;
};

int isEmpty(struct deque *dq) {
    if(dq->f == -1 && dq->r == -1) {
        return 1;
    }
    return 0;
}

int isFull(struct deque *dq) {
    if((dq->f == 0 && dq->r == dq->size - 1) || (dq->f == dq->r + 1)) {
        return 1;
    }
    return 0;
}

void enqueueFront(struct deque *dq, int val) {
    if(isFull(dq)) {
        printf("This Deque is full\n");
    } else {
        if(dq->f == -1) { // If deque is initially empty
            dq->f = dq->r = 0;
        } else if(dq->f == 0) {
            dq->f = dq->size - 1;
        } else {
            dq->f--;
        }
        dq->arr[dq->f] = val;
        printf("Enqueued %d at front\n", val);
    }
}

void enqueueRear(struct deque *dq, int val) {
    if(isFull(dq)) {
        printf("This Deque is full\n");
    } else {
        if(dq->r == -1) { // If deque is initially empty
            dq->f = dq->r = 0;
        } else if(dq->r == dq->size - 1) {
            dq->r = 0;
        } else {
            dq->r++;
        }
        dq->arr[dq->r] = val;
        printf("Enqueued %d at rear\n", val);
    }
}

int dequeueFront(struct deque *dq) {
    int a = -1;
    if(isEmpty(dq)) {
        printf("This Deque is empty\n");
    } else {
        a = dq->arr[dq->f];
        if(dq->f == dq->r) { // Queue has only one element
            dq->f = dq->r = -1;
        } else if(dq->f == dq->size - 1) {
            dq->f = 0;
        } else {
            dq->f++;
        }
    }
    return a;
}

int dequeueRear(struct deque *dq) {
    int a = -1;
    if(isEmpty(dq)) {
        printf("This Deque is empty\n");
    } else {
        a = dq->arr[dq->r];
        if(dq->r == dq->f) { // Queue has only one element
            dq->r = dq->f = -1;
        } else if(dq->r == 0) {
            dq->r = dq->size - 1;
        } else {
            dq->r--;
        }
    }
    return a;
}

int main() {
    struct deque dq;
    dq.size = 5;
    dq.f = dq.r = -1; // Initialize front and rear
    dq.arr = (int*) malloc(dq.size * sizeof(int));

    // Test the DEQueue operations
    enqueueRear(&dq, 10);
    enqueueRear(&dq, 20);
    enqueueFront(&dq, 5);
    enqueueFront(&dq, 1);
    
    printf("Dequeuing from front: %d\n", dequeueFront(&dq));
    printf("Dequeuing from rear: %d\n", dequeueRear(&dq));

    enqueueRear(&dq, 30);
    enqueueFront(&dq, 0);

    if(isEmpty(&dq)) {
        printf("Deque is empty\n");
    }
    if(isFull(&dq)) {
        printf("Deque is full\n");
    }

    return 0;
}
