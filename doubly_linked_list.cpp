// ========================================
// Author: Justin Wu
// File Name: doubly_linked_list.cpp
// Description: Main function to create doubly linked list
//              4 test cases included
// ========================================

// Libraries
#include <iostream>
#include <string>

// Doubly Linked List Node
class Node {
    public: 
        int value;
        Node* next = nullptr;
        Node* prev = nullptr;

        // Constructor
        Node(int val) {
            value = val;
        }

        // Deconstructor
        ~Node() {}
};

// Implementation of Doubly Linked List
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor
    DoublyLinkedList() {
        // Create dummy nodes to make it easier to remove node from beginning
        head = new Node(-1); 
        tail = new Node(-1);

        head->next = tail;
        tail->prev = head;
    }

    // Deconstructor
    ~DoublyLinkedList() {}

    // Insert value at head node
    void insertHead(int val) {
        Node* newNode = new Node(val);

        newNode->prev = head;
        newNode->next = head->next;

        head->next->prev = newNode;
        head->next = newNode;
    }

    // Remove value at head node
    void removeHead() {
        if (head->next != tail) {
            Node* deleteNode = head->next;

            head->next->next->prev = head;
            head->next = head->next->next;

            delete deleteNode;
        }
    }

    // Insert value at tail node
    void insertTail(int val) {
        Node* newNode = new Node(val);

        newNode->prev = tail->prev;
        newNode->next = tail;

        tail->prev->next = newNode;
        tail->prev = newNode;
    }

    // Remove value at tail node
    void removeTail() {
        if (tail->prev != head) {
            Node* deleteNode = tail->prev;

            tail->prev->prev->next = tail;
            tail->prev = tail->prev->prev;

            delete deleteNode;
        }
    }

    // Insert value before the index node
    // If index == length of the linked list, insert value at the tail 
    // If index > the length, do not insert value
    void insertIndex(int index, int val) {
        Node* cur = head->next;

        // Find the index
        while (cur && index > 0) {
            cur = cur->next;
            index -= 1;
        }

        if (cur && index == 0) {
            Node* newNode = new Node(val);

            newNode->next = cur;
            newNode->prev = cur->prev;

            cur->prev->next = newNode;
            cur->prev = newNode;
        }
    }

    // Remove the index node
    // If the index is valid
    void removeIndex(int index) {
        Node* cur = head->next;

        // Find the index
        while (cur && index > 0) {
            cur = cur->next;
            index -= 1;
        }

        if (cur && cur != tail && index == 0) {
            Node* deleteNode = cur;

            cur->next->prev = cur->prev;
            cur->prev->next = cur->next;

            delete deleteNode;
        }
    }

    // Get the value of the index node
    // If the index is invalid, return -1.
    int getIndex(int index) {
        Node* cur = head->next;

        // Find the index
        while (cur && index > 0) {
            cur = cur->next;
            index -= 1;
        }

        if (cur && cur != tail && index == 0) {
            return cur->value;
        }

        return -1;
    }

    // Free up each node
    void deleteLinkedList() {
        Node* cur = head;
        Node* next = nullptr;

        while (cur != nullptr) {
            next = cur->next;
            delete cur;
            cur = next;
        }
    }

    // Print out each node from head to tail 
    void traverseForward() {
        Node* cur = head->next;

        while (cur != tail) {
            std::cout << cur->value << " -> ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }

    // Print out each node from tail to head 
    void traverseBackward() {
        Node* cur = tail->prev;

        while (cur != head) {
            std::cout << cur->value << " -> ";
            cur = cur->prev;
        }
        std::cout << std::endl;
    }
};

// Main Function for testing use cases
int main()
{
    // Test Case #1 - Test insertHead, insertTail, removeHead, removeTail,
    DoublyLinkedList* test1 = new DoublyLinkedList();
    std::cout << "Test Case #1:" << std::endl;
    test1->insertHead(1);      // 1 ->
    test1->insertHead(2);      // 2 -> 1 ->
    test1->insertHead(3);      // 3 -> 2 -> 1 ->
    test1->insertTail(4);      // 3 -> 2 -> 1 -> 4 ->
    test1->insertTail(5);      // 3 -> 2 -> 1 -> 4 -> 5 ->
    test1->insertTail(6);      // 3 -> 2 -> 1 -> 4 -> 5 -> 6 ->
    test1->traverseForward();  
    test1->traverseBackward(); // 6 -> 5 -> 4 -> 1 -> 2 -> 3 ->
    std::cout << "===========================" << std::endl;


    // Test Case #2 - Test insertIndex, removeIndex, getIndex, 
    DoublyLinkedList* test2 = new DoublyLinkedList();
    std::cout << "Test Case #2:" << std::endl;
    test2->insertIndex(1, 2);                               // ->
    test2->traverseForward();                               
    test2->insertIndex(0, 4);                               // 4 ->
    test2->traverseForward();                               
    test2->insertIndex(1, 10);                              // 4 -> 10 ->
    test2->traverseForward();                               
    test2->traverseBackward();                              // 10 -> 4
    test2->insertIndex(6, 2);                               // 4 -> 10 ->
    test2->insertIndex(2, 68);                              // 4 -> 10 -> 68 ->
    test2->traverseForward();                               
    test2->removeIndex(1);                                  // 4 -> 68 ->
    printf("test2->getIndex(0): %d\n", test2->getIndex(0)); // return 4
    test2->traverseForward();                               
    test2->traverseBackward();                              // 68 -> 4
    std::cout << "===========================" << std::endl;


    // Test Case #3 - Test all functions
    DoublyLinkedList* test3 = new DoublyLinkedList();
    std::cout << "Test Case #3:" << std::endl;
    printf("test3->getIndex(0): %d\n", test3->getIndex(0));   // return -1
    test3->insertIndex(0, 5);                                 // 5 ->
    test3->insertTail(34);                                    // 5 -> 34
    test3->insertHead(78);                                    // 78 -> 5 -> 34
    printf("test3->getIndex(2): %d\n", test3->getIndex(2));   // return 34
    test3->traverseForward();  
    test3->traverseBackward();                                // 34 -> 5 -> 78
    test3->removeHead();                                      // 5 -> 34
    test3->insertIndex(1, 15);                                // 5 -> 15 -> 34
    test3->insertIndex(2, 25);                                // 5 -> 15 -> 25 -> 34
    test3->traverseForward();                                
    test3->traverseBackward();                                // 34 -> 25 -> 15 -> 5
    printf("test3->getIndex(3): %d\n", test3->getIndex(3));   // return 34
    test3->removeTail();                                      // 5 -> 15 -> 25
    printf("test3->getIndex(3): %d\n", test3->getIndex(3));   // return -1
    test3->removeIndex(20);                                   // Remove nothing
    test3->traverseForward();                                
    test3->traverseBackward();                                // 25 -> 15 -> 5
    std::cout << "===========================" << std::endl;


    // Test Case #4 - Test out of bound cases
    DoublyLinkedList* test4 = new DoublyLinkedList();
    std::cout << "Test Case #4:" << std::endl;
    test4->insertHead(9);                                     // 9 ->
    test4->traverseForward();                               
    printf("test4->getIndex(0): %d\n", test4->getIndex(0));   // return 9
    printf("test4->getIndex(89): %d\n", test4->getIndex(89)); // return -1
    test4->removeIndex(0);                                    // Remove nothing
    test4->removeIndex(2);                                    // Remove nothing
    test4->removeHead();                                      // ->t 
    test4->traverseForward();                                 
    test4->insertHead(78);                                    //78 ->
    test4->traverseForward();                                 
    test4->removeTail();                                      // ->
    printf("test4->getIndex(0): %d\n", test4->getIndex(0));   // return -1
    test4->traverseForward();                                 
    test4->traverseBackward();                                // ->
    std::cout << "===========================" << std::endl;


    // Delete Linked Lists
    test1->deleteLinkedList();
    test2->deleteLinkedList();
    test3->deleteLinkedList();
    test4->deleteLinkedList();

    delete test1;
    delete test2;
    delete test3;
    delete test4;

    return 0;
}