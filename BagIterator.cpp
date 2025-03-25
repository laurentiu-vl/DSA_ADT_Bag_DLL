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
        currentFreq = freq;
    }
}

void BagIterator::first() {
    current = bag.head;
    currentFreq = freq; //de verificat
}

void BagIterator::next() {

    if (!valid()) {
        throw std::out_of_range("Iterator out of range");
    }
    currentFreq--;
    //cout << "Frequency is " << current->data.second - freq << " for element: " << current->data.first << endl;

    if (currentFreq == 0) {
        current = current->next;
        if (current != nullptr) {
            currentFreq = current->data.second;
        }
    }

    // freq--;
    // //cout << "Frequency is " << current->data.second - freq << " for element: " << current->data.first << endl;
    //
    // if (freq == 0) {
    //     current = current->next;
    //     if (current != nullptr) {
    //         freq = current->data.second;
    //     }
    // }
}

bool BagIterator::valid() const {

    if (current == nullptr) {
        return false;
    }
    return true;
}

TElem BagIterator::getCurrent() const {
    if (current != nullptr) {
        return current->data.first;
    }
    throw std::out_of_range("Iterator out of range");
}

int BagIterator::getFreq() const {
    if (valid()) {
        return freq;
    }
    throw std::out_of_range("Iterator out of range");
}
