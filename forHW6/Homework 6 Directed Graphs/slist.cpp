/* ====================================================
 
 HW3P3 slist - (slist.cpp)
 Your name: Jer Cherng Law
 Complier:  Xcode g++ 4.2.1
 File type: Implementation file for child class searchable linked lists in HW3P3.
 
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

// overloading =
// The operator = does not work well with pointers

slist& slist::operator=(const slist& OtherOne)
{
    el_t remove;
    // First make sure this-> and OtherOne are not the same object.
    // To do this, compare the pointers to the objects .
    if (&OtherOne != this)  // if not the same
    {
        // this-> object has to be emptied first.
        while (!this->isEmpty()) this->deleteRear(remove);
        // this-> object has to be built up by allocating new cells (**)
        
        Node* P;  // local pointer for OtherOne
        P = OtherOne.Front;
        while (P != NULL)  // This uses a loop which repeats until you reach the end of OtherOne.
        {
            this->addRear(P->Elem);    //P’s element is added to this->
            P = P->Next;               // Go to the next node in OtherOne
        }
    }// end of if
    return *this;    // return the result unconditionally.
}

// overloading =
// The operator = does not work well with pointers
bool slist::operator==(const slist& linkedList) {
    Node * pointertoLeftHandSideLinkedList = this->Front;
    
    slist makeCopy(linkedList);
    Node * pointertoRightHandSideLinkedList = makeCopy.Front;
    
    // case 1, check for size
    if(this->Count != linkedList.Count) return false;
    bool isStillSame = true;
    // case 2, if size is same
    while (true) {
        if(pointertoLeftHandSideLinkedList == NULL) break;
        if(pointertoLeftHandSideLinkedList->Elem != pointertoRightHandSideLinkedList->Elem) isStillSame = false;
        
        pointertoLeftHandSideLinkedList = pointertoLeftHandSideLinkedList->Next;
        pointertoRightHandSideLinkedList = pointertoRightHandSideLinkedList->Next;
    }
    return isStillSame;
}

// The copy constructor to allow pass by value and return
// The regular copy constructor does not work well with pointers
slist::slist(const slist& linkedListToBeCopied){
    *this = linkedListToBeCopied;
}

// Copytest will receive the list passed by value from main() and
void slist::copyTest(){
    // Simply
    // 1) add a node to its rear with 6 in it (should not affect the original)
    // 2) display it (6 elements 1,2,3,4,5,6)
    slist newLinkedListCopy(*this);
    newLinkedListCopy.addRear(6);
    cout << "Displaying everything on copied linked list of L1: ";
    newLinkedListCopy.displayAll();
}

int slist::getNumberofElements(){
    return Count;
}
