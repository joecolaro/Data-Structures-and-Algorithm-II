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


// copy constructor for sorting
dgraph::dgraph(dgraph& copy_from_old){
    for(int i = 0; i < SIZE; i++) 		//initializes all elements of our table (*)
    {
        Gtable[i].visit = copy_from_old.Gtable[i].visit;
        Gtable[i].vertexName = copy_from_old.Gtable[i].vertexName;
        Gtable[i].outDegree = copy_from_old.Gtable[i].outDegree;
        Gtable[i].adjacentOnes = copy_from_old.Gtable[i].adjacentOnes;
    }

    countUsed = copy_from_old.countUsed;
}

void dgraph::fillTable(){   // read from the input file table.txt and fill GTable
    int slot = 0;
    el_t read_char;
    string read_input;
    
    ifstream fin;
    
    cout << "Please specify file path to be used. Otherwise default path will be used:\n";
    getline(cin, read_input);
    
    if(read_input == "")
        fin.open("/Users/jerchernglaw/Documents/CS 311/HWPrograms/forHW6/table.txt");
    
    else
        fin.open(read_input.c_str());
    
    if(!fin) {
        cout << "File does not exist. Exiting program.\n";
        exit(0);
    }
    
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
        cout << "Vertex Name       : " << Gtable[i].vertexName << '\n';
        cout << "Out Degree        : " << Gtable[i].outDegree << '\n';
        cout << "Adjacent Vertices : ";
        (Gtable[i].adjacentOnes).displayAll();
        cout << "\nVisit Number      : " << Gtable[i].visit << "\n\n";
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
    for(int i = 0; i < countUsed; i++)		// while i < #of slots used (*)
        if(x == Gtable[i].vertexName)		// when requested list head is found
            return Gtable[i].adjacentOnes;	// return adjacency list object
    cout << "Error: Vertex does not exist." << endl;
    slist temp;                             // creates Null slist object to be returned
    return temp;
}

// checks the visit number of gvertex.
// If 0 returns false otherwise returns true.
bool dgraph::isMarked(el_t vertexCheck){
    //return (this->visit == 0)? false: true;
    for(int i = 0; i < countUsed; ++i)
    {
        if(vertexCheck == Gtable[i].vertexName)
        {
            if(Gtable[i].visit != 0)
                return true;
        }
    }
    return false;
} // dgraph creates a table of gvertices
  // how to access the individual elements for this?

void dgraph::visit(int previousVisitValue, el_t vertexVisit) {
    // el_t is defined to be char in this program.
    // It is generic and can be changed within llist.
    // int holds the number of the previous vertex visited.
    // If the current vertex has not been visited, it's visit
    // value will be recorded as 1 increment of the visit number of previous node.
    for(int i = 0; i < countUsed; ++i)
    {
        if(Gtable[i].vertexName == vertexVisit)
        {
            Gtable[i].visit = previousVisitValue;
        }
    }
}



void dgraph::graph_sort()
{
    dgraph copy_graph(*this);
    // swap (current and compared)
    // check if visitnum is smaller if smaller then
    for(int i = 0; i < countUsed; i++){
        for(int j = 0; j < countUsed; j++){
            if(copy_graph.Gtable[i].visit <= copy_graph.Gtable[j].visit)
                swap(copy_graph.Gtable[i], copy_graph.Gtable[j]);
        }
    }

    for(int x = 0; x < copy_graph.countUsed; x++){
        cout << copy_graph.Gtable[x].vertexName << '(' << copy_graph.Gtable[x].visit << ')'<< " -> ";
    }
    
    cout << "end\n";
}
