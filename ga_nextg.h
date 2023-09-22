/* ga_nextg.h  */

#ifndef GA_NEXTG_H
#define GA_NEXTG_H

#include "ga_types.h"

void nextgen(Agelh *old, Agelh *new, int ruletenum, int beststay, float mutdist,
             float mutp, float base, int skor[]);

#endif
