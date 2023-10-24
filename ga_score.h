/* ga_score.,h */

#ifndef GA_SCORE_H
#define GA_SCORE_H

#include "ga_types.h"

void scoreeval(Population *a, int score[], int (*costfunction)(Genome));

void adjustscore(int score[], int goodscore[], int n);

int onescore(Genome a, int (*costfunction)(Genome));

#endif
