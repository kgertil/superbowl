#ifndef PARENT_POOL_H
#define PARENT_POOL_H
#include"Population.h"
#include"Individual.h"
#include<vector>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;

// decleration of the class
template<class T>
class Parent_Pool:public Population<T>
{
public:
Parent_Pool(); // default constructor
// iterator and check to make sure that a parent doesnt get picked twice
vector<int>::iterator it; // iterator
bool check; // checking for condition
int parent_selection; // location of selected parents in the parent array
virtual ~Parent_Pool();  // destructor
void form_population(); // forming parents
Individual<T> *Parent_array; // array of parents
int Size1; // number of parents
Individual<T> * pick_parents(); // pick 2 parents
Parent_Pool(Population<T> &P); // copy constructor
template<class U> friend class Offspring;
vector<int> indexed_parent_array; // array of selected parents lovations
Individual<T> *picked_parents_arr; // array of picked 2 parents
void print();  // display results
protected:
private:
};

// destructor
template<class T>
Parent_Pool<T>::~Parent_Pool()
{

}

// copy constructor
template<class T>
Parent_Pool<T>::Parent_Pool(Population<T> &P):Population<T>(P)
{
Size1 = this->best_fitness_list.size();
}

// forming parents
template<class T>
void Parent_Pool<T>::form_population()
{
Size1 = this->best_fitness_list.size();
Parent_array = new Individual<T>[Size1];
int j = 0;
int y = this->S;
if(this->Individuals_array[0].pick_application==0)
{
for(int i = 0;i<this->best_fitness_list.size();i++)
{
j = 0;
while(j<y)
{
if((this->Individuals_array[j].fitness1)==(this->best_fitness_list.at(i)))
{
Parent_array[i] = this->Individuals_array[i];
j = y+10;
}
else
j++;
}
}
}

// if curve fitting application
if(this->Individuals_array[0].pick_application==1)
{
for(int i = 0;i<this->best_fitness_list.size();i++)
{
j = 0;
while(j<y)
{
if((this->Individuals_array[j].fitness2)==(this->best_fitness_list.at(i)))
{
Parent_array[i] = this->Individuals_array[i];
j = y+10;
}
else
j++;
}
}
}
cout.precision(32);
}

// picking 2 parents
template<class T>
Individual<T> * Parent_Pool<T>::pick_parents()
{
int flag;
for(int i=0;i<2;i++)
{
if(indexed_parent_array.size()!=0)
{
parent_selection = rand() % Size1 + 1;
it = find(indexed_parent_array.begin(),indexed_parent_array.end(),(parent_selection-1));
check = (*it==(parent_selection-1));
flag = 1;
while(flag==1)
{
if(check)
{
parent_selection = rand() % Size1 + 1;
it = find(indexed_parent_array.begin(),indexed_parent_array.end(),(parent_selection-1));
check = (*it==(parent_selection-1));
}
else
flag = 0;
}
}
else
{
parent_selection = rand() % Size1 + 1;
}
indexed_parent_array.push_back(parent_selection-1);
}
picked_parents_arr = new Individual<T>[2];
for(int g = 0;g<indexed_parent_array.size();g++)
{
static int temp_indx= 0;
temp_indx = indexed_parent_array.at(g);
picked_parents_arr[g] = Parent_array[temp_indx];
}
return picked_parents_arr;
}
template<class T>
void Parent_Pool<T>::print()
{
for(int i=0;i<Size1;i++)
{
if(Parent_array[0].pick_application==0)
{
cout<<"x "<<i<<" is: "<<Parent_array[i].x<<endl;
cout<<"y "<<i<<" is: "<<Parent_array[i].y<<endl;
cout<<"fitness "<<i<<" is: "<<Parent_array[i].fitness1<<endl;
}
else if(Parent_array[0].pick_application==1)
{
cout<<"a "<<i<<" is: "<<Parent_array[i].a<<endl;
cout<<"b "<<i<<" is: "<<Parent_array[i].b<<endl;
cout<<"c "<<i<<" is: "<<Parent_array[i].c<<endl;
cout<<"d "<<i<<" is: "<<Parent_array[i].d<<endl;
cout<<"fitness "<<i<<" is: "<<Parent_array[i].fitness2<<endl;
}
}
}

#endif // PARENT_POOL_H
