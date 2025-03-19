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

    if (head == nullptr) { //if no elem in Bag
        return false;
    }

    Node *current = head;
    bool elemFound = false;
    int Found = 0;

    while (current != nullptr) {
        //case only 1 elem, elem=head=tail, and found
        if (current == head && current == tail && current->data.first == elem) {
            if (current->data.second > 1) {
                current->data.second--;
            }
            if (current->data.second == 1) {
                current = nullptr;
            }
            elemFound = true;
        }

        //case only 2 elem, head and tail, and found
        if (current == head && current->next == tail) {
            if (current->data.first == elem) {
                //if head/current = elem and freq > 1, just -- the freq
                if (current->data.second > 1) {
                    current->data.second--;
                }
                if (current->data.second == 1) { //if current = elem and freq = 1, then is deleted and tail becomes head
                    //current = current->next;
                    current->next->prev = nullptr;
                    current->next->next == nullptr;
                    //tail = current->next;
                    head = current->next;
                }
                elemFound = true;
            }
            if (current->next->data.first == elem) { //if current->next/tail = elem and freq > 1, just -- the freq
                if (current->next->data.second > 1) {
                    current->next->data.second--;
                }
                if (current->next->data.second == 1) { //if curr->next/tail = elem and freq = 1, tail is deleted, curr becomes also tail
                    current->next = nullptr;
                    tail = current;
                }
                elemFound = true;
            }
        }

        if (elemFound == true) {
            return true;
        }

        //general case

        //case current = tail, but it is not head // elem is tail
        if (current == tail && current->data.first == elem) {
            if (current->data.second > 1) {
                current->data.second--;
                elemFound = true;
            }
            if (current->data.second == 1) {
                tail = current->prev;
                current = nullptr;
            }
        }

        if (elemFound == true) {
            return true;
        }
        return false;
    }
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

