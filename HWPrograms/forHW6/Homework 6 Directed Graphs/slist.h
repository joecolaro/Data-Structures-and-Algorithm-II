/* ====================================================
 
 HW3P3 slist - (slist.h)
 Your name: Jer Cherng Law
 Complier:  Xcode g++ 4.2.1
 File type: Header file for child class searchable linked lists in HW3P3
 
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
    
    // The copy constructor to allow pass by value and return
    // The regular copy constructor does not work well with pointers
    slist(const slist&);
    
    int search(el_t);
    // search through the list to see if any node contains the key.
    // If so, return its position (>=1). Otherwise, return 0.
    
    void replace(el_t,  int);
    // go to the Ith node (I is between 1 and Count) and
    // replace the element there with the new element.
    // If I was an illegal value, throw an exception.
    
    // overloading =
    // The operator = does not work well with pointers
    slist& operator=(const slist&);

    // overloading ==
    // The operator == does not work well with pointers
    bool operator==(const slist&);
    
    void copyTest();
    
    // this is for extra credit to tell user how many elements
    int getNumberofElements();
};
#endif /* defined(__Searchable_Linked_List__slist__) */
