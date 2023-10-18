/* ga_nextg.c  */

#include "ga_nextg.h"
#include "ga_a.h"
#include "ga_crossover.h"
#include "ga_score.h"
#include <assert.h>

void nextgen(Population *old, Population *new, int roulettenum, int beststay,
             float mutdist, float mutp, float base, int score[]) {
  static int goodscore[255];
  static int best[50];
  int i, j, n;
  int ifather, imother;

  assert(beststay <= 50);

  n = old->num;
  scoreeval(old, score);
  adjustscore(score, goodscore, n);
  findbestgenomes(goodscore, n, beststay, best);
  buildrandgenomeforcrossover(goodscore, n, roulettenum, base);

  for (i = 0; i < beststay; i++)
    copygenome(new->a[i], old->a[best[i]], old->dnanum);
  for (i = beststay; i < n; i++) {
    ifather = randgenomeforcrossover();
    imother = randgenomeforcrossover();
    crossover(old->a[ifather], old->a[imother], new->a[i], mutdist, mutp,
              old->dnanum);
  }
}
