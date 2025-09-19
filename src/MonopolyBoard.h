//
// Created by Steph on 9/16/2025.
//
#ifndef MONOPOLYBOARD_H
#define MONOPOLYBOARD_H
#include <iostream>
#include <string>
#include <cstdlib>

template <typename T>
class CircularlyLinkedList {
  private:
    // nested Node class omitted here; identical to the SinglyLinkedList Node class
    class RollDice {
    private:
        int dice1 = 0;
        int dice2 = 0;
    public:
        int roll() {
            dice1 = (rand() % 6) + 1;
            dice2 = (rand() % 6) + 1;
            return dice1 + dice2;
        }
    };

    class Node {
        public:
        T elem;
        Node *next;

        Node(const T &element, Node *nxt = nullptr) : elem(element), next(nxt) {}
    };
    // instance variables of the CircularlyLinkedList
    int sz{0};                                           // number of entries in the list
    Node* tail{nullptr};                                 // the node storing last element of the list

  public:
    CircularlyLinkedList() {} // Constructs an empty list

    // ---------- access functions ----------
    int size() const { return sz; }                      // Returns the number of elements stored
    bool empty() const { return sz == 0; }               // Tests whether the list is empty.
    T& front() { return tail->next->elem; }              // Live reference to first element
    const T& front() const { return tail->next->elem; }  // Const reference to first element
    T& back() { return tail->elem; }                     // Live reference to last element
    const T& back() const { return tail->elem; }         // Const reference to last element

    // ---------- update functions ----------

    // Inserts element at the beginning of the list
    void push_front(const T& elem) {
        if (sz == 0) {
            tail = new Node(elem);
            tail->next = tail;                           // link to itself circularly
        } else {
            tail->next = new Node(elem, tail->next);     // splice new node after the tail
        }
        sz++;
    }

    // Inserts element at the end of the list
    void push_back(const T& elem) {
        push_front(elem);                                // start by inserting at front of list
        tail = tail->next;                               // then rotate newest node to be tail
    }

    // Removes the first element of the list
    void pop_front() {
        Node* head = tail->next;
        if (head == tail)
            tail = nullptr;                              // must be the only node left
        else
            tail->next = head->next;
        delete head;
        sz--;
    }

    // Rotates the first element to the back of the list
    void step() {
        if (tail != nullptr)                             // if empty, do nothing
            tail = tail->next;                           // otherwise, the old head becomes the new tail
    }

    void currentNode() {
        std::cout << tail->elem << std::endl;
    }

    void print() {
        if (!tail) {
            std::cout << "Empty List" << std::endl;
        }

        Node* current = tail->next;

        do {
            std::cout << current->elem << std::endl;
            current = current->next;
        } while (current != tail->next);
    }

    void roll() {
        RollDice dice;
        int steps = dice.roll();
        std::cout << steps << std::endl;

        for (int i = 0; i < steps; i++) {
            step();
        }
    }

    void clear() {
        while (sz > 0 ) {
            pop_front();
        }
    }

    ~CircularlyLinkedList() { clear(); }
};



#endif //MONOPOLYBOARD_H
