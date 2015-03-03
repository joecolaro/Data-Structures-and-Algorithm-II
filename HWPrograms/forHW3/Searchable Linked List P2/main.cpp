/* ====================================================
 
 HW3P2 slist
 Your name: Jer Cherng Law
 Complier:  Xcode g++ 4.2.1
 File type: client file for testing searchable linked lists.
 
 //===================================================== */

#include "slist.h"

int main() {
    
    // initializing searchable linked list
    slist searchableLinkedList;
    
    // as per assignment requirement:
    // add 4 to Front
    searchableLinkedList.addFront(4);
    // addRear 3 times, 6, 7, 8
    searchableLinkedList.addRear(6);
    searchableLinkedList.addRear(7);
    searchableLinkedList.addRear(8);
    
    searchableLinkedList.displayAll();

    // searching for 6 in linked list
    if(!searchableLinkedList.search(6))
        cout << "6 was not found.\n";
    else
        cout << "6 is in position: " << searchableLinkedList.search(6) << '\n';

    
    // replace 6 with 0 using search result
    // calling for search result within a function.
    try {
        searchableLinkedList.replace(0, searchableLinkedList.search(6));
    }
    catch (llist::OutOfRange) {
        cout << "Trying to perform an action that is out of range.\n";
    }
    catch (llist::Underflow) {
        cout << "Trying to perform an action that is causing an underflow.\n";
    } // end of 6 replaced by 0
    

    // searching for 8 in linked list
    if(!searchableLinkedList.search(8))
        cout << "8 was not found.\n";
    else
        cout << "8 is in position: " << searchableLinkedList.search(8) << '\n';
    
    
    // trying to replace 8 with 2
    try {
        searchableLinkedList.replace(2, searchableLinkedList.search(8));
    }
    catch (llist::OutOfRange) {
        cout << "Trying to perform an action that is out of range.\n";
    }
    catch (llist::Underflow) {
        cout << "Trying to perform an action that is causing an underflow.\n";
    } // end of 8 replaced by 2
    
    
    searchableLinkedList.displayAll();
    
    // searching for 5, expected output is 5 was not found.
    if(!searchableLinkedList.search(5))
        cout << "5 was not found.\n";
    else
        cout << "5 is in position: " << searchableLinkedList.search(5) << '\n';
    
    return 0;
}
