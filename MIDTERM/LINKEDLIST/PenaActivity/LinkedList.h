
//A] Macro definitions and inclusion of header file

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//B] Data Structure Definition
 
typedef struct {
    char FN[24], MI, LN[16];
}nametype;

typedef struct {
	 char ID[9];
    nametype name;
    char course[8];
    int yrlevel;
}studtype;

typedef struct node{
   studtype stud;
	struct node *link;  
}*List;
                  //Initializes the list to be empty
void insertLast(List *A, studtype S);    //Inserts an element at the end of the list;  
                                         //If malloc() is not successfull, display "Memory Allocation Error. Cannot insert Element with ID ___". 
                                                 
void displayHeader();
void displayStudent(studtype S);          //Displays info of a student record in 1 horizontal line
void displayList(List A);                 //Displays the list. Calls displayStudent()

void deleteElem(List *A, char ID[]);     //Deletes the element bearing the given ID if the element is found; otherwise
                                         // Display "Element with ID ___ is not found"

/*****************************************************************
 * Function Definitions                                          *
 *****************************************************************/

//----- Display Functions ------
void displayHeader()
{
	printf("\n\n");
	printf("%-10s", "Id Number");
   printf("%-13s", "FirstName");
   printf("%-3s", "MI");
   printf("%-13s", "LastName");
   printf("%-10s", "Program");
   printf("%-10s", "Year");		
}

void displayStudent(studtype S)
{
	printf("\n");
	printf("%-10s", S.ID);
   printf("%-13s", S.name.FN);
   printf("%-3c",  S.name.MI);
   printf("%-13s", S.name.LN);
   printf("%-10s", S.course);
   printf("%-10d", S.yrlevel);	
}  
            
void displayList(List A)
{
	displayHeader();
	
	//Complete this function by traversing the list from the 1st element to the last element, and calling displayStudent()
	int id = 0;
   List temp;
   for(temp = A; temp != NULL; temp = temp->link, id++){
      displayStudent(temp->stud);
   }
	printf("\n\nList has %d elements:",  id); 
}  

void initList(List *A)
{
	*A = NULL;
}

void insertLast(List *A, studtype S)
{
	 //Complete this function
    List *trav;
    List temp = (List) malloc (sizeof(struct node));
    if(temp != NULL){
      for(trav = A; *trav != NULL; trav = &(*trav)->link){}
      strcpy(temp->stud.ID, S.ID);
      strcpy(temp->stud.course, S.course);
      temp->stud.yrlevel = S.yrlevel;
      strcpy(temp->stud.name.FN, S.name.FN);
      strcpy(temp->stud.name.LN, S.name.LN);
      temp->stud.name.MI = S.name.MI;
      temp->link = *trav;
      *trav = temp;
    }else{
      printf("Memory Allocation Error. Cannot insert Element with ID %s", S.ID);
    }   
}   

void deleteElem(List *A, char ID[])
{
	 List *trav = A, temp;
      for(;*trav != NULL && strcmp((*trav)->stud.ID, ID) != 0; trav = &(*trav)->link){}

      if(*trav != NULL){
      temp = *trav;
      *trav = temp->link;
      free(temp);
    }else{
      printf("Element with ID %s is not found", ID);
    }
   
}    
	

