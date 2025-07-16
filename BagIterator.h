#include "Bag.h"

class BagIterator
{
    //DO NOT CHANGE THIS PART
    friend class Bag;

private:
    //TODO - Representation
    /* ADT Bag – repräsentiert mithilfe einer DLL von Paaren der Form (Element, Frequenz).
    */

    const Bag& bag;

    Bag::Node *current;
    int freq;

    BagIterator(const Bag& c);
public:
    void first();
    void next();
    TElem getCurrent() const;
    bool valid() const;

    int getFreq() const;
};
