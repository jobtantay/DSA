#include <stdio.h>
#include <stdbool.h>

#define MAX 5

typedef struct{
    int elem[MAX];
    int front;
    int rear;
}Queue;

void initQueue(Queue *Q){
    Q->front = 0;
    Q->rear = MAX - 1;
}

bool isEmpty(Queue Q){
    return((Q.rear+1) % MAX == Q.front)?true:false;
}

bool isFull(Queue Q){
    return((Q.rear+2) % MAX == Q.front)?true:false;
}

int front(Queue Q){
    return(!isEmpty(Q))?Q.elem[Q.front]:'\0';
}

void enqueue(Queue *Q, int x){
    if(!isFull(*Q)){
        Q->rear = (Q->rear+1)%MAX;
        Q->elem[Q->rear] = x; 
    }
}

void deque(Queue *Q){
    if(!isEmpty(*Q)){
        Q->front = (Q->front + 1) % MAX;
    }
}

void display(Queue Q){
    int i;
    if(!isEmpty(Q)){
        for(i = Q.front; i != (Q.rear+1)%MAX; i = (i + 1)%MAX){
        printf("%d ", Q.elem[i]);
        }
    }
}

int main(){

    Queue Q;

    initQueue(&Q);

    enqueue(&Q,10);
    enqueue(&Q,20);
    enqueue(&Q,30);

    printf("Front: %d\n", front(Q));

    dequeue(&Q);

    printf("After dequeue:\n");
    display(Q);

    enqueue(&Q,40);
    enqueue(&Q,50);
    enqueue(&Q,60); // test overflow

    printf("\nFinal Queue:\n");
    display(Q);

    return 0;
}