//
//  dgraph.cpp
//  Directed Graphs
//  dgraph.h implementation file
//  Created by Jer Cherng Law on 11/16/14.
//  Copyright (c) 2014 Jer Cherng Law. All rights reserved.
//

#include "dgraph.h"


// ====   For the dgraph.cpp file ====================================
// note that Gtable[i].adjacnentOnes is a slist, so you can use
//  any slist function on it

dgraph::dgraph(){    // initialize vertexName (blank) and visit numbers (0)
    for(int i = 0; i < SIZE; i++) 		//initializes all elements of our table (*)
    {
        Gtable[i].visit = 0;
        Gtable[i].vertexName = ' ';
    }
    countUsed = 0;					// initialize countUsed to 0
}


void dgraph::fillTable(){   // read from the input file table.txt and fill GTable
    int slot = 0;
    el_t read_char;
    
    ifstream fin;
    fin.open("/Users/jerchernglaw/Documents/CS 311/HWPrograms/forHW6/table.txt");
    
    //  Hint on filltable::
    while (fin >> Gtable[slot].vertexName)  // if I can read the name
    {
        // increment the countUsed;
        countUsed++;
        fin >> Gtable[slot].outDegree;
        // Then for the outDegree times do the following:
        for(int i = 0; i < Gtable[slot].outDegree; i++) // note ++a vs a++ (*)
        {
            fin >> read_char;
            // below utilize slist
            (Gtable[slot].adjacentOnes).addRear(read_char);
        }
        slot++;
    }
    fin.close(); //close input file
}
void dgraph::displayGraph() {  // displays in an easy to read format
    // Hint on displaygraph
    for (int i = 0; i < countUsed; i++)
    {
        cout << Gtable[i].vertexName << endl;
        cout << Gtable[i].outDegree << endl;
        (Gtable[i].adjacentOnes).displayAll();
    }
}
int dgraph::findOutDegree(el_t x){  // returns the out degree of a given vertex

    for(int i = 0; i < countUsed; i++)		//while i < #of slots used (*)
        if(x == Gtable[i].vertexName)		//if vertex is found
            return Gtable[i].outDegree;		//return outDegree
    cout << "Error: Vertex does not exist." << endl;	//when vertex is not found
    return 1;
}

slist dgraph::findAdjacency(el_t x){  // returns the adjacency list of a given vertex
    for(int i = 0; i < countUsed; i++)		//while i < #of slots used (*)
        if(x == Gtable[i].vertexName)		//when requested list head is found
            return Gtable[i].adjacentOnes;		//return adjacency list object
    cout << "Error: Vertex does not exist." << endl;
    slist temp;					//creates Null slist object to be returned
    return temp;
}