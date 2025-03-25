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
    //theta(1) best: theta(1), worst: theta(1)
    current = bag.head;

    if (current != nullptr) {
        freq = current->data.second;
    }
}

void BagIterator::first() {
    //theta(1) best: theta(1), worst: theta(1)
    current = bag.head;
    freq = current->data.second;
}

void BagIterator::next() {
    //theta(1) best: theta(1), worst: theta(1)

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
    }
}

bool BagIterator::valid() const {
    //theta(1) best: theta(1), worst: theta(1)

    if (current == nullptr) {
        return false;
    }
    return true;
}

TElem BagIterator::getCurrent() const {
    //theta(1) best: theta(1), worst: theta(1)
    if (current != nullptr) {
        return current->data.first;
    }
    throw std::out_of_range("Iterator out of range");
}

int BagIterator::getFreq() const {
    //theta(1) best: theta(1), worst: theta(1)
    if (valid()) {
        return freq;
    }
    throw std::out_of_range("Iterator out of range");
}