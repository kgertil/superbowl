/*
 * Collection.h
 *
 *  Created on: Mar 7, 2016
 *      Author: kevin
 */

#ifndef COLLECTION_H_
#define COLLECTION_H_

class Collection{
public:

	Collection() {}; // Default constructor
	virtual ~Collection() {}; // Destructor

	// Inserts the specified element at the specified position in the collection
	virtual void add(int index, int element) = 0;

	// Appends the specified element to the end of this collection
	virtual void add(int value) = 0;

	// Removes all of the elements from this collection.
	virtual void clear() = 0;

	// Returns true if this collection contains the specified element.
	virtual bool contains(int element) = 0;

	// Returns the element at the specified position in this collection.
	virtual int get(int index) = 0;

	// Returns true if this list contains no elements.
	virtual bool isEmpty() = 0;

	// Removes the element at the specified position in this collection
	virtual void remove(int index) = 0;

	// Returns the number of elements in this collection.
	virtual int size() = 0;

};

#endif /* COLLECTION_H_ */
