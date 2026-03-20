#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    char elem;
    struct node *next;
}*Stack;

void initStack(Stack *top){
    *top = NULL;
}

void push(Stack *top, char elem){
    Stack temp = (Stack) malloc (sizeof(struct node));
    if(temp != NULL){
        temp->elem = elem;
        temp->next = *top;
        *top = temp;
    }

}

void pop(Stack *top){
    if(*top == NULL){
        return;
    }else{
        Stack temp = *top;
        *top = temp->next;
        free(temp);
    }
}

bool isEmpty(Stack top){
    return(top == NULL)?true : false;
}

char peak(Stack top){
    return(top != NULL)? top->elem : '\0';
}

void display(Stack top){
    for(Stack temp = top; temp != NULL; temp = temp->next){
        printf("%c\n",temp->elem);
    }
}

int main(){
    Stack top;
}