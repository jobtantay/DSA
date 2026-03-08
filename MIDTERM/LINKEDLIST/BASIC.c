#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct node{
    char elem;
    struct node *link;
}*List;

void initList(List * L){
    *L = NULL;
}

int main()
{
    List L;

}
