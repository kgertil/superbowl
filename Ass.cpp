
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;


class Date    	// Date class

{
public:

	Date ();    	// default constructor
	Date (int, int, int);    	// Constructor that receives arguments
	Date (const Date&);   		 // Copy constructor

	// Accessing functions
	int getDay ();
	int getMonth ();
	int getYear ();
	void setDate (int, int, int);

	// Destructor
	~Date ();

	// Overloaded operators
	friend ifstream& operator >> (ifstream&, Date&);
	friend ofstream& operator << (ofstream&,Date&);

private:
	int day;    	//data members of Date class in private
	int month;
	int year;
};



Date::Date ()
{
	day = 0;
	month = 0;
	year = 0;
}

Date::Date (int a, int b, int c)
{
	day = a;
	month = b;
	year = c;

}

Date::Date (const Date& temp)
{
	*this = temp;

}


int Date::getDay()
{
	return day;
}

int Date::getMonth()
{
	return month;
}

int Date::getYear()
{
	return year;
}

void Date:: setDate (int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}


Date::~Date()
{
}

ifstream& operator >> (ifstream& input, Date& obj)
{
	input >> obj.year;
	input.ignore();   	 // The ignore function is used to skip reading the hyphen

	input >> obj.month;
	input.ignore();

	input >> obj.day;

	return input;   	 // To allow cascaded usage of the operator
}

ofstream& operator << (ofstream& output,Date& obj){

	output << obj.year << '-' << obj.month << '-' << obj.day;

	return output;   	 // To allow cascaded usage of the operator
}


int main (int argc, char *argv[])

{
    // start of test driver


	ifstream input (argv[1]);   		 // Associate input with the file that its directory has been provided in the setting of eclipse
	ofstream output ("reverse.dat");    // Associate output with the file "reverse.dat"
	string dType;
	int dSize;

	// Pointers that will be used to dynamically allocate arrays the will store the third field
	int *iPtr;
	float *fPtr;
	char *cPtr;
	Date *dPtr;


	// An infinite loop that will continue until the EOF has been reached
	while (1)
	{
    	input >> dType;
    	input >> dSize;


    	if (dType == "int")
    	{
        	output << dType << setw (8) << dSize << "\t";

        	iPtr = new int [dSize];

        	for (int i = 0; i < dSize; i++)
            	input >> iPtr [i];

        	for (int i = dSize - 1; i >= 0; i--)
            	output << iPtr [i] << ' ';

        	output << endl;

        	if (input.get() == EOF)
            	break;

    	}

    	else if (dType == "float")
    	{
        	output << dType << setw (6) << setprecision(2) << fixed << dSize << "\t";

        	fPtr = new float [dSize];

        	for (int i = 0; i < dSize; i++)
        	{
            	input >> fPtr [i];
        	}
        	for (int i = dSize - 1; i >= 0; i--)
            	output << fPtr [i]  << "  ";

        	output << endl;

        	if (input.get() == EOF)
            	break;
    	}

    	else if (dType == "char")
    	{
        	output << dType << setw (7) << dSize << "\t";

        	cPtr = new char [dSize];

        	for (int i = 0; i < dSize; i++)
            	input >> cPtr [i];

        	for (int i = dSize - 1; i >= 0; i--)
            	output << cPtr [i] << ' ';

        	output << endl;

        	if (input.get() == EOF)
            	break;
    	}

    	else if (dType =="Date")
    	{
        	output << dType << setw (7) << dSize << "\t";

        	dPtr = new Date [dSize];

        	for (int i = 0; i < dSize; i++)
        	{
            	input >> dPtr [i];
        	}

        	for (int i = dSize - 1; i >= 0; i--)
            	output << dPtr [i]  << ' ';

        	output << endl;

        	if (input.get() == EOF)
            	break;
    	}
	}

}





