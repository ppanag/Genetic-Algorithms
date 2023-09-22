/* ga_skor.,h */

#ifndef GA_SKOR_H
#define GA_SKOR_H

#include "ga_types.h"

void skoreval(Agelh *a, int skor[]);

void adjustskor(int skor[], int goodskor[], int n);

int oneskor(Animal a);

#endif
