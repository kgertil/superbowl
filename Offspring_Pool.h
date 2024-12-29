#ifndef OFFSPRING_POOL_H
#define OFFSPRING_POOL_H
#include"Genetic_Algorithm.h"
#include<iostream>
#include<string>

#include "Population.h"
using namespace std;
template<class T>
class Offspring_Pool:public Population<T>
{
  public:
  Offspring_Pool(Offspring<T> &,Offspring<T> &,Population<T> &P);
  void real_valued_mutation(Offspring<T> &);
  void form_population();
  void print();
  virtual ~Offspring_Pool();
  float noise;
  string var_str;
  int pick_var;
  Offspring<T> Offspring_population[2];
  Offspring<T>OS1;
  Offspring<T>OS2;

 protected:
 private:
};

template<class T>
Offspring_Pool<T>::Offspring_Pool(Offspring<T> &Os1,Offspring<T> &Os2,Population<T> &P):Population<T>(P)
{
if(this->Individuals_array[0].pick_application==1)
var_str = "abcd";
else if(this->Individuals_array[0].pick_application==0)
var_str = "xy";
pick_var = rand()%(var_str.size()-1); // picking the variable that will be mutated
//cout<<"Os fr "<<Os1.a<<endl;
real_valued_mutation(Os1);
real_valued_mutation(Os2);
OS1 = Os1;
OS2 = Os2;
}


template<class T>
void Offspring_Pool<T>::real_valued_mutation(Offspring<T> &Os)
{
vector<T>var_array1;
if(this->Individuals_array[0].pick_application==0)
{
var_array1.push_back(Os.x);
var_array1.push_back(Os.y);
}

if(this->Individuals_array[0].pick_application==1)
{
var_array1.push_back(Os.a);
var_array1.push_back(Os.b);
var_array1.push_back(Os.c);
var_array1.push_back(Os.d);
}
noise = -0.1 + static_cast <T> (rand()) /( static_cast <T> (RAND_MAX/(0.1-(-1))));
var_array1.at(pick_var)+=noise;

}

template<class T>
void Offspring_Pool<T>::form_population()
{

Offspring_population[0] = OS1;
Offspring_population[1] = OS2;
}

template<class T>
Offspring_Pool<T>::~Offspring_Pool()
{
 //dtor
}

template<class T>
void Offspring_Pool<T>::print()
{
  if(Offspring_population[0].pick_application==1)
  {
  cout<<"mutated offspring 1"<<endl;
  cout<<"a 0 is: "<<Offspring_population[0].a<<endl;
  cout<<"b 0 is: "<<Offspring_population[0].b<<endl;
  cout<<"c 0 is: "<<Offspring_population[0].c<<endl;
  cout<<"d 0 is: "<<Offspring_population[0].d<<endl;
  cout<<"fitness 0 is: "<<Offspring_population[0].fitness2<<endl;
  cout<<"************************************************************"<<endl;
  cout<<"mutated offspring 2"<<endl;
  cout<<"a 1 is: "<<Offspring_population[1].a<<endl;
  cout<<"b 1 is: "<<Offspring_population[1].b<<endl;
  cout<<"c 1 is: "<<Offspring_population[1].c<<endl;
  cout<<"d 1 is: "<<Offspring_population[1].d<<endl;
  cout<<"fitness 1 is: "<<Offspring_population[1].fitness2<<endl;
  }
  else if(Offspring_population[0].pick_application==0)
  {
    cout<<"mutated offspring 1"<<endl;
  cout<<"x 0 is: "<<Offspring_population[0].x<<endl;
  cout<<"y 0 is: "<<Offspring_population[0].y<<endl;
  cout<<"fitness 0 is: "<<Offspring_population[0].fitness1<<endl;
  cout<<"********************************************"<<endl;
  cout<<"mutated offspring 2"<<endl;
  cout<<"x 1 is: "<<Offspring_population[1].x<<endl;
  cout<<"y 1 is: "<<Offspring_population[1].y<<endl;
  cout<<"fitness 1 is: "<<Offspring_population[1].fitness1<<endl;
  }

}

#endif // OFFSPRING_POOL_H
