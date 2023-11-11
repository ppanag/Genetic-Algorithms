#include "terminal_gui.h"
#include "ga_types.h"
#include "z_err.h"
#include <stdio.h>

#define WIDTH 100
#define HEIGHT 40

void drawPoints(byte px[], byte py[], int n) {
  // Clear the screen
  printf("\033[2J");
  for (int i = 0; i < n; i++) {
    int x = (px[i] * WIDTH) / 255;  // Scale x coordinate
    int y = (py[i] * HEIGHT) / 255; // Scale y coordinate

    // Ensure coordinates are within bounds
    x = (x < 0) ? 0 : (x >= WIDTH) ? WIDTH - 1 : x;
    y = (y < 0) ? 0 : (y >= HEIGHT) ? HEIGHT - 1 : y;

    // Draw point
    printf("\033[%d;%dH*", y + 1, x + 1);
  }
  printf("\033[%d;%dH ", HEIGHT + 1, 0);
}

void terminal_draw(Genome a) {
  static byte px[11000], py[11000];
  int i, n;
  n = (a.dnanum) / 2 + 2;
  check(n < 11000);
  px[0] = 250;
  py[0] = 0;
  px[n - 1] = 5;
  py[n - 1] = 0;
  for (i = 1; i < n - 1; i++) {
    px[i] = a.dna[i - 1];
    py[i] = a.dna[n - 3 + i];
  }
  drawPoints(px, py, n);
}
