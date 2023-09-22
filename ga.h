/* ga.h --genetic algorithm */

#ifndef GA_H
#define GA_H

#include "ga_types.h"

void ga_init(int dnan, int animaln);

void ga_params(int ruletenum, int beststay, float mutdist, float mutp,
               float base);

void ga_exelixi(long gens);

void ga_printbests(int m);

#endif
