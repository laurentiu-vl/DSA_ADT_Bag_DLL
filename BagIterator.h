#include "Bag.h"

class BagIterator
{
    //DO NOT CHANGE THIS PART
    friend class Bag;

private:
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

    //iterator care adauga element pe pozitia curenta; primeste element si il adauga
    //imi faci loc si adaug (nu getcurrent)
    void addAtCurrent(const TElem& e);

};
