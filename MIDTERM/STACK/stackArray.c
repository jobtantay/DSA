
#include <stdio.h>
#include <stdbool.h>

#define MAX 5
typedef struct{
    char elem[MAX];
    int top;
}top;

void initStack(top* s){
    s->top = -1;
}

void push(top* s, char x){
    if(s->top != MAX - 1){
        s->top++;
        s->elem[s->top] = x;
    }
}

void pop(top *s){
    if(s->top != -1){
        s->top--;
    }
}


bool isEmpty(top s){
    return (s.top == - 1)? true:false;
}

char isPeak(top s){
    return(s.top!= -1 )?s.elem[s.top] : '\0';  
}

int main(){
    top s;
}