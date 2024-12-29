/*
 * Linker.h
 *
 *  Created on: Mar 7, 2016
 *      Author: kevin
 */
#include "Node.h"
#include "Collection.h"


#ifndef LINKER_H_
#define LINKER_H_
#include <iostream>

using namespace std;


class LinkedList : public Collection
{
public:
    LinkedList(); // Default constructor
    virtual ~LinkedList(); // Destructor

    // Inserts the specified element at the specified position in the collection
    virtual void add(int index, int element);

    // Appends the specified element to the end of this collection
    virtual void add(int value);

    // Removes all of the elements from this collection.
    virtual void clear();

    // Returns true if this collection contains the specified element.
    virtual bool contains(int element);

    // Returns the element at the specified position in this collection.
    virtual int get(int index);

    // Returns true if this list contains no elements.
    virtual bool isEmpty();

    // Removes the element at the specified position in this collection
    virtual void remove(int index);

    // Returns the number of elements in this collection.
    virtual int size();

    void print ();

    Node* getHead () {return head;}
    Node* getTail () {return tail;}

    /////////////////Operator Overloading/////////////////

    bool operator == (LinkedList&);
    friend ostream& operator << (ostream&, LinkedList&);
    bool operator < ( LinkedList&);
   LinkedList operator+( LinkedList &L2);
    int operator[](int index);



private:
    Node* head;
    Node* tail;
};


#endif /* LINKER_H_ */
