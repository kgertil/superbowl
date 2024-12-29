//============================================================================
// Name        : LinkedList.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Linker.h"
#include "Node.h"

int main() {

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
		obj2.add(15);
		obj2.add(85);
		obj2.add(45);
		if (obj1 == obj2)
	   	 cout << "The two lists are equal" << endl << endl;
		else
	   	 cout << "The two lists are not equal" << endl << endl;

		cout << "Testing the overloaded < operator" << endl;
		if (obj1 < obj2)
	   	 cout << "The sum of elements in obj1 is smaller than the sum of elements in obj2" << endl << endl;
		else
	   	 cout << "The sum of elements in obj1 is not smaller than the sum of elements in obj2" << endl << endl;

	    cout << "Testing the operator+ over loader" << endl;
	    cout << "The nodes of object 1 are"<< endl;
	    cout << obj1;

	    cout << "The nodes of object 2 are"<< endl;
	    cout << obj2;

	    LinkedList obj3 = obj1+obj2;
	    cout <<"The nodes inside object 3 which is the result of obj1 + obj2 " << endl << obj3;


	    cout << "Testing the subscript overloader" << endl;
	    cout << "The value of the node at subscript 1 is: "<< obj1 [2] << endl;



		obj1.clear();
		cout << "The list size after clearing the list is: " << obj1.size();

}
