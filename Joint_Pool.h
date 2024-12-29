#ifndef JOINT_POOL_H
#define JOINT_POOL_H
#include<iostream>
using namespace std;
#include"Offspring.h"
#include"Parent_Pool.h"
template<class T>
class joint_pool:public Population<T>
{
    public:
        joint_pool(Population<T> &,Parent_Pool<T>,Offspring_Pool<T>);
        Individual<T> *joint_array;
        virtual ~joint_pool();
    protected:
    private:
};

template<class T>
joint_pool<T>::joint_pool(Population<T> &P,Parent_Pool<T> PP,Offspring_Pool<T> Osp):Population<T>(P)
{
 // passing mutated offspring
 P.Individuals_array[0] = Osp.Offspring_population[0];
 P.Individuals_array[1] = Osp.Offspring_population[1];
 int j = 0;
 for(int i=0;i<PP.Size1;i++)
 {
P.Individuals_array[j] = PP.Parent_array[i];
  j++;
 }
 P.S = PP.Size1+2;
}

template<class T>
joint_pool<T>::~joint_pool()
{

}
#endif // JOINT_POOL_H
