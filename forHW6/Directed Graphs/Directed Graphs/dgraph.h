//
//  dgraph.h
//  Directed Graphs
//
//  Created by Jer Cherng Law on 11/16/14.
//  Copyright (c) 2014 Jer Cherng Law. All rights reserved.
//

#ifndef __Directed_Graphs__dgraph__
#define __Directed_Graphs__dgraph__

// ============ for the dgraph.h file =================================

// You need to comment this file completely using the How to Comment file.
// We will check to see how well you have commented it

// I am using hw3p3.h which is the most up to date slist.h

#include "slist.h"

const int SIZE = 20;

// this will be in each GTable slot
struct Gvertex
{
    el_t vertexName;       //the vertex Name
    int outDegree;	//the Out degree
    slist adjacentOnes;   //the adjecent vertices in an slist
    int visit;            // This will hold the visit number in HW7
};

class dgraph
{
private:
    Gvertex Gtable[SIZE];
    int  countUsed; // how many slots of the Gtable are actually used
    
public:
    
    dgraph();    // initialize vertexName (blank) and visit numbers (0)
                 // initialize countUsed to be 0
    ~dgraph(){};   // do we have to delete all nodes of slists in table??
                 // Question: If we do not do this, will the llist destructor
                 // be called automatically??? Yes it will.
    
    
    void fillTable();   // read from the input file table.txt and fill GTable
    
    void displayGraph();  // displays in an easy to read format
    
    int findOutDegree(el_t);  // returns the out degree of a given vertex
    
    slist findAdjacency(el_t);  // returns the adjacency list of a given vertex
};

#endif /* defined(__Directed_Graphs__dgraph__) */