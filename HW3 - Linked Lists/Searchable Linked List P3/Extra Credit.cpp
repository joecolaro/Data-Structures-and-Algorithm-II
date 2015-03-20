/* ====================================================
 
 Extra Credit for HW3P3
 Your name: Jer Cherng Law
 Complier : Xcode g++ 4.2.1
 File type: Test file for overloading operator==
 
 //===================================================== */

#include "slist.h"

int main() {
    
    slist L1, L2;
    
    el_t remove;
    // =====================================
    // Test cases
    // =====================================
    
    // ===================================== L1 is empty and L2 is empty =====================================
    (L1.isEmpty())? cout << "L1 is Empty\n": cout << "L1 has " << L1.getNumberofElements() << " elements.\n";
    (L2.isEmpty())? cout << "L2 is Empty\n": cout << "L2 has " << L2.getNumberofElements() << " elements.\n";
    cout << "Displaying everything on list L1: ";
    L1.displayAll();
    cout << "Displaying everything on list L2: ";
    L2.displayAll();
    (L1 == L2)? cout << "L1 is equals to L2.\n\n": cout << "L1 is not equals to L2.\n\n";
    while(!L1.isEmpty() || !L2.isEmpty()) {
        if(!L1.isEmpty())
            L1.deleteRear(remove);
        if(!L2.isEmpty())
        L2.deleteRear(remove);
    }
    
    // ================================== L1 is empty and L2 has 2 elements ==================================
    L2.addRear(9);
    L2.addRear(8);
    (L1.isEmpty())? cout << "L1 is Empty\n": cout << "L1 has " << L1.getNumberofElements() << " elements.\n";
    (L2.isEmpty())? cout << "L2 is Empty\n": cout << "L2 has " << L2.getNumberofElements() << " elements.\n";
    cout << "Displaying everything on list L1: ";
    L1.displayAll();
    cout << "Displaying everything on list L2: ";
    L2.displayAll();
    (L1 == L2)? cout << "L1 is equals to L2.\n\n": cout << "L1 is not equals to L2.\n\n";
    while(!L1.isEmpty() || !L2.isEmpty()) {
        if(!L1.isEmpty())
            L1.deleteRear(remove);
        if(!L2.isEmpty())
            L2.deleteRear(remove);
    }
    
    // ================================== L1 has 2 elements and L2 is empty  ==================================
    L1.addRear(9);
    L1.addRear(8);
    (L1.isEmpty())? cout << "L1 is Empty\n": cout << "L1 has " << L1.getNumberofElements() << " elements.\n";
    (L2.isEmpty())? cout << "L2 is Empty\n": cout << "L2 has " << L2.getNumberofElements() << " elements.\n";
    cout << "Displaying everything on list L1: ";
    L1.displayAll();
    cout << "Displaying everything on list L2: ";
    L2.displayAll();
    (L1 == L2)? cout << "L1 is equals to L2.\n\n": cout << "L1 is not equals to L2.\n\n";
    while(!L1.isEmpty() || !L2.isEmpty()) {
        if(!L1.isEmpty())
            L1.deleteRear(remove);
        if(!L2.isEmpty())
            L2.deleteRear(remove);
    }
    
    // ================================== L1 has 1,2,3 and L2 has 1,2,3 ==================================
    L1.addRear(1);
    L1.addRear(2);
    L1.addRear(3);
    
    L2.addRear(1);
    L2.addRear(2);
    L2.addRear(3);
    
    (L1.isEmpty())? cout << "L1 is Empty\n": cout << "L1 has " << L1.getNumberofElements() << " elements.\n";
    (L2.isEmpty())? cout << "L2 is Empty\n": cout << "L2 has " << L2.getNumberofElements() << " elements.\n";
    cout << "Displaying everything on list L1: ";
    L1.displayAll();
    cout << "Displaying everything on list L2: ";
    L2.displayAll();
    (L1 == L2)? cout << "L1 is equals to L2.\n\n": cout << "L1 is not equals to L2.\n\n";
    while(!L1.isEmpty() || !L2.isEmpty()) {
        if(!L1.isEmpty())
            L1.deleteRear(remove);
        if(!L2.isEmpty())
            L2.deleteRear(remove);
    }
    
    // =================================== L1 has 1,2,3 and L2 has 1,2 ===================================
    L1.addRear(1);
    L1.addRear(2);
    L1.addRear(3);
    
    L2.addRear(1);
    L2.addRear(2);
    
    (L1.isEmpty())? cout << "L1 is Empty\n": cout << "L1 has " << L1.getNumberofElements() << " elements.\n";
    (L2.isEmpty())? cout << "L2 is Empty\n": cout << "L2 has " << L2.getNumberofElements() << " elements.\n";
    cout << "Displaying everything on list L1: ";
    L1.displayAll();
    cout << "Displaying everything on list L2: ";
    L2.displayAll();
    (L1 == L2)? cout << "L1 is equals to L2.\n\n": cout << "L1 is not equals to L2.\n\n";
    while(!L1.isEmpty() || !L2.isEmpty()) {
        if(!L1.isEmpty())
            L1.deleteRear(remove);
        if(!L2.isEmpty())
            L2.deleteRear(remove);
    }
    
    // ================================== L1 has 1,2,3 and L2 has 1,2,3,4 ==================================
    L1.addRear(1);
    L1.addRear(2);
    L1.addRear(3);
    
    L2.addRear(1);
    L2.addRear(2);
    L2.addRear(3);
    L2.addRear(4);
    
    (L1.isEmpty())? cout << "L1 is Empty\n": cout << "L1 has " << L1.getNumberofElements() << " elements.\n";
    (L2.isEmpty())? cout << "L2 is Empty\n": cout << "L2 has " << L2.getNumberofElements() << " elements.\n";
    cout << "Displaying everything on list L1: ";
    L1.displayAll();
    cout << "Displaying everything on list L2: ";
    L2.displayAll();
    (L1 == L2)? cout << "L1 is equals to L2.\n\n": cout << "L1 is not equals to L2.\n\n";
    while(!L1.isEmpty() || !L2.isEmpty()) {
        if(!L1.isEmpty())
            L1.deleteRear(remove);
        if(!L2.isEmpty())
            L2.deleteRear(remove);
    }
    
    // ================================== L1 has 1,2,3 and L2 has 1,2,4 ==================================
    L1.addRear(1);
    L1.addRear(2);
    L1.addRear(3);
    
    L2.addRear(1);
    L2.addRear(2);
    L2.addRear(4);
    
    (L1.isEmpty())? cout << "L1 is Empty\n": cout << "L1 has " << L1.getNumberofElements() << " elements.\n";
    (L2.isEmpty())? cout << "L2 is Empty\n": cout << "L2 has " << L2.getNumberofElements() << " elements.\n";
    cout << "Displaying everything on list L1: ";
    L1.displayAll();
    cout << "Displaying everything on list L2: ";
    L2.displayAll();
    (L1 == L2)? cout << "L1 is equals to L2.\n\n": cout << "L1 is not equals to L2.\n\n";
    while(!L1.isEmpty() || !L2.isEmpty()) {
        if(!L1.isEmpty())
            L1.deleteRear(remove);
        if(!L2.isEmpty())
            L2.deleteRear(remove);
    }
    return 0;
}

