


#include <iostream>
#include <cctype>
#include <fstream>
#include "StackOperand.h"
using namespace std;
// Ivy Seo

//stack for Operands

/*This program reads infix expressions from a file, one expression per line. 
Operands are consisted with single digits. 
It simplifies input and allows us to concentrate on the evaluation algorithm and its interaction with the stacks. 
The program uses two stacks, one of integers for operands and one of characters for operators. 
Therefore, #include two stack classes that differ only in the types of object in their stacks. 
When the program reads the name of a file, then from the file reads syntactically correct general 
infix expressions involving single-digit integers and binary arithmetic operators: +, -, *, and /. 
And it prints to the terminal each expression in the file and its value.*/
 
void stack::push(Item entry) //Append a value on top of the stack
{
Node *temp;

temp = new Node;
temp -> data = entry;
temp -> next =top;
top = temp;
++used;
}
 
stack::Item stack::pop() //Remove the value on top of the stack
{
Node *temp;
Item popped;

popped = top -> data;
temp = top;
top = top -> next;
delete temp;
--used;
return popped;
}

stack::~stack() //Destructor
{
Node* temp;
 
while ( top != NULL )
{
temp = top;
top = top -> next;
delete temp;
}
}
 
//stack_b for Operators
 
void stack_b::push(Item entry) //Append a value on top of the stack
{
Node *temp;

temp = new Node;
temp -> data = entry;
temp -> next =top;
top = temp;
++used;
}
 
stack_b::Item stack_b::pop() //Remove the value on top of the stack
{
Node *temp;
Item popped;

popped = top -> data;
temp = top;
top = top -> next;
delete temp;

--used;
return popped;

}

stack_b::~stack_b() //Destructor
{
Node* temp;
 
while ( top != NULL )
{
temp = top;
top = top -> next;
delete temp;
}
}

stack_b::Item stack_b::peek() //see what's on top of the stack
{
Item top_peek;
top_peek = top -> data;
return top_peek;
}

#include <iostream>
#include <cctype>
#include <fstream>
#include "project7.h"
using namespace std;
 
int apply(char, int, int);
int pre(char);
 
int main()
{
   stack a;
stack_b b;
   char x;
   int num, res;
 
   string file_name;
   fstream n;

   cout << "Please enter the name of the file below," << endl;
   cin >> file_name;
   n.open( file_name.c_str() );
 
   while( !n.eof() )
   {
       n.get(x);  
       while( x != '\n' && !n.eof() )
       {
if( isdigit(x) )    
{
num = x -'0';  
cout<<num<<" ";
a.push(num);
}

else if( (x == '+' || x == '-' || x == '*' || x == '/') && b.empty() == true )
{
cout<<x<<" ";
b.push(x);
}

else if( (x == '+' || x == '-' || x == '*' || x == '/') && b.empty() != true && pre(x) < pre(b.peek()))
           {
cout<<x<<" ";
b.push(x);
}

else if( x =='(' )
{
cout<<x<<" ";
b.push(x);
}

else if( x == ')')
{
char operators;
int y, oper_A, oper_B;

cout<<x<<" ";

oper_B = a.pop();
oper_A = a.pop();
operators = b.pop();

y = apply(operators, oper_
A, oper_B);
a.push(y);

}
else    
{
char operators;
int y, oper_A, oper_B;

oper_B = a.pop();
oper_A = a.pop();
operators = b.pop();

y = apply(operators, oper_A, oper_B);
a.push(y);
}

n.get(x);  
 
           if( x == '\n' || n.eof() )  
{
while( b.empty() != true)
{
char operators;
int y, oper_A, oper_B;

oper_B = a.pop();
oper_A = a.pop();
operators = b.pop();

y = apply(operators, oper_A, oper_B);
a.push(y);
}

           }
           else
{
n.get(x);
}
res=a.pop();
               cout<<endl;
cout<<res<<endl;
       }
   }
n.close();
}
 
int apply (char optr, int opnd1, int opnd2)
{
   if(optr == '+')
       return opnd1 + opnd2;
 
   else if(optr == '-')
       return opnd1 - opnd2;
 
   else if(optr == '*')
       return opnd1 * opnd2;
 
   else if(optr =='/')
       return opnd1 / opnd2;
}
 
int pre (char optr)
{
if ( optr == '/' || optr == '*' )
{
   return 0;
}
    else
{
    return 1;
}
}
