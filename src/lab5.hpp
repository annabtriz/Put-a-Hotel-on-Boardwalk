#ifndef LAB5_HPP
#define LAB5_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std; 

template <typename T>
class CircularLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* current;

public:
    CircularLinkedList() : head(nullptr), current(nullptr) {
        static bool seeded = false;
        if (!seeded) {
            srand(static_cast<unsigned>(time(nullptr)));
            seeded = true;
        }
    }

    ~CircularLinkedList() {
        if (!head) return;
        Node* temp = head->next;
        while (temp != head) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        delete head;
    }

    void append(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            head->next = head;
            current = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    T getCurrent() const {
        if (!current) throw runtime_error("The list is empty");
        return current->data;
    }

    void step() {
        if (current) current = current->next;
    }

    void stepN(int n) {
        for (int i = 0; i < n; i++) step();
    }

    int rollAndMove() {
        int dice1 = (rand() % 6) + 1;
        int dice2 = (rand() % 6) + 1;
        int roll = dice1 + dice2;
        stepN(roll);
        return roll;
    }
};

#endif