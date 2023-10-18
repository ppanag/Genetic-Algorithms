/*ga_a.h*/

#ifndef GA_A_H
#define GA_A_H

#include "ga_types.h"

Genome newrandgenome(int dnanum);

void printgenome(Genome a, int dnanum);

void printarray(int a[], int n);

void copygenome(Genome dst, Genome src, int n);

#endif
