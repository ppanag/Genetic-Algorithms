/* ga.h --genetic algorithm */

#ifndef GA_H
#define GA_H

#include "ga_types.h"

void ga_init(int dnan, int genomen);

void ga_params(int roulettenum, int beststay, float mutdist, float mutp,
               float base);

void ga_run(long gens, int (*costfunction)(Genome));

void ga_printbests(int m);

#endif
