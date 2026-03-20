#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    char plate[20];
    char brand[20];
    int hours;
}Car;

typedef struct node{
    Car data;
    struct node *next;
}*List;

typedef struct{
    List front;
    List rear;
}ParkingQueue;


void initQueue(ParkingQueue *Q){
    Q->front = Q->rear = NULL;
}

bool isEmpty(ParkingQueue Q){
    return(Q.front == NULL)? true : false;
}

void enqueue(ParkingQueue *Q, char plate[], char brand[], int hours){
    List temp = (List) malloc (sizeof(struct node));
    if(temp != NULL){
        strcpy(temp->data.brand,brand);
        strcpy(temp->data.plate, plate);
        temp->data.hours = hours;
        temp->next = NULL;
        if(Q->front != NULL){
            Q->rear->next = temp;
        }else{
            Q->front = temp;
        }

        Q->rear = temp;
    }
}

void dequeue(ParkingQueue *Q){
    if(!isEmpty(*Q)){
        List temp;
        temp = Q->front;
        Q->front = temp->next;
        if(temp == Q->rear){
            Q->rear = NULL;
        }
        free(temp);
    }
}

void display(ParkingQueue Q){
    if(Q.front!=NULL){
        List trav = Q.front;
        for(;trav!=NULL;trav = trav->next){
            //print the data didnt put printf i got tired 
        }
        
    }
}

void removeLongParked(ParkingQueue *Q){
    if(Q->front != NULL){
        List *trav = Q->front;
        List temp;
        for(; *trav != NULL; trav = &(*trav)->next){
            if((*trav)->data.hours > 5){
                temp = *trav;
                *trav = temp->next;
                free(temp);
            }
        }
    }
}

int main(){

}