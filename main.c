
#include "ga.h"
#include "rnd.h"
#include "zz_costfunction.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// debug level
int rdebug = 5;

int main(int n, char **arg) {
  long g = 1;
  // get number of generations from command
  if (n > 1)
    g = atol(arg[1]);
  rndseed();
  printf("\n***** g=%ld\n", g);

  ga_init(100, 50);
  ga_params(1000, 5, 2, .1, .01);
  ga_run(g, costfunction1);
  ga_printbests(1);
  return 0;
}
