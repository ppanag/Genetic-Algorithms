/* ga.c */

#include <stdio.h>
#include "ga.h"
#include "ga_a.h"
#include "ga_crossover.h"
#include "ga_nextg.h"
#include "ga_types.h"
#include "z_err.h"

static int ready = 0;
static Population oldgeneration, newgeneration;
static Population *old, *new;
static int Roulettenum, Beststay;
static int best[200], score[256];
static float Mutp, Mutdist, Base;
int genomenum, dnanum;


void ga_init(int dnan, int genomen) {
  int i;
  old = &oldgeneration;
  new = &newgeneration;
  old->dnanum = new->dnanum = dnanum = dnan;
  check(genomenum < 256);
  old->num = new->num = genomenum = genomen;
  if (!ready) {
    for (i = 0; i < genomen; i++) {
      new->a[i] = newrandgenome(dnan);
      old->a[i] = newrandgenome(dnan);
    }
  }
  ready = 1;
}


void ga_params(int roulettenum, int beststay, float mutdist, float mutp,
               float base) {
  check(ready);
  check(roulettenum < 3000);
  check(beststay < 50);
  check(mutdist < 200);
  check(mutp >= 0 && mutp <= 1);
  check(base >= 0 && base <= 1);
  Roulettenum = roulettenum;
  Beststay = beststay;
  Mutdist = mutdist;
  Mutp = mutp;
  Base = base;
  ready = 2;
}


void ga_run(long gens, int (*costfunction)(Genome)) {
  long i;
  Population *tmp;
  check(ready > 1);
  for (i = 0; i < gens; i++) {
    tmp = old;
    old = new;
    new = tmp;
    nextgen(old, new, costfunction, Roulettenum, Beststay, Mutdist, Mutp, Base,
            score);
  }
}


void ga_printbests(int m) {
  int i;
  findbestgenomes(score, old->num, m, best);
  for (i = 0; i < m; i++) {
    printf("[s:%5d <", score[best[i]]);
    printgenome(old->a[best[i]], old->dnanum);
    printf("] ");
  }
}
