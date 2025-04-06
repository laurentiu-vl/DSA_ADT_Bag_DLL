#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
#include <exception>
using namespace std;

Bag::Bag() {
    //theta(1) best: theta(1), worst: theta(1)
    head = nullptr;
    tail = nullptr;
}

void Bag::add(TElem elem) {
    //O(n) best: theta(1), worst: theta(n)
    //case Bag is with no elems
    //cout << "Adding element " << elem << endl;
    if (head == nullptr) {
        Node *firstNode = new Node();
        firstNode->data = make_pair(elem, 1);
        firstNode->next = nullptr;
        firstNode->prev = nullptr;
        head = firstNode;
        tail = firstNode;
    } else {
        //case Bag contains the elem or not
        Node *current = head;
        while (current != nullptr) {
            if (current->data.first == elem) {
                current->data.second++;
                break;
            }

            if (current == tail && current->data.first != elem) {
                Node *nodeToBeInsertedLast = new Node();
                current->next = nodeToBeInsertedLast;
                nodeToBeInsertedLast->data = make_pair(elem, 1);
                nodeToBeInsertedLast->next = nullptr;
                nodeToBeInsertedLast->prev = current;
                tail = nodeToBeInsertedLast;
                break;
            }
            current = current->next;
        }
    }
}

bool Bag::remove(TElem elem) {
    //O(n) best: theta(1), worst: theta(n)

    Node *current = head;
    if (head == nullptr) {
        return false;
    }

    while (current != nullptr) {
        if (current->data.first == elem) {
            // elem found
            if (current->data.second > 1) {
                current->data.second--;
            } else if (current->data.second == 1) {
                if (current->prev != nullptr) {
                    //maintain the connection prev
                    current->prev->next = current->next;
                } else {
                    head = current->next; //if current is head ->update the head being the curr->next
                }
                if (current->next != nullptr) {
                    //maintain the connection next
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev; //if current is tail ->update the tail being the curr->prev
                }

                delete current;
            }
            return true;
        }
        current = current->next;
    }
    return false;

    // //if no elem in Bag
    // if (head == nullptr) {
    //     return false;
    // }
    //
    // Node *current = head;
    // bool elemFound = false;
    //
    // while (current != nullptr) {
    //     //case only 1 elem, elem=head=tail, and found
    //     if (sizeOfDistinctElemsFunc() == 1 && current->data.first == elem) {
    //         if (current->data.second > 1) {
    //             current->data.second--;
    //         } else if (current->data.second == 1) {
    //             //current = nullptr;
    //             head = nullptr;
    //             tail = nullptr;
    //         }
    //         return true;
    //     }
    //     //case only 2 elem, head and tail, and found
    //     if (sizeOfDistinctElemsFunc() == 2 && current->data.first == elem) {
    //         //if head/current = elem and freq > 1, just -- the freq
    //         if (current->data.second > 1) {
    //             current->data.second--;
    //         }
    //         //if current = elem and freq = 1, then is deleted and tail becomes head
    //         else if (current->data.second == 1) {
    //             //current = current->next;
    //             current->next->prev = nullptr;
    //             current->next->next == nullptr;
    //             //tail = current->next;
    //             head = current->next;
    //         }
    //         //if current->next/tail = elem and freq > 1, just -- the freq
    //         if (current->next->data.second > 1) {
    //             current->next->data.second--;
    //         }
    //         //if curr->next/tail = elem and freq = 1, tail is deleted, curr becomes also tail
    //         else if (current->next->data.second == 1) {
    //             current->next = nullptr;
    //             tail = current;
    //         }
    //         return true;
    //     }
    //     //case current = tail, but it is not head // elem is tail
    //     if (current == tail && current->data.first == elem) {
    //         if (current->data.second > 1) {
    //             current->data.second--;
    //             //elemFound = true;
    //         } else if (current->data.second == 1) {
    //             tail = current->prev;
    //             //current = nullptr;
    //         }
    //         return true;
    //     }
    //     //general case
    //     if (current->data.first == elem) {
    //         if (current->data.second > 1) {
    //             current->data.second--;
    //         } else if (current->data.second == 1) {
    //              current->prev->next = current->next;
    //              current->next->prev = current->prev;
    //
    //         }
    //         current = nullptr;
    //         return true;
    //     }
    //     current = current->next;
    // }
    // return false;
}

bool Bag::search(TElem elem) const {
    //O(n) best: theta(1), worst: theta(n)
    Node *current = head;

    while (current != nullptr) {
        if (current->data.first == elem) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int Bag::nrOccurrences(TElem elem) const {
    //O(n) best: theta(1), worst: theta(n)
    Node *current = head;

    while (current != nullptr) {
        if (current->data.first == elem) {
            return current->data.second;
        }
        current = current->next;
    }
    return 0;
}

int Bag::size() const {
    //theta(n) best: theta(n), worst: theta(n)
    int sizeOf = 0;
    //int sizeOfDistinctElement = 0;
    Node *current = head;

    while (current != nullptr) {
        sizeOf += current->data.second;
        current = current->next;
        //sizeOfDistinctElement += 1;
    }
    return sizeOf;
}

bool Bag::isEmpty() const {
    //theta(1) best: theta(1), worst: theta(1)
    if (head == nullptr) {
        return true;
    }
    return false;
}

BagIterator Bag::iterator() const {
    //theta(1) best: theta(1), worst: theta(1)
    return BagIterator(*this);
}

Bag::~Bag() {
    //theta(n) best: theta(1), worst: theta(n)
    Node *current = head;

    while (current != nullptr) {
        Node *next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
}

// int Bag::sizeOfDistinctElemsFunc() const {
//     int sizeOfDistinctElems = 0;
//     Node *current = head;
//
//     while (current != nullptr) {
//         sizeOfDistinctElems += 1;
//         current = current->next;
//     }
//     return sizeOfDistinctElems;
// }
