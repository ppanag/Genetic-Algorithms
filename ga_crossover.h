/* ga_crossover.h */

#ifndef GA_CROSSOVER_H
#define GA_CROSSOVER_H

#include "ga_types.h"

void crossover(Genome p1, Genome p2, Genome child, float mut, float mutp,
               int dnanum);
/* 0<mutp<1  */

void buildrandgenomeforcrossover(int score[], int n, int roulettenum, float base);

int randgenomeforcrossover();

void findbestgenomes(int score[], int n, int b, int best[]);

#endif
