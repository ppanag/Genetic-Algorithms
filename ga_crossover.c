/* ga_crossover.c */

#include "ga_crossover.h"
#include "ga_types.h"
#include "rnd.h"
#include "z_err.h"
#include <assert.h>
#include <stdlib.h>
extern int rdebug;
static int ready = 0;
static int randnum = 0;

/* max roulette space */
#define MAXR 4000
static byte roulette[MAXR]; /*an zwa>255 kanto int */

void crossover(Genome p1, Genome p2, Genome child, float mut, float mutp,
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

void buildrandgenomeforcrossover(int score[], int n, int roulettenum,
                                 float base) {
  int i, k, j, m, min, max, critical;
  long s, s2;

  if (rdebug > 1)
    for (i = 0; i < n; i++) {
      check(score[i] >= 0);
    }

  check(roulettenum <= MAXR);
  check(base > 0 && base < 1);
  min = 32700;
  max = -1;
  for (i = 0; i < n; i++) {
    if (score[i] < min)
      min = score[i];
    else if (score[i] > max)
      max = score[i];
  }
  critical = min + base * (max - min);
  for (i = 0; i < n; i++)
    if (score[i] < critical)
      score[i] = 0;

  s = 0;
  for (i = 0; i < n; i++)
    s += score[i];
  j = 0;
  s2 = s / 2;
  for (i = 0; i < n; i++) {
    m = (int)((score[i] * roulettenum + s2) / s);
    /* rounded??  */
    for (k = 0; k < m; k++) {
      roulette[j] = i;
      j++;
    }
  }

  randnum = j;
  ready = 1;
  check(randnum <= MAXR);
  if (rdebug > 9) {
    printf("rletnum=%d randnum=%d\n", roulettenum, randnum);
    for (i = 0; i < roulettenum + 2; i++)
      printf("%4d", roulette[i]);
  }
}

int randgenomeforcrossover() {
  assert(ready);
  return roulette[rand() % randnum];
}

void findbestgenomes(int score[], int n, int b, int best[]) {
  register int j, k, i;
  int value[50];
  int v;

  check(b < 50);
  for (j = 0; j < b; j++)
    value[j] = -32767;
  for (i = 0; i < n; i++) {
    v = score[i];
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
