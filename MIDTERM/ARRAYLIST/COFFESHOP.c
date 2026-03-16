#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
    int orderID;
    char drink[20];
    float price;
}Order;

typedef struct{
    Order orders[MAX];
    int count;
}OrderList;

void initList(OrderList *L){
    L->count = 0;
}

bool searchOrder(OrderList L, int id){

        int i;
        for(i = 0; i < L.count && L.orders[i].orderID != id; i++){}
        return(i < L.count)?true:false;
    
}

void addLast(OrderList *L, int ID, char drink[], float price){
    if(L->count < MAX){
        int i = L->count;
        strcpy(L->orders[i].drink, drink);
        L->orders[i].orderID = ID;
        L->orders[i].price = price;
        L->count++;
    }
}

void addFirst(OrderList *L, int ID, char drink[], float price){
    if(L->count < MAX){
        for(int x = L->count;0 < x; x--){
            L->orders[x] = L->orders[x - 1];
        }
        L->orders[0].orderID = ID;
        strcpy(L->orders[0].drink, drink);
        L->orders[0].price = price;
        L->count++;
    }
}

void displayOrderList(OrderList L){
    for(int i = 0; i < L.count; i++){
        printf("ID: %d\tDrink: %s\tPrice: %.2f\t\n",L.orders[i].orderID, L.orders[i].drink, L.orders[i].price);
    }
}

void deleteOrder(OrderList *L, int id){
    int i;
    
    for(i = 0; L->count > i && L->orders[i].orderID != id; i++){}

    if(L->count > i){
        for(;i < L->count - 1; i++){
        L->orders[i] = L->orders[i + 1];
    }
        L->count--;
    }

}
int main(){

    OrderList L;

    initList(&L);

    printf("\nAdding orders...\n");

    addLast(&L,101,"Latte",150.00);
    addLast(&L,102,"Mocha",160.00);
    addLast(&L,103,"Cappuccino",170.00);

    addFirst(&L,100,"Espresso",120.00);

    printf("\n--- CURRENT ORDER LIST ---\n");
    displayOrderList(L);

    printf("\nSearching for Order ID 102...\n");

    if(searchOrder(L,102)){
        printf("Order Found!\n");
    }else{
        printf("Order Not Found!\n");
    }

    printf("\nDeleting Order ID 102...\n");
    deleteOrder(&L,102);

    printf("\n--- UPDATED ORDER LIST ---\n");
    displayOrderList(L);

    printf("\nSearching for Order ID 102 again...\n");

    if(searchOrder(L,102)){
        printf("Order Found!\n");
    }else{
        printf("Order Not Found!\n");
    }

    return 0;
}