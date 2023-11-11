// terminal_gui.h

#ifndef TERMINAL_GUI_H
#define TERMINAL_GUI_H

#include "ga_types.h"
#include <stdio.h>

#define WIDTH 100
#define HEIGHT 40

void drawPoints(byte px[], byte py[], int n);
void terminal_draw(Genome a);

#endif
