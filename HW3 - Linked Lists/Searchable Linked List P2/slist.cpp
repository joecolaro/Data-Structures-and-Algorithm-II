/* ====================================================
 
 HW3P2 slist
 Your name: Jer Cherng Law
 Complier:  Xcode g++ 4.2.1
 File type: Implementation file for child class searchable linked lists.
 
 //===================================================== */
#include "slist.h"

slist::slist(){}

slist::~slist(){}

int slist::search(el_t newNum){
    int position = 1;
    Node * p = Front;
    while(p->Elem != newNum){

        position++;
        if(position > Count) break;
        p = p->Next;
        
    }
    return (position >= 1 && position <= Count)? position: 0;
}
// search through the list to see if any node contains the key.
// If so, return its position (>=1). Otherwise, return 0.

void slist::replace(el_t newNum,  int ithNode){
    OutOfRange outOfRange;
    Node * p = Front;
    // If I was an illegal value, throw an exception.
    if( ithNode < 1 || ithNode > Count) throw outOfRange;
    else
        // go to the Ith node (I is between 1 and Count) and
        for(int i = 1; i != ithNode; i++, p = p->Next);
    // replace the element there with the new element.
    int temp = p->Elem;
    p->Elem = newNum;
    cout << temp << " has been replaced with " << p->Elem << '\n';
}