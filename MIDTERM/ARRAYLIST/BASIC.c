#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct{
    char elem[MAX];
    int count;
}List;

void display(List L){
    for(int i = 0; i < L.count; i++){
        printf("%c ", L.elem[i]);
    }
    printf("\n");
}
void initList(List *L){
    L->count = 0;
}
void insertFirst(List *L){
    int i;
    char x;

    if (L->count == MAX){
        printf("THE ARRAY IS FULL");
        return;
    }


    printf("INSERT FIRST ELEMENT: ");
    scanf(" %c", &x);

    for(i = L->count; i > 0; i--){
        L->elem[i] = L->elem[i - 1];
    }
    L->elem[0] = x;
    L->count++;

    printf("Value %c inserted at first.", x);

    return;
}
void insertLast(List *L){
    int i;
    char x;

    printf("Enter Value: ");
    scanf(" %c", &x);

    if(L->count < MAX){
        L->elem[L->count] = x;
        L->count++;
    }else printf("ARRAY IS FULL\n");
}
void insertAtPos(List *L){
    int pos, i;
    char x;

    printf("ENTER POSITION: ");
    scanf("%d", &pos);
    printf("ENTER VALUE: ");
    scanf(" %c", &x);

    if(L->count < MAX){
        for(i = L->count; i > pos; i--){
            L->elem[i] = L->elem[i - 1];
        }
        L->elem[pos] = x;
        L->count++;
    }else{
        printf("ARRAY IS MAX");
    }
    
}
void insertSorted(List *L){
    int i, j;
    char x;

    printf("ENTER SORTED VALUE: ");
    scanf(" %c", &x);

    if(L->count < MAX){
        for(i = 0; i < L->count && L->elem[i] < x; i++){};
        for(j = L->count; j > i; j--){
            L->elem[j] = L->elem[j - 1];
        }
        L->elem[i] = x;
        L->count++;
    }
}
void deleteFirst(List *L){
    int i;
    if(L->count > 0){
        for(i = 0; i < L->count - 1; i++){
            L->elem[i] = L->elem[i + 1];
        }
        L->count--;
    }
}

int main(){
    List L;
    initList(&L);
    int choice;

    printf("\n===== ARRAY LIST MENU =====\n");
    printf("1. Insert First\n2. Insert Last\n3. Insert At Position\n4. Insert Sorted\n5. Delete First\n6. Delete Last\n7. Delete At Position\n8. Delete Element\n9. Display\n0. Exit\n");


    do{

    printf("ENTER CHOICE: ");
    scanf("%d", &choice);

        switch (choice){
            case 1:
            insertFirst(&L);
            printf("\n");
            break;

            case 2:
            insertLast(&L);
            printf("\n");
            break;

            case 3:
            insertAtPos(&L);
            printf("\n");
            break;

            case 4:
            insertSorted(&L);
            printf("\n");
            break;

            case 5:
            deleteFirst(&L);
            printf("\n");
            break;

            case 6:
            
            case 9:
            display(L);
            break;
        }
    }while(choice != 0);


}