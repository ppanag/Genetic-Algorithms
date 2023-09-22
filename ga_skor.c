/* ga_skor.c  */
#include "ga_skor.h"
#include "z_err.h"
#include "ga_fight.h"
#include "ga_types.h"
#include <stdlib.h>

extern int dnanum;

void skoreval(Agelh *a, int skor[]) {
  int n, i;
  n = a->num;
  for (i = 0; i < n; i++) {
    skor[i] = oneskor(a->a[i]);
  }
}

int oneskorex(Animal a) {
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

void adjustskor(int skor[], int goodskor[], int n) {
  int i, min = 32000, max = -32000;
  for (i = 0; i < n; i++) {
    if (skor[i] < min)
      min = skor[i];
    if (skor[i] > max)
      max = skor[i];
  }
  check(max < 16001);
  for (i = 0; i < n; i++)
    goodskor[i] = skor[i] - min + 1;
}

extern int CH;
void skoreval2(Agelh *a, int skor[]) {
  int i, j, k, sk;
  for (i = 0; i < a->num; i++)
    skor[i] = 0;
  for (i = 0; i < CH; i++)
    for (j = 0; j < a->num; j++)
      for (k = 0; k < a->num; k++) {
        sk = fight(a->a[j], a->a[k]);
        skor[j] += sk;
        skor[k] -= sk;
      }
}

#define ppp(x, y) (0)
#include "sail.h"
int oneskor(Animal a) {
  static float px[11000], py[11000];
  int i, n;
  float t;
  n = dnanum / 2 + 2;
  check(n < 11000);
  px[0] = 250.0;
  py[0] = 0.0;
  px[n - 1] = 5.0;
  py[n - 1] = 0.0;
  for (i = 1; i < n - 1; i++) {
    px[i] = (float)(a.dna[i - 1]);
    ppp("%f ", px[i]);
    py[i] = (float)(a.dna[n - 3 + i]);
  }
  t = sailtime(px, py, n);
  if (t > 2.1E9)
    t = 2.1E9;
  return -(int)t;
}
