
#include<iostream>
#include <string>
using namespace std;

class Node {
    
private:
    int value; // the value of the node
    Node* next; // A pointer to the next node
    
public:
    Node(int, Node*); // Regular constructor
    
    Node(const Node&);// Copy constructor
    
    ~Node(); // Destructor
    
    void setValue(int); // Changes value
    int getValue(); // Returns value
    void setNext(Node*); // Changes next
    
    Node* getNext(); // Returns next
    
    
};

class Collection{
    
protected:
    
    Collection() {}; // Default constructor
    virtual ~Collection(){}; // Destructor
    
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

Node :: Node(const Node&  points2)
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


////// OSAMA's part//////////////


Node::Node (int value1, Node* next1)
{
    value = value1;
    next = next1;
}


int Node::getValue()
{
    return value;
}

void Node::setNext (Node* next1)
{
    next = next1;
}
//////// LinkedListed Definition


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

////////// Question 2

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

int main ()
{
    LinkedList obj1;
    
    obj1.add(15);
    obj1.add(85);
    obj1.add(45);
    
    obj1.print ();
    
    cout << "\nThe value of the node pointed to by tail is " << (obj1.getTail())->getValue() << endl << endl;
    
    
    cout << "After the addition of a node at position 2 " << endl;
    obj1.add(2, 77);
    obj1.print ();
    
    cout << "After the addition of a node at position 0 "<< endl;
    obj1.add(0, 16);
    obj1.print();
    
    cout << "After the addition of a node at position 5 (the final position)" <<endl;
    obj1.add(5, 100);
    obj1.print();
    
    
    
    cout << "\nThe number of elements in the collection is " << obj1.size() << endl << endl;
    
    if (obj1.contains(85))
        cout << "The element exists in the list" << endl << endl;
    else
        cout << "The element doesn't exist in the list" <<endl << endl;
    
    cout << "Removing the final element" << "\n";
    obj1.remove(5);
    cout << "The list after removing the elements" << endl;
    obj1.print();
    cout << endl;
    
    cout << "Removing the initial element" << "\n";
    obj1.remove(0);
    cout << "The list after removing the elements" << endl;
    obj1.print();
    cout << endl;
    
    cout << "Removing the element at position 2" << "\n";
    obj1.remove(2);
    cout << "The list after removing the elements" << endl;
    obj1.print();
    cout << endl;
    
   
    
    
    cout << "----- Testing the overloaded operators -----" << endl << endl;
    
    cout << "Printing the elements of the list using the overloaded << operator" << endl;
    cout << obj1 << endl;
    
    cout << "Testing the overloaded equality operator" << endl;
    LinkedList obj2;
    obj2.add(0);
    obj2.add(11);
    obj2.add(22);
    if (obj1 == obj2)
        cout << "The two lists are equal" << endl << endl;
    else
        cout << "The two lists are not equal" << endl << endl;
    
    cout << "Testing the overloaded < operator" << endl;
    if (obj1 < obj2)
        cout << "The sum of elements in obj1 is smaller than the sum of elements in obj2" << endl << endl;
    else
        cout << "The sum of elements in obj1 is not smaller than the sum of elements in obj2" << endl << endl;
    
    
    cout << "Testing the operator+ overloader" << endl;
    cout << "The nodes of object 1 are"<< endl;
    cout << obj1;
    
    cout << "The nodes of object 2 are"<< endl;
    cout << obj2;
    
    LinkedList obj3 = obj1+obj2;
    cout <<"The nodes inside object 3 which is the result of obj1 + obj2 " << obj3 << endl;
    
    
    cout << "Testing the subscript overloader" << endl;
    cout << "The value of the node at subscript 1 is: "<< obj1 [2] << endl;
    
    
    
    obj1.clear();
    cout << "The list size after clearing the list is: " << obj1.size();
    
    
}





