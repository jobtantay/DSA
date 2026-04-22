#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Nested struct
typedef struct {
    int year;
    char course[50];
} AcademicInfo;

// Main data
typedef struct {
    int id;
    char name[50];
    AcademicInfo acad;
} Student;

// Node with pointer typedef
typedef struct node {
    Student data;
    struct node* next;
} *LIST;

void initList(LIST *L){
    *L = NULL;
}

LIST createNode(Student s){
    LIST temp = (LIST) malloc (sizeof(struct node));
    if(temp != NULL){
        temp->data.id = s.id;
        strcpy(temp->data.name, s.name);
        strcpy(temp->data.acad.course, s.acad.course);
        temp->data.acad.year = s.acad.year;
        temp->next = NULL;
    }
    return temp;
}

void insertFirst(LIST *L, Student s){
    LIST temp = createNode(s);
    if(temp != NULL){
    temp->next = *L;
    *L = temp;
    }
}

void displayList(LIST L){
    for(LIST ptr = L; ptr != NULL; ptr = ptr->next){
        printf("ID: %d  Name: %s  Year:%d  Course:%s\n", ptr->data.id, ptr->data.name, ptr->data.acad.year, ptr->data.acad.course);
    }
}

void insertLast(LIST *L, Student s){
    LIST *trav, temp = createNode(s);

    for(trav = L; *trav != NULL; trav = &(*trav)->next){}
    if(temp!=NULL){
        temp->next = *trav;
        *trav = temp;
    }
    
}

void deleteFirst(LIST *L){
    LIST temp = *L;
    if(temp != NULL){
        *L = temp->next;
        free(temp);
    }
}

void insertAtPos(LIST *L, Student s, int pos){
    int count = 1;
    LIST *trav = L;
    for(; *trav != NULL && count != pos; trav = &(*trav)->next, count++){}
    if(pos == count){
        LIST temp = createNode(s);
        if(temp != NULL){
            temp->next = *trav;
            *trav = temp;
        }
    }
}

void deleteLast(LIST *L){
    LIST *trav, temp;
    
  
    for(trav = L; (*trav)->next != NULL; trav = &(*trav)->next){}

        
        temp = *trav;
        *trav = NULL;
        free(temp);
    
}

void deleteAtPos(LIST *L, int pos){
    LIST *trav, temp;
    int count = 1;
    for(trav = L; *trav != NULL && pos > count; trav = &(*trav)->next, count++){}

    if(*trav != NULL && count == pos){
        LIST temp = *trav;
        *trav = (*trav)->next;
        free(temp);
    }
}

int main() {
    LIST L;
    initList(&L);

    Student s1 = {1, "John", {1, "CS"}};
    Student s2 = {2, "Jane", {2, "IT"}};
    Student s3 = {3, "Mark", {3, "IS"}};
    Student s4 = {4, "Luke", {1, "CS"}};

    insertFirst(&L, s1);
    insertLast(&L, s2);
    insertAtPos(&L, s3, 2);
    insertLast(&L, s4);

    printf("List after insertions:\n");
    displayList(L);

    deleteFirst(&L);
    deleteLast(&L);
    deleteAtPos(&L, 1);

    printf("\nList after deletions:\n");
    displayList(L);

    return 0;
}