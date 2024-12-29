#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<cmath>
#include<string>
#include<iomanip>
#include<limits>
//#include"Parent_Pool.h"

#include "Population.h"

using namespace std;

// Individual template class deceleration
template<class T>
class Individual
{
 public:
 Individual(); // default constructor
 Individual(int); // constructor that takes one argument
 static int flag; // declaring a static flag to be set to 1 when certain condition occures
 T x,y; // declaring the Individual representation for the optimization problem
 T a,b,c,d; // declaring the Individual representation for the curve fitting problem
 T HIGH; // highest value in which a, b, c and d can be
 T LOW;  // lowest value in which a, b, c and d can be
 T MAX;  // maximum value in which x and y can be
 T LOW_Residual; // the lowest residual value can be
 T HIGH_Residual; // the highest residual value can be
 T fitness1; // fitness of the optimization problem
 T fitness2; // fitness of the curve fitting problem
 string int_or_float; // string used to check if the type chosen by the user is int or float
 virtual ~Individual();  // destructor
 T f(T,T); // Langermann's function to calculate fitness for the optimization problem
 T MSE(T,T,T,T); // MSE function to calculates fitness for the curve fitting problem
 static int pick_application; // pick between the optimization application and the curve fitting application
 template<class U> friend class Population;
};

// Individual class implementation

// initializing pick_application
template<class T>
int Individual<T>::pick_application = 0;

// initializing the static flag to zero for once at compile time
template<class T>
int Individual<T>::flag = 0;

// implementation of constructor that takes one argument
template<class T>
Individual<T>::Individual(int q)
{
pick_application = q;

}

// default constructor implementation
template<class T>
Individual<T>::Individual()
{

// preventing srand from seeding the random number generator more than once in the same second
if (flag==0)
{
srand(time(0));
flag = 1;
}

// checking to see if the type selected by the user is int or float
if(sizeof(T)==sizeof(int))
{
T i = 1.55;
if(i==1)
{
int_or_float = "int";

}
else
int_or_float = "float";
}
MAX = 10.00;  // setting the maximum value, in which x and y can be, to 10
HIGH = 10;   // initializing highest value in which a, b, c and d can be
LOW = -10; // initializing the lowest value in which a, b, c and d can be
LOW_Residual = -1.00; //initializing the lowest residual value can be
HIGH_Residual = 1.00; //initializing the highest residual value can be

// for the optimization problem
if(pick_application == 0)
{
// making sure that the generic type is not a character
if(sizeof(x)!= sizeof(char)&&int_or_float!="int")
{
x = static_cast <T> (rand()) / (static_cast <T> (RAND_MAX/MAX)); // generating random value between 0 and 10
y = static_cast <T> (rand()) / (static_cast <T> (RAND_MAX/MAX)); // generating random value between 0 and 10
fitness1 = f(x,y);
}
else
{
cout<<"x and y cannot be initialized since the type selected is int while this program is designed to work with type float, please change the type to int and run the program again"<<endl<<"if u need the program to work with integer, contact the programmer"<<endl;
}
}

// for the curve fitting problem
if(pick_application==1)
{
// generating random values for a, b, c and d between LOW_Residual and HIGH_Residual
if(sizeof(a)!=sizeof(char))
{
a = LOW + static_cast <T> (rand()) /( static_cast <T> (RAND_MAX/(HIGH-LOW)));
b = LOW + static_cast <T> (rand()) /( static_cast <T> (RAND_MAX/(HIGH-LOW)));
c = LOW + static_cast <T> (rand()) /( static_cast <T> (RAND_MAX/(HIGH-LOW)));
d = LOW + static_cast <T> (rand()) /( static_cast <T> (RAND_MAX/(HIGH-LOW)));
fitness2 = MSE(a,b,c,d);
}
else
{
cout<<"a, b, c and d cannot be initialized since the type selected is int while this program is designed to work with type float, please change the type to int and run the program again"<<endl<<"if u need the program to work with integer, contact the programmer"<<endl;
}

}

}

// Langermann's function
template<class T>
T Individual<T>::f(T x,T y)
{
const int m = 5;  // the size of c array
const int k = 5;  // the size of a and b arrays
T a[k] = {3,5,2,1,7}; // constant a used in Langermann's equation
T b[k] = {5,2,1,4,9}; // constant b used in Langermann's equation
T c[m] = {1,2,5,2,3} ; // constant c used in Langermann's equation
T c_summation = 0; // the summation of c

// computing the summation of c
for(int i = 0;i<5;i++)
c_summation+=c[i];
T fitness = 0; // fitness, using the optimization problem, initialization

// solving for the fitness using Langermann's equation for the 2D version
for(int i = 0;i<5;i++)
fitness = fitness + exp(-1*pow((x-a[i]),2)/M_PI-pow((y-b[i]),2)/M_PI)*cos(M_PI*pow((x-a[i]),2)+ M_PI*((y-b[i]),2));
fitness*=c_summation;
// fitness has been computed

cout.precision(32);
return fitness; // returning the fitness result
}

// mean squared error function
template<class T>
T Individual<T>::MSE(T a,T b,T c,T d)
{
const int num_sets = 10; // number of sets
const int num_pts = 20; // number of points per set
const int total_num_of_pts = num_pts*num_sets; // 20 points needed for each of the 10 tests for the curve fitting problem
T X[num_sets][num_pts];  // x-coordinate on each point
T best_Y[num_sets][num_pts]; // the equation that best fit the points
T Y_hat[num_sets][num_pts]; // the vector of 200 predictions, 20 for each test
T MSE = 0; // mean squared error initialized
T MSE_array[num_sets]; // array that holds the MSE of each set
T e[num_sets][num_pts]; // Residuals

// setting the x-coordinates of the points
for(int i = 0;i<num_sets;i++)
{
for(int j=0;j<num_pts;j++)
{
if(i==0&&j==0)
X[i][j] = 0;
else
X[i][j]= X[i][j-1]+1;
}
}

// Residuals generated randomly
for(int i = 0;i<num_sets;i++)
{
for(int j =0;j<num_pts;j++)
{
e[i][j] = LOW_Residual + static_cast <T> (rand()) /( static_cast <T> (RAND_MAX/(HIGH_Residual-LOW_Residual)));
}
}
// solving for Y values
for(int i = 0;i<num_sets;i++)
{
for(int j =0;j<num_pts;j++)
{
best_Y[i][j] = a*pow(X[i][j],3)+b*pow(X[i][j],2)+c*X[i][j]+d; // solving for values of predicted values of y
Y_hat[i][j] = a*pow(X[i][j],3)+b*pow(X[i][j],2)+c*X[i][j]+d+e[i][j]; // solving for the Y values that corresponds to the X values
}
}
// Computing the MSE of each set
for(int i = 0;i<num_sets;i++)
{
for(int j = 0;j<num_pts;j++)
{
if(j==(num_pts-1))
{
MSE = MSE + pow((Y_hat[i][j]-best_Y[i][j]),2);
MSE/=num_pts;
MSE_array[i]= MSE;
MSE = 0;
}
else
{
MSE = MSE + pow((Y_hat[i][j]-best_Y[i][j]),2);
}
}
}
// computing the fitness of the curve fitting problem which is the average MSE over 10 sets
for(int i = 0;i<num_sets;i++)
fitness2 += MSE_array[i];
fitness2/=num_sets;
return fitness2; // returning fitness
}

// destructor
template<class T>
Individual<T>::~Individual()
{

}










#endif // INDIVIDUAL_H
