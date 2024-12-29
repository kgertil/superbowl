/*
 * Linker.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: kevin
 */

#include "Linker.h"
#include "Node.h"

LinkedList::~LinkedList()
{
    clear ();
}

void LinkedList::clear()
{
    Node* temp;
    int Size = size();
    for (int i = 0; i < Size; i++)
    {
   	 temp = head->getNext();
   	 delete head;
   	 head = temp;
    }

    head = NULL;
    tail = NULL;
}


int LinkedList:: get(int index)
{
    Node temp = *head;

    for (int i = 0; i < index; i++)
    {
   	 temp = *(temp.getNext());
    }

    return temp.getValue();
}

bool LinkedList:: isEmpty()
{
    if (head == NULL)
   	 return true;

    else
   	 return false;
}

int LinkedList::size ()
{
    int size = 0;
    Node* temp = head;

    if (head == NULL)
   	 return 0;

    else
    {
   	 while (temp->getNext() != NULL)
   	 {
   		 temp = temp->getNext();
   		 size++;
   	 }
   	 return ++size;
    }
}

void LinkedList::print ()
{
    int Size = size();
    if (Size == 0)
    {
   	 cout << "No elements in the list exist to be printed" << endl;
   	 return;
    }

    Node* temp = head;
    while (temp->getNext() != NULL)
    {
   	 cout << temp->getValue() << endl;
   	 temp = temp->getNext();
    }
    cout << temp->getValue() << endl;        	// print the value of the last node
}



///////////////// Kev’s Code ///////////////

LinkedList::LinkedList(){
    head = NULL;
    tail = NULL;
};


// update tail after each addition
void LinkedList:: add(int index, int element){

    if (index == 0)
   	 head = new Node (element, head);

    else if ((index > 0) && (index <= size() ))
    {
   	 Node* temp = head;

   	 for (int i = 0; i < index - 1; i++)
   	 {
   		 temp = temp->getNext();
   	 }
   	 temp->setNext(new Node (element, temp->getNext()));

    }

    else
   	 cout << "The given index is outside the boundaries of the collection!" << endl;

}

void LinkedList::add(int value){
    Node* temp = head;

    if (head == NULL)
    {
   	 head = new Node (value, NULL);
   	 tail = head;
    }


    else
    {
   	 while (temp->getNext() != NULL)
   	 {
   		 temp = temp->getNext();
   	 }

   	 temp->setNext(new Node (value, NULL));

   	 tail = temp->getNext();
    }
}

bool LinkedList::contains (int element){
    Node* temp = head;
    int Size = size();

    for (int i = 0; i < Size; i++)
    {
   	 if (temp->getValue() == element)
   		 return true;

   	 temp = temp->getNext();
    }

    return false;
}


void LinkedList::remove(int index){

    Node *tempptr = head;
    Node *prior = head;
    int Size = size();

    // Deals with the case of removing a node in the middle or end of the LinkedList
    if (index > 0 && index < Size){

   	 for (int i = 0; i < index; i++)
   	 {
   		 tempptr = tempptr->getNext();
   	 }

   	 for (int i = 0; i < index - 1; i++)
   	 {
   		 prior = prior->getNext();
   	 }

   	 if (index == Size -1)
   		 tail = prior;

   	 prior->setNext (tempptr->getNext());

   	 delete tempptr;
    }

    // Deals with removing the first element
    else if (index == 0)
    {
   	 tempptr = head->getNext();

   	 delete head;

   	 head = tempptr;
    }


    else
   	 cout << "The index is out of boundaries" << endl;


}


///////////////////Operator Overloading////////////////

ostream& operator << (ostream& output, LinkedList& obj)
{
    int Size = obj.size();
    if (Size == 0)
    {
   	 output << "No elements in the list exist to be printed" << endl;
   	 return output;
    }

    Node* temp = obj.head;
    while (temp->getNext() != NULL)
    {
   	 output << temp->getValue() << endl;
   	 temp = temp->getNext();
    }
    output << temp->getValue() << endl;        	// print the value of the last node

    return output;
}

bool LinkedList::operator == (LinkedList& right)
   	 {
    Node* temp1 = head;
    Node* temp2 = right.head;
    int Size = size();

    if (right.size() != Size)
   	 return false;

    for (int i = 0; i < Size; i++)
    {
   	 if (temp1->getValue() != temp2->getValue())
   		 return false;

   	 temp1 = temp1->getNext();
   	 temp2 = temp2->getNext();
    }

    return true;

   	 }

bool LinkedList::operator < (LinkedList& right)
{
    int sum1 = 0;
    int sum2 = 0;
    Node* temp1 = head;
    Node* temp2 = right.head;

    while (temp1->getNext() != NULL)
    {
   	 sum1 += temp1->getValue();
   	 temp1 = temp1->getNext();
    }

    while (temp2->getNext() != NULL)
    {
   	 sum2 += temp2->getValue();
   	 temp2 = temp2->getNext();
    }

    if (sum1 < sum2)
   	 return true;

    else
   	 return false;
}


LinkedList LinkedList:: operator+( LinkedList &L2){


    LinkedList L3;

    Node  *temp = head;

    while(temp ->getNext()!=NULL){

        L3.add(temp->getValue());

        temp= temp->getNext();


    }

    L3.add(temp->getValue()); // adding the last element of the left linklist

    temp= L2.head;

    while(temp ->getNext()!=NULL){

        L3.add(temp->getValue());

        temp= temp->getNext();


    }

    L3.add(temp->getValue()); // adding the last element of the left linklist

    return L3;
}

int LinkedList::operator[](int index){ // update on drive

    Node *ptr = head;
    int Size = size();

    if ( index < 0 || index >= Size)
    {
        cout << "Index " << index <<" not in of range of LinkedList" << endl;

        exit(0);
    }
    else
    {
        for ( int i= 0; i < index; i++){

            ptr= ptr->getNext();

        }
        return ptr->getValue();

    }


}

