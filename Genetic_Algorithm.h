#ifndef GENETIC_ALGORITHM_H
#define GENETIC_ALGORITHM_H
#include "Individual.h"
#include"Parent_Pool.h"
#include"Offspring.h"
#include"Offspring_Pool.h"
#include"joint_pool.h"
#include"Population.h"
using namespace std;
#include<iostream>

template<class T>
class Genetic_Algorithm
{
public:
friend ostream & operator<<(ostream &,Individual<T>);  // overloaded output operator
Genetic_Algorithm(Population<T> &);
Population<T> *P;
Population<T> *P1;
Population<T> *P3;
Individual<T> *Selected_parents;
Parent_Pool<T> *PP1;
int pick_application;

 //Offspring<T1,T2> *Os2;
// Offspring_Pool<T1,T2> OsP;
Population<T> *P2;
~Genetic_Algorithm();
protected:
private:
};

template<class T>
Genetic_Algorithm<T>::~Genetic_Algorithm()
{

}
template<class T>
Genetic_Algorithm<T>::Genetic_Algorithm(Population<T> &P )
{
cout<<"please enter 0 for the optimization application and 1 for the curve fitting application"<<endl;
cin>>pick_application;
Individual<T> I(pick_application);
P1 = &P;
P1->form_population();
P1->tournament_selection();
cout<<"population:"<<endl;
P1->print();
cout<<"----------------------------------------------------------------------------"<<endl<<endl;
Parent_Pool<T> PP(P);
P2 = &PP;
P2->form_population();
cout<<"Parents:"<<endl;
P2->print();
cout<<"------------------------------------------------------------------------------------"<<endl<<endl;
PP1 = &PP;
Selected_parents = new Individual<T>[2];
Selected_parents = PP1->pick_parents();

Offspring<T> Os1(Selected_parents);
Offspring<T> Os2(Selected_parents);
cout<<"Offspring 1:"<<endl;
Os1.print();
cout<<"-----------------------------------------------------------------------------"<<endl<<endl;
cout<<"offspring 2:"<<endl;
Os2.print();
cout<<"----------------------------------------------------------------------------------"<<endl<<endl;
Offspring_Pool<T>Osp(Os1,Os2,P);
P3 = &Osp;
P3->form_population();
P3->print();
cout<<"-----------------------------------------------------------------------------------"<<endl<<endl;
joint_pool<T> jp(P,PP,Osp);
cout<<"new population"<<endl;
P.print();
cout<<"--------------------------------------------------------------------------------"<<endl<<endl;
cout<<"new population size: "<<P.S<<endl;





}
template<class T>
ostream& operator<<(ostream &out,Individual<T> I)
{
T A,B,C,D;
T X,Y;
out<<"fitness is: "<<I.fitness2<<endl<<"a = "<<I.a<<"b = "<<I.b<<"c = "<<I.c<<"d = "<<I.d<<endl;
return out;
}
#endif // GENETIC_ALGORITHM_H
