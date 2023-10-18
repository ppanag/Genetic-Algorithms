/* ga_nextg.h  */

#ifndef GA_NEXTG_H
#define GA_NEXTG_H

#include "ga_types.h"

void nextgen(Population *old, Population *new, int roulettenum, int beststay, float mutdist,
             float mutp, float base, int score[]);

#endif
