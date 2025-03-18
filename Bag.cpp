#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {

    head = nullptr;
    tail = nullptr;
    //next = nullptr;
    //prev = nullptr;
    //pair?

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
            //current = current->next;

            if (current == tail && current->data.first != elem) {
                Node *lastNode = new Node();
                lastNode->data = make_pair(elem, 1);
                lastNode->next = nullptr;
                lastNode->prev = current;
                tail = lastNode;
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

    BagIterator it = iterator();

    while (it.valid()) {
        if (it.getCurrent() == elem) {
            return true;
        }
        it.next();
    }
    return false;

}

int Bag::nrOccurrences(TElem elem) const {

    //int count = 0;
    BagIterator it = iterator();

    while (it.valid()) {
        if (it.getCurrent() == elem) {
            return it.current->data.second;
        }
        it.next();
    }
    return 0;

}

int Bag::size() const {

    int sizeOf = 0;
    while (iterator().getCurrent()) {
        sizeOf++;
    }
    return sizeOf;

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

