// =========================================================

//HW2P2 stack client
//Your name: Jer Cherng Law
//Complier:  Xcode g++ 4.2.1
//File type: Client file AIO

//================================================================

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void combine(vector<int>, vector<int>, vector<int> &);
vector<int>::iterator vectorIterator;

int main()
{
    int tempInt = 0;
    
    vector<int> L1;
    vector<int> L2;
    vector<int> L3;
    
    cout << "Please enter 3 values for vector L1 in ascending order: ";
    for (int j = 0; j < 3; j++)
    {
        cin >> tempInt;
        cin.ignore(1000,10);
        L1.push_back(tempInt); // pushes user input onto vector L1
    }
    
    cout << "Please enter 3 values for vector L1 in ascending order: ";
    for (int j = 0; j < 3; j++)
    {
        cin >> tempInt;
        cin.ignore(1000,10);
        L2.push_back(tempInt); // pushes user input onto vector L2
    }
    
    // reverse order of items on the vector list because it reads user input a b c
    // as c b a, reverse order to become a b c
    reverse(L1.begin(),L1.end());
    reverse(L2.begin(),L2.end());

    combine(L1, L2, L3);
    
    // output function
    cout << "Resulting vector is: " ;
    for(vectorIterator = L3.begin(); vectorIterator != L3.end(); vectorIterator++)
        cout << *vectorIterator << ' ';
    cout << '\n';
    return 0;
}

void combine(vector<int> A, vector<int> B, vector<int> &R)
{
    // this function combines two vectors into a singular
    // it is not exactly a true merge sort function.
    // it checks to see if one value in the vector is less than the other.
    // If it is, it will push itself onto the resulting vector L3
    // else, the item being compared to will be pushed onto the resulting
    // vector.
    

    // sizes of A and B are compared for error checking
    if(A.size() != B.size())
        cout << "Size of both vectors are different. Cannot compute.\n";
    
    // else, while both vector A and vector B contains elements
    else
    {
        while (!A.empty() && !B.empty())
        {
            
            cout << "Comparing item from L1: " << A.back() << " with item from L2: " << B.back() << '\n';
            
            // if array[i2] < array [i3]
            if(A.back() < B.back())
            {
                // equivalent of: array[i++] = array[i2++]
                R.push_back(A.back());
                A.pop_back();
            }
            else
            {
                // equivalent of: array[i++] = array[i3++]
                A.push_back(B.back());
                B.pop_back();
            }
        }
        
        if(!A.empty()) {
            while(!A.empty()) {
                R.push_back(A.back());
                A.pop_back();
            }
        }
        
        else if(!B.empty()) {
            while(!B.empty()) {
                R.push_back(B.back());
                B.pop_back();
            }
        }
    }
}
