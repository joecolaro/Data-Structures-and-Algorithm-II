/* ====================================================
 
 HW3P1 llist
 Your name: Jer Cherng Law
 Complier:  Xcode g++ 4.2.1
 File type: Implementation file for linked lists.
 
 //===================================================== */

#include "llist.h"

int menu();

int main() {
    
    llist LinkedList;
    
    el_t userInput, itemBeingRemoved;
    
    int choice = 0, indexOfItem = 0;
    // insert code here...
    while(true) {
        choice = menu();
        if(choice == -9999) break;
        try {
            switch(choice) {
                    
                    // add item to rear
                case 1:
                    cout << "Please enter the number you want to add to Rear: ";
                    cin >> userInput;
                    LinkedList.addRear(userInput);
                    cout << '(' << userInput << ") has been added onto the list.\n";
                    break;
                    
                    // add item to front
                case 2:
                    cout << "Please enter the number you want to add to Front: ";
                    cin >> userInput;
                    LinkedList.addFront(userInput);
                    cout << '(' << userInput << ") has been added onto the list.\n";
                    break;
                    
                    // deleting item from rear
                case 3:
                    cout << "Deleting an item from rear...\n";
                    LinkedList.deleteRear(itemBeingRemoved);
                    cout <<'(' << itemBeingRemoved << ") has been removed from the list.\n";
                    break;
                    
                    // deleting item from front
                case 4:
                    cout << "Deleting an item from front...\n";
                    LinkedList.deleteFront(itemBeingRemoved);
                    cout << '(' << itemBeingRemoved << ") has been removed from the list.\n";
                    break;
                    
                    // adding to position before i
                case 5:
                    cout << "Please enter index to add item before: ";
                    cin >> indexOfItem;
                    cout << "Please enter the number you want to add to position " << indexOfItem - 1 << ": ";
                    cin >> userInput;
                    LinkedList.addbeforeIth(indexOfItem, userInput);
                    break;
                    
                    // deleting item from ith position
                case 6:
                    cout << "Please enter index of item on list to be removed: ";
                    cin >> indexOfItem;
                    cout << "Deleting " << indexOfItem << " item from front...\n";
                    LinkedList.deleteIth(indexOfItem, itemBeingRemoved);
                    cout << "Item " << itemBeingRemoved << " of index " << indexOfItem << " has been removed from the list.\n";
                    break;
                    
                case 7:
                    cout << "Checking if list is empty...\n";
                    (LinkedList.isEmpty())? cout << "List is empty.\n": cout << "List is populated.\n";
                    break;
                    
                case 8:
                    LinkedList.displayAll();
                    break;
                    
                default:
                    break;
            }
        } catch (llist::Underflow) {
            cout << "Error: User input has caused underflow.\n";
        } catch (llist::OutOfRange) {
            cout << "Error: Out of range.\n";
        }
    }
    
    cout << "End of Program.\n";
    
    return 0;
}

int menu() {
    //choice starts with sentinel case
    int choice = -9999;
    
    cout << "\nPlease enter choice below: \n";
    cout << "1. Add an item to rear\n";
    cout << "2. Add an item to front\n";
    cout << "3. Delete an item from rear\n";
    cout << "4. Delete an item from front\n";
    cout << "5. Add item before i-th position on list\n";
    cout << "6. Delete item on i-th position of list\n";
    cout << "7. Check if list is empty\n";
    cout << "8. Display all items in the list\n";
    cout << "-9999. Exit program\n";

    cin >> choice;
    
    return choice;
}


