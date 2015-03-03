//===========================================================
//HW6
//Your name: Alexis Scollard
//Complier:  g++
//File type:  Client file
//===========================================================

#include "dgraph.h"

// Main driver for D-Graph
int main()
{
  slist l1;
  dgraph G; 
  char x;		//for user input
  
  G.fillTable();	//read value from table.txt
  G.displayGraph();	//Display graph	
	
  bool ok = true;

  //Loop until user wants to quit
  while (ok)
  {
      cout << "\nEnter vertex letter to find out degree or 'q' to quit: ";
      cin >> x;
      if(x == 'q')	//if q was entered break loop
	ok = false;
      else
	cout << "The degree at '" << x << "' is: " << G.findOutDegree(x) << endl;
  }
  
  ok = true;

  //Loop until user wants to quit
  while (ok)
    {
      cout << "\nEnter vertex letter to find adjacency list or 'q' to quit: ";
      cin >> x;
      if(x == 'q')	//if q was entered break loop
	ok = false;
      else
	{
	  cout << "The adjacency list at '" << x << "' is:" << endl;
	  l1 = G.findAdjacency(x);
	  l1.displayAll();
	}
    }
}

