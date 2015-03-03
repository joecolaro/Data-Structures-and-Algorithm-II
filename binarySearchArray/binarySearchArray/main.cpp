// ======================================================================
// HW2P1 binary search implementation and test file AIO (binSearchTree.cpp
// Your name: Jer Cherng Law
// Complier: Mac OS X Terminal g++ v4.2.1
// File type: client file
//=======================================================================

#include <iostream>
#include <fstream>
using namespace std;

void binarySearch(int[], int, int, int);

int main()
{
    
    int search = 0, intArray[] = {1, 3, 5 ,7, 9, 11, 13, 15, 17, 19};
    int first = 0, last = 9;
    ifstream fin;
    fin.open("inputBinSearch.txt");
    
    while(!fin.eof())
    {
        fin >> search;
        fin.ignore(1000,10);
        
        binarySearch(intArray, first, last, search);
    }
    
    fin.close();
    return 0;
}

void binarySearch(int array[], int first, int last, int searchItem)
{
    int middle;
    
    // start by finding middle
    middle = (first + last) / 2;
    
    // terminating case when item is found or when last < first or first > last
    while((array[middle] != searchItem) && (first <= last))
    {
        cout << "comparing against an element in slot " << middle << '\n';
        // these two cases of adding and subtracting is reducing the size of the array
        // narrowing the choices down depending on the comparison with the middle item
        if (array[middle] > searchItem)     // If the number is > searchItem,
        {                                   // decrease middle by one.
            last = middle - 1;
        }
        else
        {
            first = middle + 1;             // Else, increase middle by one.
        }
        middle = (first + last) / 2;        // give new value of middle after modifying first/last
    }
    
    if (first <= last)
    {
        cout<< "Number was found in middle "<< middle + 1 << "\n\n";
    }
    
    else
        cout<< "Failed.\n";                 // Number is not in array
}