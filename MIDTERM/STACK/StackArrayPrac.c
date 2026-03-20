#include <stdio.h>
#include <stdbool.h>

#define MAX 5

typedef struct{
    char elem[MAX];
    int top;
}Stack;

void initStack(Stack *S){
    S->top = -1;
}

void push(Stack *S, char x){
    if(S->top != MAX - 1){ //check if full
        S->top++;
        S->elem[S->top] = x;
    }
}

void pop(Stack *S){
    if(S->top > -1){
        S->top--;
    }
}

char peek(Stack S){
    return S.elem[S.top];
}

bool isFull(Stack S){
    return(S.top == MAX - 1)?true : false;
}

void display(Stack S){
    printf("top to bottom");
    for(int i = 0; i <= S.top; i++){
        printf(" %c", S.elem[i]);
    }

    printf("\nbuttom to top\n");
    for(int i = S.top; i >= 0; i--){
        printf(" %c", S.elem[i]);
    }
}

int main()
{
    Stack s;
    initStack(&s);

    push(&s,'A');
    push(&s,'B');
    push(&s,'C');

    printf("Top: %c\n", peek(s));

    pop(&s);

    printf("After pop:\n");
    display(s);

    return 0;
}