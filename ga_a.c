/* ga_a.c ---some functions*/

#include "ga_a.h"
#include "ga_types.h"
#include "z_err.h"
#include <stdio.h>
#include <stdlib.h>

Genome newrandgenome(int dnanum) {
  int i;
  Genome a;
  a.dna = malloc(dnanum);
  if (a.dna == NULL)
    error("cant malloc randgenome");
  for (i = 0; i < dnanum; i++)
    a.dna[i] = rand() % 256;
  return a;
}

void printgenome(Genome a, int dnanum) {
  int i;
  for (i = 0; i < dnanum; i++)
    printf("%3d ", a.dna[i]);
}

void printarray(int a[], int n) {
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", a[i]);
  puts("");
}

void copygenome(Genome dst, Genome src, int n) {
  register int i;
  for (i = 0; i < n; i++)
    dst.dna[i] = src.dna[i];
}
