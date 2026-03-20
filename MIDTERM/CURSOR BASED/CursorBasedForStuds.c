/********************************************************************
 * Programming Practice on Cursor-based Implementation of ADT List. *
 * CIS 2101 Group 3                                                 *
 *                                                                  *
 ********************************************************************/
#include <stdio.h>
#define SIZE 6     //Size of the array of the Virtual Heap

//Data Structure Definition
typedef struct {
	char data;
	int link;
}nodetype;
typedef struct {
   nodetype Nodes[SIZE];
   int Avail;   //holds the first node in the list of available nodes
}VirtualHeap;   //Definition of the Virtual Heap

typedef int CBList;  //Definition of the List 

typedef enum {True, False} Boolean;
 

//Function Prototypes
//A. Virtual Heap Management Routines
void initVirtualHeap(VirtualHeap *VH);  //Initializes the virtual heap
int allocSpace(VirtualHeap *VH);        //Equivalent to malloc() in linked list
void deallocSpace(VirtualHeap *VH, int ndx); //Equivalent to free() in linked List
void displayVHeap(VirtualHeap VH);     //For illustration purposes ONLY


//B. ADT List Operations
void initList(CBList *L);
void displayList(CBList L, VirtualHeap VH);
void insertFirst(CBList *L, char elem, VirtualHeap *VH);
void deleteElem(CBList *L, char elem, VirtualHeap *VH);
void insertLast(CBList *L, char elem, VirtualHeap *VH);
Boolean isMember(CBList L, char elem, VirtualHeap VH);

void main()
{
	VirtualHeap V;
	CBList L;
	 
    //Task 1:  Calls initVirtualHeap(), initlist() and displayList()  	
	printf("\n\nTask 1: Initializes Virtual Heap and List. Displays the List");
	printf("\n============================================================");
	 
	
   
    //Task 2: Calls insertFirst() 5x, and displayList()
	printf("\n\nTask 2: Insert elements: H,E,L,L,O and displays the list");
	printf("\n========================================================");
 
 
 
     //Task 3:  Call deleteElem() and displayList()	
 	printf("\n\nTask 3: Delete element 'E'  and displays the list");
 	printf("\n=================================================");
   
   
 	
     //Task 4: Populate a new list M. Call insertLast() 3x, and displayList()
 	printf("\n\nTask 4: Inserts into a new list M, elements: U,S,C and displays the list M");
 	printf("\n=====================================================");
   
	
	
    //Task 5:  Calls isMember() 2x 	
 	printf("\n\nTask 5: Check membership for an existing and non-existing element");
 	printf("\n===================================================================");
    char nonElem = 'U';   //to be removed
    char elem = 'H';      //to be removed
   
}
	
/**********************************************
 * Virtual Heap Management Routines           *
 **********************************************/
// Initializes the virtual heap by linking the nodes and 
// letting variable Avail hold the index of the 1st available node
void initVirtualHeap(VirtualHeap *VH)   
{
   VH->Avail = 0;
   int i;
    for(i = 0; i < SIZE - 1; i++){
        VH->Nodes[i].link = i + 1;
    }
    VH->Nodes[i].link = -1;
}

//Equivalent to malloc() in linked list
//Removes the 1st available node if it exists; -1 if no available node
int allocSpace(VirtualHeap *VH)
{
    int idx = VH->Avail;
    if(idx != -1){
        VH->Avail = VH->Nodes[idx].link;//goes to the link of the current avail
    }
    return idx;
}

//Equivalent to free() in linked List
//Inserts the nodes at the 1st position of the available nodes
void deallocSpace(VirtualHeap *VH, int ndx)
{
    if(ndx >= 0 && ndx < SIZE){
        VH->Nodes[ndx].link = VH->Avail;
        VH->Avail}
}

void displayVHeap(VirtualHeap VH)
{
	int x;
	
	printf("\n\nThe Virtual Heap :: Avail = %d", VH.Avail);
	printf("\n%10s","Index");
	printf("%10s","Elements");
    printf("%10s","Link");
	for(x = 0; x < SIZE; x++){
		printf("\n%10d", x);
		printf("%10c", VH.Nodes[x].data);
    	printf("%10d", VH.Nodes[x].link);
	}	
}

/**********************************************
 * ADT List Operations                        *
 **********************************************/
//Initializes the given List to be empty; i.e 
//Sentinel Value of -1 is used to indicate the list is empty
//  since -1 is not a valid array index.
void initList(CBList *L)
{

}

//Display the elements of the list
void displayList(CBList L, VirtualHeap VH)
{
	
}

//Inserts an element at the first position of the list
void insertFirst(CBList *L, char elem, VirtualHeap *VH)
{

}

//Deletes the given element from the list
void deleteElem(CBList *L, char elem, VirtualHeap *VH)
{
	
}

//Inserts an element at the last position of the given list
void insertLast(CBList *L, char elem, VirtualHeap *VH)
{
	
}

//Returns True if the given element is in the list; otherwise returns False
Boolean isMember(CBList L, char elem, VirtualHeap VH)
{
	
}
