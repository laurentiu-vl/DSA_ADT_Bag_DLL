#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
#include <exception>
using namespace std;


Bag::Bag() {

    head = nullptr;
    tail = nullptr;

}

void Bag::add(TElem elem) {

    //case Bag is with no elems
    if (head == nullptr) {
        Node *firstNode = new Node();
        firstNode->data = make_pair(elem, 1);
        firstNode->next = nullptr;
        firstNode->prev = nullptr;
        head = firstNode;
        tail = firstNode;
    }
    else {
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
    //TODO - Implementation
    return false;
}


bool Bag::search(TElem elem) const {

    Node *current = head;

    while (current != nullptr) {
        if (current->data.first == elem) {
            return true;
        }
        current = current->next;
    }
    return false;

    // BagIterator it = iterator();
    //
    // while (it.valid()) {
    //     if (it.getCurrent() == elem) {
    //         return true;
    //     }
    //     it.next();
    // }
    // return false;

}

int Bag::nrOccurrences(TElem elem) const {

    Node *current = head;

    while (current != nullptr) {
        if (current->data.first == elem) {
            return current->data.second;
        }
        current = current->next;
    }
    return 0;

    // BagIterator it = iterator();
    //
    // while (it.valid()) {
    //     if (it.getCurrent() == elem) {
    //         return it.current->data.second;
    //     }
    //     it.next();
    // }
    // return 0;

}

int Bag::size() const {

    int sizeOf = 0;
    Node *current = head;

    while (current != nullptr) {
        sizeOf += current->data.second;
        current = current->next;
    }
    return sizeOf;

    // try {
    //     while (iterator().getCurrent()) { //nu se actualizeaza current
    //         //sizeOf++;
    //         sizeOf += iterator().current->data.second;
    //         iterator().next();
    //         cout << sizeOf;
    //     }
    // }
    // catch (exception& e) {
    //     return sizeOf;
    // }
    // return sizeOf;

}

bool Bag::isEmpty() const {

    if (head == nullptr) {
        return true;
    }
    return false;
}

BagIterator Bag::iterator() const {

    return BagIterator(*this);

}

Bag::~Bag() {
    //TODO - Implementation
}

