//
//  main.cpp
//  Directed Graphs
//  Dgraph client file.
//  Created by Jer Cherng Law on 11/15/14.
//  Copyright (c) 2014 Jer Cherng Law. All rights reserved.
//

#include "dgraph.h"

int main()
{
    
    slist tempSlist;            // initialize slist
    stack tempStack;            // inistalize stack
    dgraph graph;               // initialize graph
    
    el_t currentVertex = 'A';   // initialized to starting vertex
    
    int count = 1;              // counter used for visitNum
    int vertexOutDegree;        // holds the out degree of current vertex

    
    graph.fillTable();
    
    cout << "Graph: "<< endl;
    graph.displayGraph();
    
    
    graph.visit(1,currentVertex); 		//the first vertex gets visited
    
    tempSlist = graph.findAdjacency(currentVertex); 	//stores adjacency list for first elements
    vertexOutDegree = graph.findOutDegree(currentVertex); 		//gets out degree for first adjacency list
    cout << "\nPopping: " << currentVertex << " from Stack" << endl;
    cout << "Adding : ";
    tempSlist.displayAll();
    cout << '\n';
    
    for(int i=0; i < vertexOutDegree; i++) 		//for i is less than outdegree
    {
        tempSlist.deleteRear(currentVertex); 	//returns element
        tempStack.push(currentVertex); 		//add element to the stack
    }
    
    cout << "\nCurrent Stack:" << endl;
    tempStack.displayAll();
    
    // DFS here
    while (!tempStack.isEmpty())            //until the stack is empty
    {
        
        count++;                            //add 1 to visit order
        tempStack.pop(currentVertex); 		//get top element of stack
        
        cout << "\nPopped " << currentVertex << " from Stack" << endl;
        
        if(!graph.isMarked(currentVertex))                  //while the element has not been visited yet
        {
            graph.visit(count,currentVertex);               //update visit number
            cout<< "Visited " << currentVertex << endl;
            
            tempSlist = graph.findAdjacency(currentVertex); //add adjacency list
            
            
            cout << "Adding: " << endl;
            tempSlist.displayAll();
            cout << '\n';
            
            vertexOutDegree = graph.findOutDegree(currentVertex);
            
            //adds adjacency list to the stack
            for(int i=0; i < vertexOutDegree; i++)
            {
                tempSlist.deleteRear(currentVertex);
                tempStack.push(currentVertex);
            }
        }
        
        // case: visited
        else
            cout << currentVertex << " is marked" << endl;
        
        cout << "Current Stack: " << endl;
        tempStack.displayAll();
    }
    
    graph.displayGraph();
    // copy graph onto another graph, sort that graph based on visit number
    cout << "---------------------------\n";
    cout << "Sorted display:\n";
    cout << "---------------------------\n";
    graph.graph_sort();
    
    return 0;
}
