/* ga_crossover.h */

#ifndef GA_CROSSOVER_H
#define GA_CROSSOVER_H

#include "ga_types.h"

void crossover(Animal p1, Animal p2, Animal child, float mut, float mutp,
               int dnanum);
/* 0<mutp<1  */

void buildrandpersonforcrossover(int skor[], int n, int ruletenum, float base);

int randpersonforcrossover();

void findbestanimals(int skor[], int n, int b, int best[]);

#endif
