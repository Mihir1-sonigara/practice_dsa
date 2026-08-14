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
