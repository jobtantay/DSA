#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct{
    char plate[10];
    char brand[20];
    int hours;
}Car;

typedef struct node{
    struct node *next;
    Car data;
}*ParkingList;

void initParkingList(ParkingList* L){
    *L = NULL;
}

void addFirst(ParkingList* L, char plate[], char brand[], int hours){
    ParkingList temp = (ParkingList) malloc (sizeof(struct node));
    if(temp != NULL){
        strcpy(temp->data.plate, plate);
        strcpy(temp->data.brand, brand);
        temp->data.hours = hours;

        temp->next = *L;
        *L = temp;
    }
}

void addLast(ParkingList* L, char plate[], char brand[], int hours){
    ParkingList *trav, temp;
    temp = (ParkingList) malloc (sizeof(struct node));
    if(temp != NULL){
        for(trav = L; *trav != NULL; trav = &(*trav)->next){}
        strcpy(temp->data.brand, brand);
        temp->data.hours = hours;
        strcpy(temp->data.plate, plate);
        temp->next = NULL;
        *trav = temp;
    }
}

void removeCar(ParkingList *L, char plate[]){
    if(L != NULL){
        ParkingList *trav, temp;
        for(trav = L; *trav != NULL && strcmp((*trav)->data.plate, plate) != 0; trav = &(*trav)->next){}
        if(*trav != NULL){
            temp = *trav;
            *trav = temp->next;
            free(temp);
        }
    }
}

void display(ParkingList L){
    ParkingList temp;

    for(temp = L; temp != NULL; temp = temp->next){
        printf("Plate: %s | Brand: %s | Hours: %d\n",
               temp->data.plate,
               temp->data.brand,
               temp->data.hours);
    }
}

int searchCar(ParkingList L, char plate[]){
    ParkingList trav;
    for(trav = L; trav != NULL && strcmp(trav->data.plate, plate) != 0; trav = trav->next){}
    return(trav != NULL)?1:0;
}

int main(){

    ParkingList lot = NULL;

    printf("\nCars entering the parking lot...\n");

    addFirst(&lot,"ABC123","Toyota",3);
    addLast(&lot,"XYZ456","Honda",2);
    addLast(&lot,"DEF789","Ford",5);

    printf("\n--- CURRENT PARKED CARS ---\n");
    display(lot);

    printf("\nSearching for plate XYZ456...\n");

    if(searchCar(lot,"XYZ456")){
        printf("Car Found!\n");
    }else{
        printf("Car Not Found!\n");
    }

    printf("\nRemoving car ABC123...\n");
    removeCar(&lot,"ABC123");

    printf("\n--- UPDATED PARKING LIST ---\n");
    display(lot);

    return 0;
}