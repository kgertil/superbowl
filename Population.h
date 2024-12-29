#ifndef POPULATION_H
#define POPULATION_H
#include"Individual.h"
//#include"Offspring_Pool.h"
#include<stdlib.h>
#include"time.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Population template class decleration
template<class T>
class Population
{
public:
vector<int>winners_list;  // the list of the individual with the best fitness in each tournament
T fitness; // fitness
virtual void print(); // display results
Population(int i = 0); // default constructor with default argument
virtual void form_population();  // forming the population
void tournament_selection(); // tournaments tp pick the best indivdual in each one
vector<T>best_fitness_list; // list of fitnesses of the Individuals that won in the tournament selection
vector<T>arranged_list_of_fitness; // list of arranged fitnesses in ascending order
virtual ~Population(); // virtual destructor
int S;  // number of Individuals in a Population
Individual<T> *Individuals_array;  // pointer to Individuals
Population(Population<T> &obj );   // a copy constructor
private:
};

// implementation of Population class

// default constructor with default argument
template<class T>
Population<T>::Population(int i)
{
 S = i; // initializing the number of Individuals in the population
}

// copy constructor
template<class T>
Population<T>::Population(Population<T> &obj)
{
 S = obj.S; // copying size of population
 Individuals_array = obj.Individuals_array; // copying the array of individuals
 best_fitness_list = obj.best_fitness_list; // copying the list of fitnesses of the Individuals that won in the tournament selection
}


// forming the population
template<class T>
void Population<T>::form_population()
{
 Individuals_array = new Individual<T>[S]; // reserving heap for Individuals_array
}

// tournament selection
template<class T>
void Population<T>::tournament_selection()
{
int flag = 1; // checking flag
int selected_individual; // picked individual at random
int indx; // index for elements location
int num_of_tournament = S/4; // number of tournaments
int num_of_pick = num_of_tournament*2; // number of individuals to be picked at each tournament

// declaring iterators and checks to make sure that neither the best individual of each tournament nor the picked individuals at random gets repeated
vector<int>::iterator it1;
vector<int>::iterator it2;
bool check1;
bool check2;
for(int i =0;i<S;i++)
{
// if optimization application
if(Individuals_array[0].pick_application==0)
arranged_list_of_fitness.push_back(Individuals_array[i].fitness1);  // pushing individuals fitness into the list
// if curve fitting application
else if (Individuals_array[0].pick_application==1)
arranged_list_of_fitness.push_back(Individuals_array[i].fitness2);
}
sort(arranged_list_of_fitness.begin(),arranged_list_of_fitness.end());
vector<int> index_list;
for(int k =1;k<=num_of_tournament;k++)
{
for(int i=1;i<=num_of_pick;i++)
{
if(index_list.size()==0&&winners_list.size()==0)
{
selected_individual = rand()%S+1;
}
else if(index_list.size()==0&&winners_list.size()>0)
{
selected_individual = rand()%S+1;
it2 = find(winners_list.begin(),winners_list.end(),(selected_individual-1));
check2 = (*it2==(selected_individual-1));
flag = 1;
while(flag == 1)
{
if(check2)
{
selected_individual = rand()%S+1;
it2 = find(winners_list.begin(),winners_list.end(),(selected_individual-1));
check2 = (*it2==(selected_individual-1));
}
else
flag=0;
}
}
else if(index_list.size()>0&&winners_list.size()==0)
{
selected_individual = rand()%S+1;
it1 = find(index_list.begin(),index_list.end(),(selected_individual-1));
check1 = (*it1==(selected_individual-1));
flag = 1;
while(flag == 1)
{
if(check1)
{
selected_individual = rand()%S+1;
it1 = find(index_list.begin(),index_list.end(),(selected_individual-1));
check1 = (*it1==(selected_individual-1));
}
else
flag=0;
}
}
else
{
selected_individual = rand()%S+1;
it1 = find(index_list.begin(),index_list.end(),(selected_individual-1));
it2 = find(winners_list.begin(),winners_list.end(),(selected_individual-1));
check1 = (*it1==(selected_individual-1));
check2 = (*it2==(selected_individual-1));
flag = 1;
while(flag == 1)
{
if(check1||check2)
{
selected_individual = rand()%S+1;
it1 = find(index_list.begin(),index_list.end(),(selected_individual-1));
it2 = find(winners_list.begin(),winners_list.end(),(selected_individual-1));
check1 = (*it1==(selected_individual-1));
check2 = (*it2==(selected_individual-1));
}
else
flag=0;
}
}
index_list.push_back((selected_individual-1));
}
sort(index_list.begin(),index_list.end());
indx = index_list.at(0);
winners_list.push_back(indx);
fitness = arranged_list_of_fitness.at(indx);
best_fitness_list.push_back(fitness);
index_list.clear();
}
}

// display results
template<class T>
void Population<T>::print()
{
for(int i=0;i<S;i++)
{
if(Individuals_array[0].pick_application==1)
{
cout<<"a "<<i<<" is: "<<Individuals_array[i].a<<endl;
cout<<"b "<<i<<" is: "<<Individuals_array[i].b<<endl;
cout<<"c "<<i<<" is: "<<Individuals_array[i].c<<endl;
cout<<"d "<<i<<" is: "<<Individuals_array[i].d<<endl;
cout<<"fitness "<<i<<" is: "<<Individuals_array[i].fitness2<<endl;
cout<<"***********************************************************"<<endl;
}
else if(Individuals_array[0].pick_application==0)
{
cout<<"x "<<i<<" is: "<<Individuals_array[i].x<<endl;
cout<<"y "<<i<<" is: "<<Individuals_array[i].y<<endl;
cout<<"fitness "<<i<<" is: "<<Individuals_array[i].fitness1<<endl;
cout<<"***************************************************************"<<endl;
}
}
}

// destructor
template<class T>
Population<T>::~Population()
{
delete (Individual<T>*)0;  // clearing the heap reserved for Individuals_array
}


#endif // POPULATION_H
