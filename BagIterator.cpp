#include <exception>
#include "BagIterator.h"

#include <exception>
#include <assert.h>
#include <iostream>
#include <ostream>
#include <stdexcept>

#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag &c): bag(c) {
    current = bag.head;

    if (current != nullptr) {
        freq = current->data.second;
    }

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

    if (!valid()) {
        throw std::out_of_range("Iterator out of range");
    }

    freq--;
    //cout << "Frequency is " << current->data.second - freq << " for element: " << current->data.first << endl;

    if (freq == 0) {
        current = current->next;
        if (current != nullptr) {
            freq = current->data.second;
        }




        // if (current->next != nullptr) {
        //     freq = current->data.second;
        // }
    }
    // else {
    //     freq--;
    // }

}

bool BagIterator::valid() const {
    //return current != nullptr;
    if (current == nullptr) {
        return false;
    }
    // if (current->next == nullptr) {
    //     return false;
    // }
    return true;
}

TElem BagIterator::getCurrent() const {
    if (current != nullptr) {
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
