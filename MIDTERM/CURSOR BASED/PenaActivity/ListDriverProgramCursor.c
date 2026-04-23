#include <stdio.h>
#include "CursorList.h"    
int main()
{
 //Uncomment this when ArrayList.h or LinkedList.h is included in the program   
 
  studtype data[] = {  {"STUD1001", {"John", 'R', "Doe"}, "BSCS", 1},
           				  {"STUD1005", {"Jane", 'L', "Smith"}, "BSIT", 1},
           				  {"STUD1002", {"Mark", 'S', "Johnson"}, "BSIS", 1},
                       {"STUD1009", {"Joey", 'K', "Lee"}, "BSIS", 2},
            		     {"STUD1015", {"Michael", 'T', "Garcia"}, "BSIT", 2},
           				  {"STUD1006", {"Emlio", 'P', "Martinez"}, "BSIT", 3},
           				  {"STUD1011", {"David", 'A', "Rodriguez"}, "BSCS", 4},
            		     {"STUD1012", {"Olivia", 'B', "Hernandez"}, "BSCS", 3},
            			  {"STUD1008", {"James", 'C', "Kim"}, "BSIS", 3},
           			     {"STUD1010", {"Mia", 'D', "Nguyen"}, "BSCS", 1}
           	  			};
    int num = sizeof(data)/ sizeof(data[0]);
    
  /*-----------------------------------------------------------------------------------
   Task 1: 
     a) Declare a list variable L and Initialize it to be empty by calling initList()
     b) Declare a virtual heap variable V and initialize it to be empry by calling initVirtualHeap()
	 c) Populate the list with num # elements by calling insertLast() n times. Use array data
     d) Display the List by calling displayList()

     
   -------------------------------------------------------------------------------------*/

   CursorList L;
   VirtualHeap vh;
   initVirtualHeap(&vh);
   initList(&L);

   for(int i = 0; i < num; i++){
    insertLast(&L,data[i],&vh);
   }

   displayList(L,vh);
  
  printf("\n\nTask 1: Populating the list");
    
   
  //printf("\n\n"); system("Pause");   //Uncomment this if needed
  
  /*-----------------------------------------------------------------------------------
   Task 2: 
     a) Call deleteElem() passing the ID number STUD1009, then call displayList()
     b) Call deleteElem() passing the ID number STUD1001, then call displayList()
     c) Call deleteElem() passing the ID number STUD1013, then call displayList()
   -------------------------------------------------------------------------------------*/

   deleteElem(&L,"STUD1009",&vh);
   displayList(L,vh);
   deleteElem(&L,"STUD1001",&vh);
   displayList(L,vh);
   deleteElem(&L,"STUD1013",&vh);
   displayList(L,vh);


  printf("\n\nTask 2: Deleting Elements in the list");
 

   return 0;

}

