
//A] Macro definitions and inclusion of header file

#define ARR_LENGTH  0XA
#include <stdio.h>
#include <string.h>


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

//Definition of the Virtual Heap
typedef struct {
   studtype stud;
   int link;
}nodetype;

typedef struct {
    nodetype VSpace[ARR_LENGTH];
    int Avail;         //holds the index of the first available node
}VirtualHeap;

//Definition of the cursor List
typedef int CursorList;

//C] Function Prototypes
/*--- C1] Virtual Heap Management Functions -----*/ 
void initVirtualHeap(VirtualHeap *H);   //Initialize the virtual heap by linking the nodes and assigning an appropriate value for Avail. 
int allocSpace(VirtualHeap *H);         //Removes the first available node and returns the index of that node to the calling function
void deallocSpace(VirtualHeap *H, int nodeNdx);  //Inserts a node (indexed by nodeNdx) at the first position of the available list.
 
/*--- C2] Utility Functions ---*/
void displayHeader();                
void displayStudent(studtype S);        //Displays info of a student record in 1 horizontal line
void displayList(CursorList A, VirtualHeap V);      //Displays the list. Calls displayStudent()

/*--- C3] List Operations ---*/
 //Task #1
void initList(CursorList *A);         //Initializes the list to be empty, not the virtual heap
void insertLast(CursorList *A, studtype S, VirtualHeap *H);    //Inserts an element at the end of the list if there is still space; otherwise
                                                        // Display "Memory Allocation Error. Cannot insert Element with ID ___". 
 //Task #2
void deleteElem(CursorList *A, char ID[], VirtualHeap *H);     //Deletes the element bearing the given ID if the element is found; otherwise
                                                        //    Display "Element with ID ___ is not found"

/*****************************************************************
 * Function Definitions                                          *
 *****************************************************************/
/*C1] ----- Virtual Heap Management Functions -----*/
void initVirtualHeap(VirtualHeap *H)
{
	H->Avail = 0;
   int i;
   for(i = 0; i < ARR_LENGTH - 1; i++){
      H->VSpace[i].link = i + 1;
   }

   H->VSpace[i].link = -1;   
}


int allocSpace(VirtualHeap *H)
{
   int index = H->Avail;
   if(index != -1){
      H->Avail = H->VSpace[index].link;
   }

   return index;
}

void deallocSpace(VirtualHeap *H, int nodeNdx)
{
   if(nodeNdx >= 0 && nodeNdx < ARR_LENGTH){
      H->VSpace[nodeNdx].link = H->Avail;
      H->Avail = nodeNdx;
   }
}


/*C2] ----- Utility Functions ------*/
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
            
void displayList(CursorList A, VirtualHeap H)
{
	int x;
	
	displayHeader();
	
	//Complete this function by traversing the list from the 1st element to the last element and
   CursorList trav;
   for(trav = A; trav != -1; trav = H.VSpace[trav].link){
      displayStudent(H.VSpace[trav].stud);
   }


	//printf("\n\nList has %d elements:",  );   //complete this line and uncomment
}  

/*C3] ----- List Operations ------*/

void initList(CursorList *A)
{
	*A = -1;
	
}

void insertLast(CursorList *A, studtype S, VirtualHeap *H) 
{
   if(H->Avail != -1){
      CursorList *trav, temp;
      for(trav = A; *trav != -1; trav = &H->VSpace[*trav].link){}
      temp = allocSpace(H);
      if(temp != -1){
         H->VSpace[temp].stud = S;
         H->VSpace[temp].link = *trav;
         *trav = temp;
      }
   } 
	 
}   

void deleteElem(CursorList *A, char ID[], VirtualHeap *H)
{
	 //Complete this function
    if(*A != -1){
      CursorList *trav, temp;
      for(trav = A; *trav != -1 && strcmp(H->VSpace[*trav].stud.ID, ID) != 0; trav = &H->VSpace[*trav].link){}
      if(*trav != -1){
         temp = *trav;
         *trav = H->VSpace[temp].link;
         deallocSpace(H,temp);
      }
    }
}    
	

