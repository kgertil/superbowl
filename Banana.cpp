#include <iostream>
#include <string>
using namespace std;

class date(){

private:

	int day;
	int month;
	int year;

public:

	date() { day = 0; month = 0; year = 0; }  // my constructor
	~date() {}; // my destructor
	date (int d, int m, int y) {day = d; month = m; y = year;}
	void printdate() {
		cout << "The day is:" << day << endl;
		cout << "The month is:" << month  << endl;
		cout << "the year is:" << year << endl;

	}
};

class customer(){

private:

string name;
string address;
string telephone;
date dob;

public:

customer() { name = ""; address =""; telephone =""; }

customer (string n, string add, string tel, date dateofbirth)	{
	name = n;
	address = add;
	telephone = tel;
	dob = dateofbirth;
}
void set_name(string n) { address = addr;}
void set_address(string addr) { address = addr;}
void set_telephone(string tele) { telephone = tele;}
void set_dateofbith(string dofb) {dateofbirth = dofb}
void print() {
 cout << "customer information is:" << name <<endl;
 cout "customer address is" << address <<endl;
 cout << "customer phone is" << telephone << endl;
 dob.print();
}


};


int main(){

	date d1;// object d1
			customer c2;
			int d,m,y;

		cout<<"enter a day"<<endl;
		cin>>d;
			d1.setday(d);
			cout<<"enter a month"<<endl;
			cin>>m;
			d1.setmonth(m);
			cout<<"enter a year	"<<endl;
			cin>>y;
			d1.setyear(y);


			string n1;
			cout<<"give me a name"<<endl;
			cin>>n1;
			c2.setname(n1);
			string t1;
			cout<<"give me a telephone number"<<endl;
			cin>>t1;
			c2.settelephone(t1);
			string n2;
			cout<<"give me a number for address"<<endl;
			cin>>n2;
			c2.setAddress(n2);
			string n3;
			cout<<"street name?"<<endl;
			cin>>n3;
			c2.setAddress(n3);


			d1.print();
					c2.print();

return 0;
}
