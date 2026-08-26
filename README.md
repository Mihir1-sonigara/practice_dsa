# practice_dsa
# Singly Linked List Operations in C++

A menu-driven C++ program that demonstrates the implementation of a **Singly Linked List** and various operations that can be performed on it.

The program uses a `node` structure containing a data field and a pointer to the next node.

## 📌 Features

This project supports the following linked-list operations:

1. Create a Linked List
2. Add Node at the Beginning
3. Add Node at the End
4. Delete Node from the Beginning
5. Delete Node from the End
6. Display Linked List
7. Search Element by Value
8. Add Node After a Specific Node
9. Add Node Before a Specific Node
10. Delete Node by Specific Value
11. Delete Node by Position
12. Reverse the Linked List
13. Update Node by Position
14. Sort Linked List in Ascending Order
15. Count Total Nodes
16. Find Maximum Element
17. Find Minimum Element
18. Find Middle Node
19. Exit

These operations are exposed through the program's main menu.

## 🧠 Concepts Used

* Singly Linked List
* Dynamic Memory Allocation
* Structures in C++
* Pointers
* Traversal
* Insertion and deletion
* Searching
* Sorting
* Linked List reversal
* Fast and slow pointer technique
* Menu-driven programming

## 🏗️ Node Structure

Each node contains:

```cpp
struct node
{
    int data;
    struct node *next;
};
```

The `data` field stores the element, while `next` stores the address of the next node.

## 🔧 Implementation

The program maintains two important pointers:

* `first` → points to the first node
* `last` → points to the last node

New nodes are dynamically allocated using `new`.

## 🔄 Reverse Linked List

The reverse operation uses three pointers:

```text
prev
current
next
```

The links between nodes are changed so that the last node becomes the first node.

## 🎯 Find Middle Node

The program uses the **slow and fast pointer technique**:

* `mid` moves one node at a time.
* `midm` moves two nodes at a time.
* When the fast pointer reaches the end, the slow pointer is at the middle.

## 📊 Sorting

The linked list is sorted in ascending order by comparing node values and swapping their `data` values.

## ▶️ How to Run

### 1. Clone the Repository

```bash
git clone <your-repository-url>
cd <repository-folder>
```

### 2. Compile

Using `g++`:

```bash
g++ "Pasted code.cpp" -o linkedlist
```

### 3. Run

Linux/macOS:

```bash
./linkedlist
```

Windows:

```bash
linkedlist.exe
```

## 💻 Example Menu

```text
=============================================================MAIN MENU==========================================================
1.Create List
2.Add At The Beginning
3.Add At The Last
4.Delete At Beginning
5.Delete At The End
6.Display List
7.Search Element By Value
8.Add Element After The Specific Node
9.Add Element Before The Specific Node
10.Delete At The Specific Element
11.Delete At The Specific Position
12.Display Reverse Of The Singly Linkedlist
13.Update Node By User
14.Sort list at Ascending Order
15.Count Total Node in Linked List
16.Find Maximum Element IN LinkedList
17.Find Minimum Element IN LinkedList
18.Find Middle Node Of The LinkedList
19.Exit
```

## 📁 Project Structure

```text
Singly-Linked-List/
│
├── linkedlist.cpp
└── README.md
```

## 🎓 Purpose

This project is created for practicing **Data Structures and Algorithms in C++**, specifically the implementation and manipulation of a singly linked list.

It is suitable for beginners learning:

* Pointers
* Dynamic memory
* Structures
* Linked Lists
* Basic algorithms

## 🚀 Future Improvements

Possible improvements to the project:

* Add proper input validation
* Handle empty-list cases consistently
* Fix edge cases in deletion operations
* Maintain the `last` pointer after every deletion
* Improve maximum/minimum element logic
* Separate the linked-list implementation into a class
* Add comments and better function naming
* Add a graphical or cleaner command-line interface

## 👨‍💻 Author

**Mihir Sonigara**

### Language

**C++**

### Topic

**Data Structures — Singly Linked List**
#cir.cpp
## 🔧 Implementation

The program uses two important pointers:

* `first` → points to the first node of the circular linked list
* `last` → points to the last node of the circular linked list
* `last->next` → always points back to `first`

The node structure is:

```cpp
struct Node
{
    int data;
    Node *next;
};
```

The list is initialized using:

```cpp
Node *first = nullptr;
Node *last = nullptr;
```

For the first node:

```cpp
first = newNode;
last = newNode;
last->next = first;
```

For subsequent nodes, the new node is connected after `last`, and `last` is updated.

```text
        ┌──────────────────────────────┐
        ↓                              │
[first] [10] → [20] → [30] → [40]      │
                                ↑       │
                               last ────┘

last->next → first
```

This maintains the circular structure of the linked list.

## 🔗 Circular Linked List Structure

In a Circular Singly Linked List, the last node does not point to `nullptr`.

Instead:

```text
last->next = first
```

Example:

```text
first
  ↓
[10] → [20] → [30] → [40]
                    ↑
                   last
                    │
                    └──────→ first
```

During traversal, the program stops when the current node becomes equal to `first` again.

```cpp
Node *current = first;

do
{
    cout << current->data << " ";
    current = current->next;
} while (current != first);
```

## ➕ Insertion Operations

### Insert at Beginning

A new node is inserted before the current `first`.

After insertion:

```text
first
  ↓
[5] → [10] → [20] → [30]
                    ↑
                   last
                    │
                    └────→ first
```

The `first` pointer is updated to the new node, and:

```cpp
last->next = first;
```

keeps the list circular.

### Insert at End

A new node is inserted after the current `last`.

The new node becomes the new `last`, and:

```cpp
last->next = first;
```

is maintained.

### Insert at Position

The program accepts a **1-based position**, traverses to the node before that position, and inserts the new node by changing the `next` pointers.

## ➖ Deletion Operations

### Delete at Beginning

The node pointed to by `first` is deleted.

For a list containing more than one node:

```cpp
first = first->next;
last->next = first;
```

If only one node exists, both pointers become:

```cpp
first = nullptr;
last = nullptr;
```

### Delete at End

The program traverses the circular list to find the node immediately before `last`.

After deleting the old last node:

```cpp
last = previous;
last->next = first;
```

This maintains the circular connection.

### Delete at Position

The program uses `previous` and `current` pointers to locate the node at the specified position.

The previous node is then connected directly to the next node.

## 🔄 Reverse Linked List

The reverse operation changes the direction of the `next` pointers.

It uses three pointers:

```text
previous
current
nextNode
```

After reversing, the old `first` becomes the new `last`, and the old `last` becomes the new `first`.

The circular relationship is maintained:

```cpp
last->next = first;
```

## 🔍 Search Element

The search operation traverses the circular linked list starting from `first`.

The traversal continues until:

```cpp
current == first
```

This prevents the program from traversing the circular list indefinitely.

## 🔢 Count Total Nodes

The program starts traversal from `first` and counts each node until it reaches `first` again.

```text
first → Node → Node → Node → last
  ↑                         │
  └─────────────────────────┘
```

## 📈 Find Maximum Element

The first node's value is initially considered the maximum.

The remaining nodes are traversed from `first` until the traversal reaches `first` again.

## 📉 Find Minimum Element

The first node's value is initially considered the minimum.

The program then compares the remaining node values to find the minimum.

## 📊 Calculate Average

The program calculates:

```text
Sum = sum of all node values
Count = total number of nodes

Average = Sum / Count
```

Traversal starts from `first` and stops when the current node becomes `first` again.

## 🔃 Sorting

The circular linked list is sorted in ascending order by comparing the `data` values of nodes.

The node connections are not changed. Instead, the `data` values are swapped.

```cpp
int temp = i->data;
i->data = j->data;
j->data = temp;
```

## 🗑️ Clear Entire List

The `clearList()` function deletes all dynamically allocated nodes.

After clearing the list:

```cpp
first = nullptr;
last = nullptr;
```

The list is then empty.

## 🔁 Find Duplicate Elements

The program compares the values of different nodes to find duplicate elements.

If a duplicate is found, its value is displayed.

## 🔢 Count Duplicate Elements

The program counts duplicate values by comparing each node with the remaining nodes in the circular linked list.

## ✅ Check if List is Empty

The list is considered empty when:

```cpp
first == nullptr
```

Otherwise, the list contains at least one node.

## 📁 Project Structure

```text
Circular-Singly-Linked-List/
│
├── cir.cpp
└── README.md
```

## 🎓 Purpose

This project is created for practicing **Data Structures and Algorithms in C++**, specifically the implementation and manipulation of a **Circular Singly Linked List**.

It is suitable for beginners learning:

* Pointers
* Dynamic memory allocation
* Structures
* Circular linked lists
* `first` and `last` pointer management
* Traversal
* Insertion
* Deletion
* Searching
* Sorting
* Reversing
* Memory management

## 👨‍💻 Author

**Mihir Sonigara**

## Language

**C++**

## Topic

**Data Structures & Algorithms — Circular Singly Linked List**
