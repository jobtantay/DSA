#include <stdio.h>
#include "LinkedList.h"       //Uncomment ArrayList.h  or LinkedList.h
//#include "LinkedList.h"    //Only one .h file should be included at a time
int main()
{
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

    
  /*-----------------------------------------------------------------------------------
   Task 1: 
     a) Declare a list variable L and Initialize it to be empty by calling initList()
	  b) Populate the list with 10 elements by calling insertLast() 10 times. Use array data
     c) Display the List by calling displayList()
   -------------------------------------------------------------------------------------*/
   List L;
   initList(&L);
   insertLast(&L, data[0]);
   insertLast(&L, data[1]);
   insertLast(&L, data[2]);
   insertLast(&L, data[3]);
   insertLast(&L, data[4]);
   insertLast(&L, data[5]);
   insertLast(&L, data[6]);
   insertLast(&L, data[7]);
   insertLast(&L, data[8]);
   insertLast(&L, data[9]);
   
  printf("\n\nTask 1: Populating the list");
  displayList(L);
    
   
  //printf("\n\n"); system("Pause");   //Uncomment this if needed
  
  /*-----------------------------------------------------------------------------------
   Task 2: 
     a) Call deleteElem() passing the ID number STUD1009, then call displayList()
     b) Call deleteElem() passing the ID number STUD1001, then call displayList()
     c) Call deleteElem() passing the ID number STUD1013, then call displayList()
   -------------------------------------------------------------------------------------*/

   deleteElem(&L, "STUD1009");
   displayList(L);
   deleteElem(&L, "STUD1001");
   displayList(L);
   deleteElem(&L, "STUD1013");
   displayList(L);
  printf("\n\nTask 2: Deleting Elements in the list");
 

   return 0;

}

