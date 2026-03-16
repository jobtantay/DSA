#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node{
    char elem;
    struct node *link;
}*top;

void initStack(top *s){
    *s = NULL;
}

void push(top *s, char x){
    top temp = (top) malloc (sizeof(struct node));
    if(temp != NULL){
        temp->elem = x;
        temp->link = *s;
        *s = temp;
    }
}

void pop(top *s){
    if(*s == NULL){
        return;
    }
    top temp = *s;
    *s = temp->link;
    free(temp);
}

void peek(top s){
    if(s!=NULL){
        printf("%c", s->elem);
    }else{
        printf("ITS EMPTY");
    }
}

bool isEmpty(top s){
    return(s==NULL)? true:false;
}

void display(top s){
    top temp = s;
    for(;temp != NULL; temp = temp->link){
        printf(" %c", temp->elem);
    }
}

int main()
{
    printf("\n");
    top s;
    initStack(&s);

    push(&s,'A');
    push(&s,'B');
    push(&s,'C');

    pop(&s);
    peek(s);

    printf("\nStack:");
    display(s);
    printf("\n");
}