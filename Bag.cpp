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
    //TODO - Implementation
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
}

BagIterator Bag::iterator() const {

    return BagIterator(*this);
}


Bag::~Bag() {
    //TODO - Implementation
}

