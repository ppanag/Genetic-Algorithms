/* ga.c */

#include "z_err.h"
#include <assert.h>
#include <stdio.h>

#include "ga.h"
#include "ga_a.h"
#include "ga_crossover.h"
#include "ga_nextg.h"
#include "ga_types.h"

static int ready = 0;
static Agelh oldgeneration, newgeneration;
static Agelh *old, *new;
static int Ruletenum, Beststay;
static int best[200], skor[256];
static float Mutp, Mutdist, Base;
int animalnum, dnanum;

void ga_init(int dnan, int animaln) {
  int i;
  old = &oldgeneration;
  new = &newgeneration;
  old->dnanum = new->dnanum = dnanum = dnan;
  check(animalnum < 256);
  old->num = new->num = animalnum = animaln;
  if (!ready) {
    for (i = 0; i < animaln; i++) {
      new->a[i] = newrandanimal(dnan);
      old->a[i] = newrandanimal(dnan);
    }
  }
  ready = 1;
}

void ga_params(int ruletenum, int beststay, float mutdist, float mutp,
               float base) {
  check(ready);
  check(ruletenum < 3000);
  check(beststay < 50);
  check(mutdist < 200);
  check(mutp >= 0 && mutp <= 1);
  check(base >= 0 && base <= 1);

  Ruletenum = ruletenum;
  Beststay = beststay;
  Mutdist = mutdist;
  Mutp = mutp;
  Base = base;

  ready = 2;
}

void ga_exelixi(long gens) {
  long i;
  Agelh *tmp;

  check(ready > 1);
  for (i = 0; i < gens; i++) {
    tmp = old;
    old = new;
    new = tmp;
    nextgen(old, new, Ruletenum, Beststay, Mutdist, Mutp, Base, skor);
  }
}

void ga_printbests(int m) {
  int i;
  findbestanimals(skor, old->num, m, best);
  for (i = 0; i < m; i++) {
    printf("[s:%5d <", skor[best[i]]);
    printanimal(old->a[best[i]], old->dnanum);
    printf("] ");
  }
}
