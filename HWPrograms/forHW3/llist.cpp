//INSTRUCTION:
//Use the provided text to help create llist.cpp
//based on Yoshii  CS311  Notes-6A
//Make sure all if-then-else are commented describing which case it is
//Make sure all local variables are described fully

/* ====================================================

HW3P1 llist
Your name: Jer Cherng Law
Complier:  Xcode g++ 4.2.1
File type: Implementation file for linked lists.

//===================================================== */

#include"llist.h" 

// llist Constructor
llist::llist()
{
    // This does not create any node.  The new list is empty.
    // initialize Front and Rear to be NULL and Count = 0.
    Front = NULL;
    Rear = NULL;
    Count = 0;
}

// llist Destructor
llist::~llist()
{
    // Please place a cout in this function "calling the llist desctructor."
    cout << "Calling the linked list destructor.\n";

    // use this in order to pass by reference to deleteFront
    el_t removing;
    
    // while the list is not empty, call deleteFront repeatedly to delete all nodes.
    while(!this->isEmpty()) this->deleteFront(removing);
}

bool llist::isEmpty()
{
    // return true if Front and Rear are both pointing to NULL.
    // Without using count - (note: do not use Count for this!!!)
    // using selection statements for practice
    return (this->Front == NULL && this->Rear == NULL)? true: false;
}


void llist::displayAll()
{
    // (special case: if the list is empty, display [ empty ] ).
    if(this->isEmpty()) cout << "Empty linked list\n";
    
    else
    {
        cout << "Displaying everything on list: \n";
        
        Node * P = this->Front;
        // displays each element of the list starting from Front in [ ].
        while (P != NULL)
        {
            cout << P->Elem << ' ';
            P = P->Next;
        }
        cout << '\n';
    }
}

void llist::addRear(el_t NewNum)
{
    // 2 cases
    // (special case: if this is going to be the very first node, you must
    // create a new node and make Front and Rear point to it.)

    // (special case: if this is going to be the very first node, you must
    // create a new node and make Front and Rear point to it.)
    if(Count == 0)
    {
        Node * newNode = new Node;
        newNode->Elem = NewNum;
        Rear = newNode;
        Front = newNode;
        Count++;
    }
    
    // adds a new node at the rear and puts NewNum in the Elem field
    // of this new node. Count is updated.
    else
    {
        // Regular case:
        Rear->Next = new Node;
        Rear = Rear->Next;
        Rear->Elem = NewNum;
        Rear->Next = NULL;
        Count++;
    }
}


void llist::addFront(el_t NewNum)
{
    // - 2 cases
    // - will add a new node to the front of the list. Count is updated.
    // - (special case: if this is going to be the very first node, you must
    //   create a new node and make Front and Rear point to it.)
    if(Count == 0)
    {
        Node * newNode = new Node;
        newNode->Elem = NewNum;
        Rear = newNode;
        Front = newNode;
        Count++;
    }
    
    // Regular Case:
    else
    {
        Node * newNode = new Node;
        newNode->Next = Front;
        Front = newNode;
        Front->Elem = NewNum;
        Count++;
    }
}

void llist::deleteFront(el_t& OldNum)
{
    Underflow underflow;
    // 3 cases
    // error case: if the List is empty, throw an exception.
    // else give back the front node element through OldNum (pass by reference)
    //    and also remove the front node. Count is updated.
    // (special case: if this is going to make the list empty,
    //    make sure both Front and Rear become NULL).
    
    // if empty
    if(this->isEmpty()) throw underflow;
    
    //Regular case:
    Count--;
    OldNum = Front->Elem;
    
    // check if will make list empty
    if(Count == 0)
    {
        delete Front;
        Front = NULL;
        Rear = NULL;
    }
    
    // else proceed as usual
    else
    {
        Node * Second = Front->Next;
        delete Front;
        Front = Second;
    }
}

void llist::deleteRear(el_t& OldNum)
{
    // - 3 cases
    // - error case: if empty, throw an exception.
    // - else give back the rear node element through OldNum (pass by reference)
    //      and also remove the rear node. Count is updated.
    // - (special case: if this is going to make the list empty,
    //      make sure both Front and Rear become NULL).
    // Regular case:
    
    Underflow underflow;
    if(this->isEmpty()) throw underflow;
    
    //Regular case:
    Count--;
    OldNum = Rear->Elem;
    
    // check if will make list empty
    if(Count == 0)
    {
        delete Rear;
        Front = NULL;
        Rear = NULL;
    }
    
    // else proceed as usual
    else
    {
        Node * previousNode = Front;
        // traverse through list until 2nd last item, remove rear and relink 2nd last to be last item
        while(previousNode->Next != Rear) {
            previousNode = previousNode->Next;
        }
        
        OldNum = Rear->Elem;
        // inserted this line to prevent memory leak before deleting
        // just to make sure nothing is pointing to rear

        previousNode->Next = NULL;
        delete Rear;
        Rear = previousNode;
        
        // double safety mechanism.
        Rear->Next = NULL;
    }
}

void llist::deleteIth(int I, el_t& OldNum)
{
    OutOfRange outOfRange;
    // - 4 cases
    // Error cases:
    // If I is an illegal value (i.e. > Count or < 1) throw an exception.
    if(I > Count || I < 1)
    {
        throw outOfRange;
    }

    // - (note: this may simply call deleteFront or deleteRear for some cases)
    // if Count == 0, the functions will handle it.
    // if first item, call deleteFront
    else if(I == 1) this->deleteFront(OldNum);
    // if last item, call deleteRear
    else if(I == Count) this->deleteRear(OldNum);

    // - will delete the Ith node (I starts out at 1).  Count is updated.
    else
    {
        // previousNode is used to point towards the node behind the node
        // intended for deletion in order to repair links
        Node * previousNode = Front;
        // currentNode is the node that needs to be found and deleted
        Node * currentNode = Front;
        
        // first we initialize j to 1
        // then until j is I, we do the following:
        // 1. we increment j
        // 2. make sure current node is not lost by setting previousNode to it
        // 3. then we iterate to the next item on the list using currentNode = currentNode->Next
        for(int j = 1; j != I; j++, previousNode = currentNode, currentNode = currentNode->Next);
        OldNum = currentNode->Elem;
        previousNode->Next = currentNode->Next;
        delete currentNode;
        // after deleting, shrink Count
        Count--;
    }
}

void llist::addbeforeIth(int I, el_t newNum)
{
    OutOfRange outOfRange;
    
    // - 4 cases
    // -  will add right before the Ith node.  Count is updated.
    // -  Error cases:
    // If I is an illegal value (i.e. > Count+1 or < 1) throw an exception.
    // (note: this may simply call addFront or addRear for some cases)
    if(I < 1 || I > Count+1) throw outOfRange;
    else if(I == Count+1) this->addRear(newNum);
    else if(I == 1) this->addFront(newNum);
    else
    {
        // previousNode is used to relink link->next that connects to (i+1)th node
        // to new node
        Node * previousNode = Front;
        // newNode->Next connects to currentNode which is the (i + 1)th node
        Node * currentNode = Front;
        Node * newNode = new Node;
        newNode->Elem = newNum;
        newNode->Next = NULL;
        
        for(int j = 1; j != I; j++, previousNode = currentNode, currentNode = currentNode->Next);
        previousNode->Next = newNode;
        newNode->Next = currentNode;
        
        Count++;
    }
}
