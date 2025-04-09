#pragma once
//DO NOT INCLUDE BAGITERATOR

//DO NOT CHANGE THIS PART
#define NULL_TELEM -111111;
#include <utility>
typedef int TElem;
class BagIterator;
class Bag {

	struct Node {
		std::pair<TElem, int> data; //elem, frecv
		Node *next;
		Node *prev;
	};

	//4. ADT Bag – repräsentiert mithilfe
	//einer DLL von Paaren der Form (Element, Frequenz).

	//iterator care adauga element pe pozitia curenta; primeste element si il adauga

private:

	Node *head;
	Node *tail;
	//int sizeOfDistinctElement = 0; //for using at remove

	//DO NOT CHANGE THIS PART
	friend class BagIterator;
public:
	//constructor
	Bag();

	//adds an element to the bag
	void add(TElem e);

	//removes one occurence of an element from a bag
	//returns true if an element was removed,
	//false otherwise (if e was not part of the bag)
	bool remove(TElem e);

	//checks if an element appearch is the bag
	bool search(TElem e) const;

	//returns the number of occurrences for an element in the bag
	int nrOccurrences(TElem e) const;

	//returns the number of elements from the bag
	int size() const;

	//returns an iterator for this bag
	BagIterator iterator() const;

	//checks if the bag is empty
	bool isEmpty() const;

	//destructor
	~Bag();

	//returns the number of distinct elements in the Bag
	//int sizeOfDistinctElemsFunc() const;
};