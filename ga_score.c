/* ga_score.c  */
#include "ga_score.h"
#include "ga_fight.h"
#include "ga_types.h"
#include "z_err.h"
#include <stdlib.h>

extern int dnanum;

void scoreeval(Population *a, int score[], int (*costfunction)(Genome)) {
  int n, i;
  n = a->num;
  for (i = 0; i < n; i++) {
    score[i] = onescore(a->a[i], costfunction);
  }
}

int onescorex(Genome a) {
  int i, n, s = 0;
  float x, y;
  n = dnanum;
  for (i = 0; i < n; i++) {
    x = a.dna[i] / 65.0 - 2;
    y = -x * x * (x + 1) * (x - 1.1);
    s += (int)(100 * y);
  }
  return s;
}

void adjustscore(int score[], int goodscore[], int n) {
  int i, min = 32000, max = -32000;
  for (i = 0; i < n; i++) {
    if (score[i] < min)
      min = score[i];
    if (score[i] > max)
      max = score[i];
  }
  check(max < 16001);
  for (i = 0; i < n; i++)
    goodscore[i] = score[i] - min + 1;
}

extern int CH;
void scoreeval2(Population *a, int score[]) {
  int i, j, k, sk;
  for (i = 0; i < a->num; i++)
    score[i] = 0;
  for (i = 0; i < CH; i++)
    for (j = 0; j < a->num; j++)
      for (k = 0; k < a->num; k++) {
        sk = fight(a->a[j], a->a[k]);
        score[j] += sk;
        score[k] -= sk;
      }
}

int onescore(Genome a, int (*costfunction)(Genome)) { return costfunction(a); }
