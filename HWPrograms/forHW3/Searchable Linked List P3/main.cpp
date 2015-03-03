/* ====================================================
 
 HW3P3 slist
 Your name: Jer Cherng Law
 Complier:  Xcode g++ 4.2.1
 File type: Test file for copy constructor and overloading operator=
 
 //===================================================== */

#include "slist.h"

// Main will
int main() {
    
    // Create a 5 element list with  1,2,3,4,5 (L1)
    
    slist L1;
    L1.addRear(1);
    L1.addRear(2);
    L1.addRear(3);
    L1.addRear(4);
    L1.addRear(5);
    cout << "Displaying everything on list L1: ";
    L1.displayAll();
    
    // Pass the list to a client function called CopyTest to test your copy constructor.
    L1.copyTest();
    
    // Display L1
    cout << "Displaying everything on list L1: ";
    L1.displayAll();
    
    // Do L1 = L1;
    L1 = L1;
    // Display L1    	(this should still be 1 2 3 4 5)
    cout << "Displaying everything on list L1: ";
    L1.displayAll();
    
    // Create a 4 element list L2 with 7,8,9,10.
    slist L2;
    L2.addRear(7);
    L2.addRear(8);
    L2.addRear(9);
    L2.addRear(10);
    // Display L2
    cout << "Displaying everything on list L2: ";
    L2.displayAll();
    
    // Do L2 = L1;  	(L2 becomes 5 elements 1,2,3,4,5)
    L2 = L1;
    // Display L2.
    cout << "Displaying everything on list L2: ";
    L2.displayAll();
    
    // Remove a rear node from L1. (This should not affect L2).
    el_t deleteOne;
    L1.deleteRear(deleteOne);
    // Display L1.   	(L1 is 1,2,3,4)
    cout << "Displaying everything on list L1: ";
    L1.displayAll();
    // Display L1 again. (4 elements)
    cout << "Displaying everything on list L1: ";
    L1.displayAll();
     
    // Display L2 again. (still 5 elements 1,2,3,4,5)
    cout << "Displaying everything on list L2: ";
    L2.displayAll();
    
    // initializing searchable linked list
    return 0;
}
