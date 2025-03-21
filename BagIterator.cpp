#include <exception>
#include "BagIterator.h"

#include <exception>
#include <assert.h>
#include <stdexcept>

#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag &c): bag(c) {
    current = bag.head;
    // if (size()) {
    //
    // }
}

void BagIterator::first() {
    current = bag.head;
}

void BagIterator::next() {
    // if (!valid()) {
    //     throw std::out_of_range("Iterator out of range");
    // }
    // if (current->next == nullptr) {
    //     current = nullptr; //e ok?
    // } else {
    //
    //     current = current->next;
    // }

}

bool BagIterator::valid() const {
    //return current != nullptr;
    if (current == nullptr) {
        return false;
    }
    return true;
}

TElem BagIterator::getCurrent() const {
    if (valid()) {
        return current->data.first;
    }
    throw std::out_of_range("Iterator out of range");

    // if (!valid()) {
    //     throw std::out_of_range("Iterator out of range");
    // }
    // return current->data.first; //pt ca TElem e declarat doar ca si element typedef .h
    //&& current->data.second; //e ok doar elementul TElem? sau trebuie si frecventa? TElem BagIterator...
}

int BagIterator::getFreq() const {
    if (valid()) {
        return freq;
    }
    throw std::out_of_range("Iterator out of range");
}
