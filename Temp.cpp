#include <iostream>
#include"Genetic_Algorithm.h"
#include"Population.h"

using namespace std;

int main()
 {
Population<float>P(20);
Genetic_Algorithm<float> G(P);

return 0;

}
