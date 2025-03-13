#include <exception>
#include "BagIterator.h"

#include <exception>
#include <assert.h>
#include <stdexcept>

#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
    //TODO - Implementation

    current = bag.head;
}

void BagIterator::first() {
    //TODO - Implementation

    current = bag.head;
}


void BagIterator::next() {
    //TODO - Implementation

    if (!valid()) {
        throw std::out_of_range("Iterator out of range");
    }

    if (current->next == nullptr) {
        current = nullptr; //e ok?
    }
    else {
        current = current->next;
    }

}


bool BagIterator::valid() const {
    //TODO - Implementation

    return current != nullptr; //?????????????
}



TElem BagIterator::getCurrent() const
{
    //TODO - Implementation

    if (!valid()) {
        throw std::out_of_range("Iterator out of range");
    }
    return current->data.first; //e ok doar elementul TElem? sau trebuie si frecventa? TElem BagIterator...

    //return NULL_TELEM
}
