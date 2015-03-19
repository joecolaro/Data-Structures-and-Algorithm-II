// =========================================================

//HW1P1 queue.cpp
//Your name: Jer Cherng Law
//Complier: Mac OS X Terminal g++ v4.2.1
//File type: queue implementation file

//================================================================

#include "queue.h"
// constructor
queue::queue()
{
    count = 0;
    front = 0;
    rear = -1;
}

//destructor 
queue::~queue(){}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty() {
    if( count == 0 ) return true;
    else return false;
}

// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull(){
    // rear can never be -1 after initialization so we use that as
    // a check in order not to isolate the instantiation case as "full"
    if((front - 1 == rear) && (rear != -1)) return true;
    else return false;
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// HOW TO CALL: provide the element to be added
void queue::add(el_t item){
    if(isFull()) throw overflow;
    else {
        count++;
        // move the rear pointer first before adding onto queue
        rear++;
        // when rear is all the way in the back and stack is
        // not full, put it in front again.
        if(rear >= MAX_SIZE) rear = rear % MAX_SIZE;
        el[rear] = item;
    }
}

// PURPOSE: if empty, calls an emergency exit routine
// if not empty, removes the front element to give it back 
// HOW TO CALL: provide a holder for the element removed (pass by ref)
void queue::remove(el_t& item){
    if(isEmpty()) throw underflow;
    else {
        count--; // decrease the count of items when removing an item
        item = el[front];
        front++; // move the front pointer
        // if front is all the way in the back put it in front again.
        if(front >= MAX_SIZE) front = front % MAX_SIZE;
    }
}

// PURPOSE: if empty, throws an exception Underflow
   // if not empty, give back the front element (but does not remove it)
   // TO CALL: provide a holder for the element (pass by ref)
void queue::frontElem(el_t& item){
    if(isEmpty()) throw underflow;
    else item = el[front];
}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize(){
    return count % MAX_SIZE; // count can go above MAX_SIZE, use mod to wrap around
}

// PURPOSE: display everything in the queue from front to rear
//  enclosed in []
// if empty, displays [ empty ]
void queue::displayAll(){
    // wrap around implementation
    int i = front; // iterator, allows us to wrap around
    int j = 0;  // this to keep count of count

    cout << "Count: " << count << " Front: " << front << " Rear: " << rear << '\n' << "[ ";
    
    // we want to print 0-24 just like in array so j < count is term case
    while( j < count ) {
        cout << el[i] << ' ';
        i++; // 7 9 10 mod 0 1 2 3 4 (rear = 5) 5 exit
        j++;
        if( i >= MAX_SIZE ) i = i % MAX_SIZE; // this makes our code wrap around the queue.
    }
    cout << "]\n";
}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear
void queue::goToBack(){
    if (isEmpty()) throw underflow;
    // move but don't output anything
    else {
        el_t x;     // placeholder for item to be moved to back
        remove(x); // removes from front
        add(x);    // adds to back
    }
}
