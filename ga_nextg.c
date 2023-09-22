/* ga_nextg.c  */

#include "ga_nextg.h"
#include "ga_a.h"
#include "ga_crossover.h"
#include "ga_skor.h"
#include <assert.h>

void nextgen(Agelh *old, Agelh *new, int ruletenum, int beststay, float mutdist,
             float mutp, float base, int skor[]) {
  static int goodskor[255];
  static int best[50];
  int i, j, n;
  int ifather, imother;

  assert(beststay <= 50);

  n = old->num;
  skoreval(old, skor);
  adjustskor(skor, goodskor, n);
  findbestanimals(goodskor, n, beststay, best);
  buildrandpersonforcrossover(goodskor, n, ruletenum, base);

  for (i = 0; i < beststay; i++)
    copyanimal(new->a[i], old->a[best[i]], old->dnanum);
  for (i = beststay; i < n; i++) {
    ifather = randpersonforcrossover();
    imother = randpersonforcrossover();
    crossover(old->a[ifather], old->a[imother], new->a[i], mutdist, mutp,
              old->dnanum);
  }
}
