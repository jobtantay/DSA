#include <stdio.h>
#include "ArrayList.h"       //Uncomment ArrayList.h  or LinkedList.h
//#include "LinkedList.h"    //Only one .h file should be included at a time
int main()
{
 //Uncomment this when ArrayList.h or LinkedList.h is included in the program   
 /*
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
   */
    
  /*-----------------------------------------------------------------------------------
   Task 1: 
     a) Declare a list variable L and Initialize it to be empty by calling initList()
	  b) Populate the list with 10 elements by calling insertLast() 10 times. Use array data
     c) Display the List by calling displayList()
   -------------------------------------------------------------------------------------*/
  
  printf("\n\nTask 1: Populating the list");
    
   
  //printf("\n\n"); system("Pause");   //Uncomment this if needed
  
  /*-----------------------------------------------------------------------------------
   Task 2: 
     a) Call deleteElem() passing the ID number STUD1009, then call displayList()
     b) Call deleteElem() passing the ID number STUD1001, then call displayList()
     c) Call deleteElem() passing the ID number STUD1013, then call displayList()
   -------------------------------------------------------------------------------------*/
  printf("\n\nTask 2: Deleting Elements in the list");
 

   return 0;

}

