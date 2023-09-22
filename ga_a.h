/*ga_a.h*/

#ifndef GA_A_H
#define GA_A_H

#include "ga_types.h"

Animal newrandanimal(int dnanum);

void printanimal(Animal a, int dnanum);

void printarray(int a[], int n);

void copyanimal(Animal dst, Animal src, int n);

#endif
