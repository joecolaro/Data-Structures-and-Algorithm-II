/* ====================================================
 
 HW3P2 slist
 Your name: Jer Cherng Law
 Complier:  Xcode g++ 4.2.1
 File type: Header file for child class searchable linked lists.
 
 //===================================================== */

#ifndef __Searchable_Linked_List__slist__
#define __Searchable_Linked_List__slist__

#include "llist.h"

// HW3P2  Instruction: Inherit everything publicly from llist

// Add the following to slist.h
class slist: public llist {
    
public:
    // constructor which is the same as the llist one
    slist();
    ~slist();
    int search(el_t);
    // search through the list to see if any node contains the key.
    // If so, return its position (>=1). Otherwise, return 0.
    
    void replace(el_t,  int);
    // go to the Ith node (I is between 1 and Count) and
    // replace the element there with the new element.
    // If I was an illegal value, throw an exception.
    
    // Then create slist.cpp with the above functions

};
#endif /* defined(__Searchable_Linked_List__slist__) */
