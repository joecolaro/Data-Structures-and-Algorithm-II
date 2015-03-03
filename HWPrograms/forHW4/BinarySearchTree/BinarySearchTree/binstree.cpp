// CS311 : This is the BST implementation file template by Rika Yoshii

// =========================================================

//HW4 BST
//Your name: Jer Cherng Law
//Complier:  Xcode 6 - gcc 4.2.1
//File type: Implementation File (binstree.cpp)

//================================================================


#include <iostream>
using namespace std;

#include "binstree.h"

// constructor  initializes Root
BST::BST()
{
   Root = NULL;   // This is an empty tree
}

// destructor must completely destroy the tree
BST::~BST()
{
   dtraverse(Root); // traverse to delete all vertices in post order
   Root = NULL;    
}


// PURPOSE: Does Post Order traversal of the tree and deletes each vertex
// PARAM:  pointer to the vertex to be deleted
void BST::dtraverse(Vertex *V)  // post order traversal
{   
    if (V != NULL)
    {
        dtraverse(V->Left);         // visit left sub tree of V
        dtraverse(V->Right);       // visit right sub tree of V
        delete V;                  // deletes V
    } // postorder delete
}


// PURPOSE: Show elements in IN order traversal from the Root
void BST::ShowInOrder()
{
    cout << "Elements in the IN order: " << endl;
    INorderTraversal(Root);  // start in-order traversal from the root
}

// PURPOSE: Does IN order traversal from V recursively
// PARAM: pointer to the vertex to visit right now
void BST::INorderTraversal(Vertex *V)
{
    if (V != NULL)
    {
        // ** traverse left sub-tree of V recursively
        INorderTraversal (V->Left);
        // ** display V's element and do endl;
        cout << V->Elem << '\n';
        // ** traverse right sub-tree of V recursively
        INorderTraversal (V->Right);
    }
} // endl flushes out cout, everything is being queued to the outstream
  // queue doesn't print out until endl?
  // inaccurate info, she's saying that it prints everything even though the
  // program crashes midway but I've never had that happen to me

// PURPOSE:  Show elements in PRE order traversal from the Root
// This is the same as Depth First Traversal
void BST::ShowPreOrder()
{
  cout << "Elements in the PRE order:" << endl;
  PREorderTraversal(Root);  // start pre-order traversal from the root
}

// PURPOSE: Does PRE order traversal from V recursively
// PARAM: pointer to the vertex to be visited now
void BST::PREorderTraversal(Vertex *V)
{
    if (V != NULL)
    {
        // ** display V's element and do endl;
        cout << V->Elem << endl;
        // ** traverse left sub-tree of V recursively
        this->PREorderTraversal(V->Left);
        // ** traverse right sub-tree of V recursively
        this->PREorderTraversal(V->Right);
    }
}


// PURPOSE: Adds a vertex to the binary search tree for new element 
// PARAM: the new element E
// ALGORITHM: We will do this iteratively (not recursively)
//     - smaller than the current -> go to the left
//     - bigger than the current  -> go to the right
//    - cannot go any further    -> add it there
void BST::Insertvertex(elem_t E)
{
    Vertex *N;       // N will point to the new vertex to be inserted
    N = new Vertex;        // a new vertex is created
    N->Left  = NULL;     // make sure it does not
    N->Right = NULL;    // point to anything
    N->Elem  = E;            // put element E in it
    
    cout << "Trying to insert " << E << endl;
    
    if (Root == NULL)  // Special case: we have a brand new empty tree
    {
        Root = N;      // the new vertex is added as the root
        cout << "...adding " << E << " as the root" << endl;
    }
    
    else  // the tree is not empty
    {
        Vertex *V;       // V will point to the current vertex
        Vertex *Parent;  // Parent will point to V's parent
        
        V = Root;        // start with the root as V
        
        while (V != NULL)  // go down the tree until you cannot go any further
        {
            if (N->Elem == V->Elem) // special case
            {
                cout << "...error: the element already exists" << endl;
                return;
            }
            else
                if (N->Elem < V->Elem)  // what I have is smaller than V
                {
                    cout << "...going to the left" << endl;
                    // ** change Parent to be V to go down
                    Parent = V;
                    // ** change V to be V's Left
                    V = V->Left;
                }
                else // what I have is bigger than V
                {
                    cout << "...going to the right" << endl;
                    // ** change Parent to be V to go down
                    Parent = V;
                    // ** change V to be V's Right
                    V = V->Right;
                }
            
        }//end of while
        
        // reached NULL -- Must add N as the Parent's child
        
        if (N->Elem < Parent->Elem)
        {
            // ** Parent's Left should point to the same place as N
            cout << "...adding " << E << " as the left child of "
            << Parent->Elem << endl;
            Parent->Left = N;
        }
        else
        {
            // ** Parent's Right should point to the same place as N
            cout << "...adding " << E << " as the right child of "
            << Parent->Elem << endl;
            Parent->Right = N;
        }
        
    }// end of normal case
}// end of InsertVertex


// PURPOSE: Deletes a vertex that has E as its element.
// PARAM: element E to be removed
// ALGORITHM: First we must find the vertex then call Remove
void BST::DeleteVertex(elem_t E)
{
    cout << "Trying to delete " << E << endl;
    
    Vertex *V;              // the current vertex
    Vertex *Parent = NULL;  // its parent
    
    if ((E == Root->Elem) && (Root->Left == NULL) && (Root->Right == NULL))
    { cout << "...deleting the lonely root" << endl;
        delete Root;
        Root = NULL;
        return; }  // only the Root was there and deleted it
    
    // ** if V is the root with one child
    else if (((E == Root->Elem) && (Root->Left == NULL)) || ((E == Root->Elem) && (Root->Right == NULL)))
    {
        if(Root->Left == NULL)
        {
            V = Root->Right;
            delete Root;
            Root = V;
        }
        else
        {
            V = Root->Left;
            delete Root;
            Root = V;
        }
        return;
    }
    
    // Otherwise deleting something else
    
    V = Root;  // start with the root to look for E
    
    while (V->Right != NULL || V->Left != NULL)
    {
        if (E == V->Elem)   // found it
        {
            cout << "...removing " << V->Elem << endl;
            // ** call remove here to remove V
            remove(V, Parent);
            return;
        }
        
        else
            if (E < V->Elem)
            {
                cout << "...going to the left" << endl;
                // ** update Parent and V here to go down
                Parent = V;
                V = V->Left;
            }
            else
            {
                cout << "...going to the right" << endl;
                // ** update Parent and V here to go down
                Parent = V;
                V = V->Right;
            }
    }// end of while
    
    // reached NULL  -- did not find it
    cout << "Did not find the key in the tree." << endl;
}// end of DeleteVertex


// PURPOSE: Removes vertex pointed to by V
// PARAM: V and its parent  pointer P
// Case 1: it is a leaf – delete it
// Case 2: it has just one child – bypass it
// Case 3: it has two children – replace it with the max of the left //subtree

void BST::remove(Vertex *V, Vertex *P)
{
    // ** if V is a leaf (case 1)
    if(V->Left == NULL && V->Right == NULL)
    {
        cout << ".. removing a leaf" << endl;
        if(P->Left == V)
        // ** if V is a left child of P
        {
            // ** delete V and also make Parent's left NULL
            delete V;
            P->Left = NULL;
        }
        else // V is a right child of the Parent
        {
            // ** delete V and also make Parent's right NULL
            delete V;
            P->Right = NULL;
        }
    } // end of leaf case
    
    // ** else if V has just the left child (case 2)
    else if(V->Left != NULL && V->Right == NULL)
    {
        cout << "removing a vertex with just the left child" << endl;
        // ** Make Parent's left or right point to the left child and
        // delete V (You need if then else to determine left or right)
        P->Left = V->Left;
        delete V;
    }
    
    // **else if V has just the right child
    else if(V->Left == NULL && V->Right != NULL)
    {
        cout << "removing a vertex with just the right child" << endl;
        // ** Make Parent's left or right point to the right child and
        // delete V (need if then else to determine left or right)
        P->Right = V->Right;
        delete V;
    }
    
    else // V has two children (case 3)
    {
        cout << "...removing an internal vertex with children" << endl;
        cout << ".....find the MAX of its left sub-tree" << endl;
        elem_t Melem;
        Melem = findMax(V); // find MAX element in the left sub-tree of V
        cout << ".....replacing " << V->Elem << " with " << Melem << endl;
        // ** Replace V's element with Melem here
        V->Elem = Melem;
    }
 }// end of remove

// PURPOSE: Finds the Maximum element in the left sub-tree of V
elem_t BST::findMax(Vertex *V)
{
     Vertex *Parent = V;
     V = V->Left;          // start with the left child of V
    
    // ** while the right child of V is still available
    while (V->Right != NULL) {
        // ** update Parent and V to go to the right
        Parent = V;
        V = V->Right;
    }
    
    // reached NULL Right  -- V now has the MAX element
    elem_t X = V->Elem;
    cout << ".....Max is " << X << endl;
    remove(V, Parent);    // remove the MAX vertex
    return X;             // return the MAX element
    
}// end of FindMax

