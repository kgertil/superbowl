/*
 * Node.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: kevin
 */

#include "Node.h"


Node:: Node (const Node&  points2)
{
    value = points2.value;
	next = points2.next;  // copy the address of points2 variable to next pointer
}

Node:: ~Node(){  } // the destructor

void Node::setValue(int v){ value = v; }  // sets value


Node* Node:: getNext()
{
	return next;  // return next
}



Node::Node (int value1, Node* next1)
{
    value = value1;
    next = next1;
}


int Node::getValue()
{
    return value;  //
}

void Node::setNext (Node* next1)
{
    next = next1;
}
