// =========================================================

//HW1P1 queue client-side file (main.cpp)
//Your name: Jer Cherng Law
//Complier: Mac OS X Terminal g++ v4.2.1
//File type: client file

//================================================================

#include "queue.h"

int main()
{
    // initializing variable
    queue my_queue;
    el_t what_to_display;
    
    // add first 3 values onto queue.
    my_queue.add("A");
    my_queue.add("B");
    my_queue.add("C");
    
    el_t input_el_t;
    try {
        while(true) {// we let the throw-when-overflow statement do excception handling
            my_queue.displayAll();
            my_queue.remove(what_to_display);
            cout << what_to_display << '\n';
            
            // the following appends characters 'A', 'B' and 'C' to the end of
            // recently removed item from the queue and then adds it back onto
            // the queue. what_to_display + "A" would result in a string and this
            // string is what's added.
            my_queue.add(what_to_display + "A");
            my_queue.add(what_to_display + "B");
            my_queue.add(what_to_display + "C");
        }
    }
    
    catch (queue::Overflow) { cout << "Overflow detected, cannot add.\n"; }
    catch (queue::Underflow) { cout << "Overflow detected, cannot add.\n"; }
    
    // display any additional error messages
    catch (const char* errorcode) { cout << errorcode << '\n'; }
    
    
    my_queue.displayAll();
    // display
    
    return 0;
}

