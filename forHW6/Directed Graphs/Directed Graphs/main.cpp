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
    slist l1;
    dgraph directed_graph;
    el_t user_input;             //for user input
    
    directed_graph.fillTable();      //read value from table.txt
    directed_graph.displayGraph();	//Display graph
    
    //Loop until user wants to quit
    while(true)
    {
        cout << "\nEnter vertex letter to find outDegree or 'q' to quit: ";
        cin >> user_input;
        if(user_input == 'q') break; //if q was entered break loopbreak;
        else cout << "The degree at '" << user_input << "' is: " << directed_graph.findOutDegree(user_input) << endl;
    }
    
    
    //Loop until user wants to quit
    while(true)
    {
        cout << "\nEnter vertex letter to find adjacency list or 'q' to quit: ";
        cin >> user_input;
        if(user_input == 'q') break;	//if q was entered break loop
        else
        {
            cout << "The adjacency list at '" << user_input << "' is:" << endl;
            l1 = directed_graph.findAdjacency(user_input);
            l1.displayAll();
        }
    }
}

