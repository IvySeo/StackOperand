
 
#include <iostream>
using namespace std;

class stack
{
 public:
   typedef int Item; 
 
//Constructor
   stack( ) { top = NULL; used = 0; } 

//Destructor
~stack( );
   //Modification Members
   void push(Item entry); // to append a value on to the top of stack

   Item pop(); //to remove the top value on the stack

 
   //Constant Member Functions
   bool empty() {return top == NULL;} //returns whether stack has value or not.
   int size() {return used;} //returns how many values the stack has
 
 private:
//Data Members
   struct Node // Node struct
     {
       Item data;
       Node *next;
     };
  
   Node *top; //A node points to the top of stack
   int used; //an integer to count the total values inside the stack
};
 
 
class stack_b
{
 public:
   typedef char Item; // The data type that can go inside the stack.
 
   //Constructor
   stack_b
  ( ) { top = NULL; used = 0; } // constructor to initialize stack as empty.
//Destructor
~stack_b( );
   //Modification Members
   void push(Item entry); // to append a value on to the top of stack

   Item pop(); //to remove the top value on the stack

Item peek(); //see what's on top of the stack
 
   //Constant Member Functions
   bool empty() {return top == NULL;} //returns whether the stack has values availbale or not.
   int size() {return used;} //returns how many values inside the stack.
 
 private:
//Data Members
   struct Node //Creats a Node struct
     {
       Item data;
       Node *next;
     };
  
   Node *top; //A node points to the top of stack
   int used; //an integer to count the total values inside the stack
};