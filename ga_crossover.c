/* ga_crossover.c */

#include "ga_crossover.h"
#include "z_err.h"
#include "ga_types.h"
#include "rnd.h"
#include <assert.h>
#include <stdlib.h>
extern int rdebug;
static int ready = 0;
static int randnum = 0;

/* max roulete space */
#define MAXR 4000
static byte rulete[MAXR]; /*an zwa>255 kanto int */

void crossover(Animal p1, Animal p2, Animal child, float mut, float mutp,
               int dnanum) {
  float s, dnachild;
  int i;
  for (i = 0; i < dnanum; i++) {
    s = (1 - mutp) * mut + mutp * abs(p1.dna[i] - p2.dna[i]);
    dnachild = (p1.dna[i] + p2.dna[i]) / 2.0 + gauss(0, s);
    if (dnachild < 0)
      dnachild = 0.0;
    if (dnachild > 255)
      dnachild = 255.0;
    child.dna[i] = (byte)dnachild;
  }
}

void buildrandpersonforcrossover(int skor[], int n, int ruletenum, float base) {
  int i, k, j, m, min, max, critical;
  long s, s2;

  if (rdebug > 1)
    for (i = 0; i < n; i++) {
      check(skor[i] >= 0);
    }

  check(ruletenum <= MAXR);
  check(base > 0 && base < 1);
  min = 32700;
  max = -1;
  for (i = 0; i < n; i++) {
    if (skor[i] < min)
      min = skor[i];
    else if (skor[i] > max)
      max = skor[i];
  }
  critical = min + base * (max - min);
  for (i = 0; i < n; i++)
    if (skor[i] < critical)
      skor[i] = 0;

  s = 0;
  for (i = 0; i < n; i++)
    s += skor[i];
  j = 0;
  s2 = s / 2;
  for (i = 0; i < n; i++) {
    m = (int)((skor[i] * ruletenum + s2) / s);
    /* rounded??  */
    for (k = 0; k < m; k++) {
      rulete[j] = i;
      j++;
    }
  }

  randnum = j;
  ready = 1;
  check(randnum <= MAXR);
  if (rdebug > 9) {
    printf("rletnum=%d randnum=%d\n", ruletenum, randnum);
    for (i = 0; i < ruletenum + 2; i++)
      printf("%4d", rulete[i]);
  }
}

int randpersonforcrossover() {
  assert(ready);
  return rulete[rand() % randnum];
}

void findbestanimals(int skor[], int n, int b, int best[]) {
  register int j, k, i;
  int value[50];
  int v;

  check(b <= 50);
  for (j = 0; j < b; j++)
    value[j] = -32767;
  for (i = 0; i < n; i++) {
    v = skor[i];
    for (j = b - 1; j >= 0; j--) {
      if (v <= value[j])
        break;
    }
    k = j + 1;
    if (k < b) {
      for (j = b - 2; j >= k; j--) {
        value[j + 1] = value[j];
        best[j + 1] = best[j];
      }
      value[k] = v;
      best[k] = i;
    }
  }
}
