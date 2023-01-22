#ifndef visualiser_h
#define visualiser_h

#include "langton.h"
#include <stdbool.h>

static int max_x;
static int max_y;

typedef enum colour cell;

// to pass max X and max Y between files properly
int get_max_x();
int get_max_y();

void start_visualisation();
void visualise_and_advance();
bool not_quit();
cell cell_at_fct(int y, int x); //optional
void end_visualisation();
const char* direction_to_s(enum direction d);
int cell_to_s(int y, int x);

#endif