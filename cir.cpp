// Circular Singly Linked List - implemented using a menu-driven program.
// The last node's "next" points back to the first node instead of nullptr.
// head -> first node, tail -> last node (tail->next is always head).
 
#include <iostream>
using namespace std;
 
struct Node
{
    int data;
    Node *next;
};
 
Node *head = nullptr;
Node *tail = nullptr;
 


 
// Creates the list by taking size and values from the user
void createList()
{
    int size;
    cout << "Enter the number of nodes to create: ";
    cin >> size;
 
    for (int i = 1; i <= size; ++i)
    {
        int value;
        cout << "Enter value for node " << i << ": ";
        cin >> value;
 
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
 
        if (head == nullptr)   // first node of the list
        {
            head = newNode;
            tail = newNode;
            tail->next = head;
        }
        else                     // add after tail
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }
}
 
// Prints all values starting from head
void displayList()
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
 
    Node *current = head;
    do
    {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}
 
// Inserts a new node before head
void insertAtBeginning()
{
    int value;
    cout << "Enter value: ";
    cin >> value;
 
    Node *newNode = new Node;
    newNode->data = value;
 
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        tail->next = head;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        tail->next = head;   // tail should always point to the current head
    }
}
 
// Inserts a new node after tail
void insertAtEnd()
{
    int value;
    cout << "Enter value: ";
    cin >> value;
 
    Node *newNode = new Node;
    newNode->data = value;
 
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        tail->next = head;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
}
 
// Inserts a new node at a given position (1-based)
void insertAtPosition()
{
    int value, position;
    cout << "Enter value: ";
    cin >> value;
    cout << "Enter position: ";
    cin >> position;
 
    if (position < 1)
    {
        cout << "Invalid position." << endl;
        return;
    }
 
    if (head == nullptr)
    {
        if (position == 1)
        {
            Node *newNode = new Node;
            newNode->data = value;
            head = newNode;
            tail = newNode;
            tail->next = head;
        }
        else
        {
            cout << "Invalid position: list is empty." << endl;
        }
        return;
    }
 
    if (position == 1)
    {
        insertAtBeginning();
        return;
    }
 
    // move to the node just before the given position
    Node *previous = head;
    for (int i = 1; i < position - 1; ++i)
    {
        previous = previous->next;
        if (previous == head)   // went all the way around, position too big
        {
            cout << "Invalid position." << endl;
            return;
        }
    }
 
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = previous->next;
    previous->next = newNode;
 
    if (previous == tail)   // inserted after the last node
    {
        tail = newNode;
    }
}
 
// Deletes the head node
void deleteAtBeginning()
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
 
    Node *nodeToDelete = head;
 
    if (head == tail)   // only one node left
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = head->next;
        tail->next = head;
    }
 
    delete nodeToDelete;
}
 
// Deletes the tail node
void deleteAtEnd()
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
 
    if (head == tail)   // only one node left
    {
        delete tail;
        head = nullptr;
        tail = nullptr;
        return;
    }
 
    Node *current = head;
    while (current->next != tail)
    {
        current = current->next;
    }
 
    current->next = head;
    delete tail;
    tail = current;
}
 
// Deletes the node at a given position (1-based)
void deleteAtPosition()
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
 
    int position;
    cout << "Enter position: ";
    cin >> position;
 
    if (position == 1)
    {
        deleteAtBeginning();
        return;
    }
 
    Node *previous = head;
    Node *current = head->next;
    int count = 2;
 
    while (current != head && count < position)
    {
        previous = current;
        current = current->next;
        ++count;
    }
 
    if (current == head)   // position does not exist
    {
        cout << "Invalid position." << endl;
        return;
    }
 
    previous->next = current->next;
    if (current == tail)
    {
        tail = previous;
    }
    delete current;
}
 
// Updates the value at a given position (1-based)
void updateElement()
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
 
    int position;
    cout << "Enter position to update: ";
    cin >> position;
 
    int newValue;
    cout << "Enter new value: ";
    cin >> newValue;
 
    Node *current = head;
    int count = 1;
    while (count < position && current->next != head)
    {
        current = current->next;
        ++count;
    }
 
    if (count != position)
    {
        cout << "Invalid position." << endl;
        return;
    }
 
    current->data = newValue;
    cout << "Node updated successfully." << endl;
}
 
// Searches for a value and prints its position(s)
void searchElement()
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
 
    int value;
    cout << "Enter value to search: ";
    cin >> value;
 
    Node *current = head;
    int position = 1;
    bool found = false;
 
    do
    {
        if (current->data == value)
        {
            cout << "Value found at position " << position << endl;
            found = true;
        }
        current = current->next;
        ++position;
    } while (current != head);
 
    if (!found)
    {
        cout << "Value not found in the list." << endl;
    }
}
 
// Counts total number of nodes
void countNodes()
{
    if (head == nullptr)
    {
        cout << "List is empty. Total nodes = 0" << endl;
        return;
    }
 
    int total = 0;
    Node *current = head;
    do
    {
        ++total;
        current = current->next;
    } while (current != head);
 
    cout << "Total nodes = " << total << endl;
}
 
// Reverses the list by flipping every node's next pointer
void reverseList()
{
    if (head == nullptr || head == tail)
    {
        cout << "List reversed successfully." << endl;
        return;
    }
 
    Node *previous = tail;
    Node *current = head;
    Node *nextNode;
 
    do
    {
        nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    } while (current != head);
 
    Node *oldHead = head;
    head = tail;
    tail = oldHead;
 
    cout << "List reversed successfully." << endl;
}
 
// Finds the maximum value in the list
void findMaximum()
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
 
    int maxValue = head->data;
    Node *current = head->next;
    while (current != head)
    {
        if (current->data > maxValue)
        {
            maxValue = current->data;
        }
        current = current->next;
    }
 
    cout << "Maximum element = " << maxValue << endl;
}
 
// Finds the minimum value in the list
void findMinimum()
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
 
    int minValue = head->data;
    Node *current = head->next;
    while (current != head)
    {
        if (current->data < minValue)
        {
            minValue = current->data;
        }
        current = current->next;
    }
 
    cout << "Minimum element = " << minValue << endl;
}
 
// Calculates sum and average of all elements
void calculateAverage()
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
 
    int sum = 0, count = 0;
    Node *current = head;
    do
    {
        sum += current->data;
        ++count;
        current = current->next;
    } while (current != head);
 
    cout << "Sum of all elements = " << sum << endl;
    cout << "Average of all elements = "
         << static_cast<double>(sum) / count << endl;
}
 
// Sorts the list in ascending order (simple comparison sort)
void sortList()
{
    if (head == nullptr || head == tail)
    {
        cout << "List sorted successfully." << endl;
        return;
    }
 
    Node *i = head;
    do
    {
        Node *j = i->next;
        while (j != head)
        {
            if (i->data > j->data)
            {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    } while (i != head);
 
    cout << "List sorted successfully." << endl;
}
 
// Deletes every node and empties the list
void clearList()
{
    if (head == nullptr)
    {
        cout << "List is already empty." << endl;
        return;
    }
 
    Node *current = head;
    do
    {
        Node *nodeToDelete = current;
        current = current->next;
        delete nodeToDelete;
    } while (current != head);
 
    head = nullptr;
    tail = nullptr;
    cout << "List cleared successfully." << endl;
}
 
// Prints values that appear more than once
void findDuplicates()
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
 
    bool found = false;
    Node *i = head;
    do
    {
        Node *j = i->next;
        while (j != head)
        {
            if (i->data == j->data)
            {
                cout << "Duplicate element found: " << i->data << endl;
                found = true;
                break;
            }
            j = j->next;
        }
        i = i->next;
    } while (i != head);
 
    if (!found)
    {
        cout << "List does not contain duplicate elements." << endl;
    }
}
 
// Counts how many duplicate values exist
void countDuplicates()
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
 
    bool found = false;
    int duplicateCount = 0;
    Node *i = head;
    do
    {
        Node *j = i->next;
        while (j != head)
        {
            if (i->data == j->data)
            {
                ++duplicateCount;
                found = true;
                break;
            }
            j = j->next;
        }
        i = i->next;
    } while (i != head);
 
    cout << "Total duplicate elements = " << duplicateCount << endl;
    if (!found)
    {
        cout << "List does not contain duplicate elements." << endl;
    }
}
 
// Checks whether the list is empty
void isListEmpty()
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
    }
    else
    {
        cout << "List is not empty." << endl;
    }
}
 
// Displays the main menu
void displayMenu()
{
    cout << "=====================================================\n";
    cout << "               CIRCULAR LINKED LIST MENU              \n";
    cout << "=====================================================\n";
    cout << " 1.  Create Circular Linked List\n";
    cout << " 2.  Display Circular Linked List\n";
    cout << " 3.  Insert At Beginning\n";
    cout << " 4.  Insert At End\n";
    cout << " 5.  Insert At Position\n";
    cout << " 6.  Delete At Beginning\n";
    cout << " 7.  Delete At End\n";
    cout << " 8.  Delete At Position\n";
    cout << " 9.  Update An Element\n";
    cout << "10.  Search For An Element\n";
    cout << "11.  Count Total Nodes\n";
    cout << "12.  Reverse The List\n";
    cout << "13.  Find Maximum Element\n";
    cout << "14.  Find Minimum Element\n";
    cout << "15.  Calculate Average Of All Elements\n";
    cout << "16.  Sort The List\n";
    cout << "17.  Clear The Entire List\n";
    cout << "18.  Find Duplicate Elements\n";
    cout << "19.  Count Duplicate Elements\n";
    cout << "20.  Check If List Is Empty\n";
    cout << "21.  Exit\n";
    cout << "=====================================================\n";
    cout << "Enter your choice: ";
}
 
int main()
{
    int choice;
 
    do
    {
        displayMenu();
        cin >> choice;
 
        switch (choice)
        {
            case 1: 
                  createList();   
                  break;
            case 2: 
                displayList();
                break;
            case 3:
                insertAtBeginning();  
                break;
            case 4:
                insertAtEnd();       
                break;
            case 5: 
                insertAtPosition();  
                break;
            case 6: 
                deleteAtBeginning(); 
                break;
            case 7:
                deleteAtEnd();
                break;
            case 8:
                deleteAtPosition();
                break;
            case 9: 
                updateElement();  
                break;
            case 10: 
                searchElement();
                break;
            case 11:   
                countNodes(); 
                break;
            case 12:
                reverseList();   
                break;
            case 13: 
                findMaximum();
                break;
            case 14: 
               findMinimum();
               break;
            case 15: 
               calculateAverage();   
               break;
            case 16: 
                sortList();           
                break;
            case 17: 
                clearList();          
                break;
            case 18: 
                findDuplicates();     
                break;
            case 19: 
                countDuplicates();    
                break;
            case 20: 
                 isListEmpty(); 
                 break;
            case 21: 
                 cout << "Exiting program. Goodbye!" << endl;
                 break;
            default:
              cout << "Invalid choice. Please try again." << endl;
        }
 
    } while (choice != 21);
 
    clearList();   // free remaining nodes before exiting
    return 0;
}
 