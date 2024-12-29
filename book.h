//
//  book.h
//  chapstick
//
//  Created by Kevin on 2016-02-14.
//  Copyright © 2016 Kevin. All rights reserved.
//



#include <iostream>
#include <string>
using namespace std;


#ifndef Book_h
#define Book_h

class Reference   // start of class Reference
{
public:
    
    Reference ();  //default constructor
    Reference (int, int, string, string);  // overload constructor
    
    int getId () {return id;}  // member function for id
    int getYear () {return publicationYear;}  // member function for year
    string getTitle () {return Title;}  // member function for  title
    string getAuthor () {return Author;}  // member function for author
    
    void print ();  // member function for print
    
private:
    
    int id, publicationYear;
    string Title, Author;
};

class Book : public Reference  // Book is a derived class of Reference
{
public:
    
    Book ();  // defualt constructor
    Book (int, int, string, string, string, int);  //constructor
    
    int getNumberOfPages() {return pagesNum;}
    
    void print ();  // member function for print
    
    
private:
    string publisher;
    int pagesNum;
    
};

#endif /* book_h */


#ifndef REFERENCE_H_
#define REFERENCE_H_




#endif /* REFERENCE_H_ */

Book :: Book ()  // constructor
: Reference ()  // invoke reference constructor
{
    publisher = "";
    pagesNum = 0;
}

Book :: Book (int ID, int PY, string TI, string AU, string PS, int PN)  //constructor with parameters
: Reference (ID, PY, TI, AU), publisher (PS), pagesNum (PN)  // invoke reference constructor
{}

void Book :: print ()  // member function for print book
{
    Reference :: print();
    
    cout << "The publisher name is: " << publisher << endl;
    cout << "The number of pages is: " << pagesNum << endl;
}

Reference::Reference ()   // defined default constructor
{
    id = 0;
    publicationYear = 0;
    Title = "";
    Author = "";
}

Reference::Reference (int ID, int PY, string TI, string AU)  // constructor overload
: id (ID), publicationYear (PY), Title (TI), Author (AU)
{}

void Reference:: print () // print member function
{
    cout << "Reference information" << endl;
    cout << "The reference unique identifier is: " << id << endl;
    cout << "The reference title is: " << Title << endl;
    cout << "The reference author is: " << Author << endl;
    cout << "The publication year is: " << publicationYear << endl;
    
}