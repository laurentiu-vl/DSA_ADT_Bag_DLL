#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
#include <exception>
using namespace std;

Bag::Bag() {
    //theta(1) best: theta(1), worst: theta(1)
    head = nullptr;
    tail = nullptr;
}

void Bag::add(TElem elem) {
    //O(n) best: theta(1), worst: theta(n)
    //case Bag is with no elems
    //cout << "Adding element " << elem << endl;
    if (head == nullptr) {
        Node *firstNode = new Node();
        firstNode->data = make_pair(elem, 1);
        firstNode->next = nullptr;
        firstNode->prev = nullptr;
        head = firstNode;
        tail = firstNode;
    } else {
        //case Bag contains the elem or not
        Node *current = head;
        while (current != nullptr) {
            if (current->data.first == elem) {
                current->data.second++;
                break;
            }

            if (current == tail && current->data.first != elem) {
                Node *nodeToBeInsertedLast = new Node();
                current->next = nodeToBeInsertedLast;
                nodeToBeInsertedLast->data = make_pair(elem, 1);
                nodeToBeInsertedLast->next = nullptr;
                nodeToBeInsertedLast->prev = current;
                tail = nodeToBeInsertedLast;
                break;
            }
            current = current->next;
        }
    }
}

bool Bag::remove(TElem elem) {
    //O(n) best: theta(1), worst: theta(n)

    Node *current = head;
    if (head == nullptr) {
        return false;
    }

    while (current != nullptr) {
        if (current->data.first == elem) {
            // elem found
            if (current->data.second > 1) {
                current->data.second--;
            } else if (current->data.second == 1) {
                if (current->prev != nullptr) {
                    //maintain the connection prev
                    current->prev->next = current->next;
                } else {
                    head = current->next; //if current is head ->update the head being the curr->next
                }
                if (current->next != nullptr) {
                    //maintain the connection next
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev; //if current is tail ->update the tail being the curr->prev
                }

                delete current;
            }
            return true;
        }
        current = current->next;
    }
    return false;
}

bool Bag::search(TElem elem) const {
    //O(n) best: theta(1), worst: theta(n)
    Node *current = head;

    while (current != nullptr) {
        if (current->data.first == elem) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int Bag::nrOccurrences(TElem elem) const {
    //O(n) best: theta(1), worst: theta(n)
    Node *current = head;

    while (current != nullptr) {
        if (current->data.first == elem) {
            return current->data.second;
        }
        current = current->next;
    }
    return 0;
}

int Bag::size() const {
    //theta(n) best: theta(n), worst: theta(n)
    int sizeOf = 0;
    //int sizeOfDistinctElement = 0;
    Node *current = head;

    while (current != nullptr) {
        sizeOf += current->data.second;
        current = current->next;
        //sizeOfDistinctElement += 1;
    }
    return sizeOf;
}

bool Bag::isEmpty() const {
    //theta(1) best: theta(1), worst: theta(1)
    if (head == nullptr) {
        return true;
    }
    return false;
}

BagIterator Bag::iterator() const {
    //theta(1) best: theta(1), worst: theta(1)
    return BagIterator(*this);
}

Bag::~Bag() {
    //theta(n) best: theta(1), worst: theta(n)
    Node *current = head;

    while (current != nullptr) {
        Node *next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
}