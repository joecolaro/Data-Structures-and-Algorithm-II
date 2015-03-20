INSTRUCTION
Look for **.

// =========================================================

//HW1P1 stack client
//Your name: **
//Complier:  **
//File type: **

//================================================================

#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

int main()
{
  stack postfixstack;  // integer stack
  string expression;
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  
  while (expression[i] != '\0')
    {
      try
	{
	  item = expression[i]; //1.  read an item.
	  if //2.  if it is an operand (number), 
	  //push it (you might get Overflow exception)
	  //3.  else if it is an operator,
	  //    pop the two operands (you might get Underflow exception), and
	  //	 apply the operator to the two operands, and
	  //    push the result.
	  
         else if ( (item == '+') || (item == '-') || (item == '*'))
	   {
	     postfixstack.pop(box1);
	     postfixstack.pop(box2);
             // a whole bunch of cases
             if (item == '-') result = box2-box1;
             // also do the + and * cases 
	     // push the result
	   }
	 else throw "invalid item";
	} // this closes try
      
      // Catch exceptions and report problems and quit the program now. 
      catch (stack::Overflow)
	{** }
      catch (stack::Underflow)
	{** }
      catch (char const* errorcode) // for invalid item
	{** }
      // go back to the loop
      **
   }// end of while
  
  //  After the loop successfully completes: 
  //  The result will be at the top of the stack. Pop it and show it.
  //  If anything is left on the stack, an incomplete expression was found
  // inform the user.
  **
    
    
}
