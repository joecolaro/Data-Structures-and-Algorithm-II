/*

INSTRUCTION
Look for **.
Update comments, complete exception handling and finish ClearIt to make this complete - Yoshii (CS311)
*/
// =========================================================

//HW1P1 stack
//Your name: Jer Cherng Law
//Complier: Mac OS X Terminal g++ v4.2.1
//File type: stack implementation file

//================================================================

#include "stack.h"

//** Constructor must initialize top to be -1 to begin with.
stack::stack()
{ 
  top = -1; // indicate an empty stack }
}
// ** Destructor does not have to do anything since this is a static array.
stack::~stack()
  {} // nothing to do }
  
// ** isEmpty checks top and returns true if empty, false otherwise.
//    In the comment, make sure you define "empty" in terms of top.
bool stack::isEmpty()
{ if (top == -1) return true; else return false; }
    
// ** isFull checks top and returns true if full, false otherwise.
// In the comment, make sure you define "full" in terms of top.
bool stack::isFull()
  { if (top == MAX-1) return true; else return false; }  

// ** push calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el after incrementing top.
void stack::push(el_t elem)
  { Overflow overflow;
    if (isFull()) throw overflow;
    else { top++; el[top] = elem; }}
  
// ** pop calls isEmpty and if true, throws an exception (Underflow)
//  Otherwise, removes an element from el and gives it back.
void stack::pop(el_t& elem)
  { Underflow underflow;
    if (isEmpty()) throw underflow;
    else { elem = el[top]; top--;}}

// ** topElem calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
void stack::topElem(el_t& elem)
  { Underflow underflow;
    if (isEmpty()) throw underflow;
    else { elem = el[top]; } }

//dislayAll calls isEmpty and if true, displays [ empty ].
//  Otherwise, diplays the elements vertically.
void stack::displayAll()
  {  if (isEmpty()) cout << "empty" << endl;
    else for (int i=top; i>=0; i--)
      { cout << el[i] << endl; }}

//** clearIt pops all elements from the stack to make it empty if it is not empty yet.
void stack::clearIt(){
    el_t x;
    for( int i = 0; i < MAX; i++) {
      pop(x);
    }
  }