/*
 * Node.h
 *
 *  Created on: Mar 7, 2016
 *      Author: kevin
 */

#ifndef NODE_H_
#define NODE_H_

#include <iostream>
using namespace std;

class Node
{
private:
    int value;
    Node* next;

public:
    Node (int, Node*);
    Node (const Node & );
    ~Node();

    void setValue (int);
    int getValue ();

    void setNext (Node*);
    Node* getNext();
};


#endif /* NODE_H_ */
