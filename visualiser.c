#include <ncurses.h>
#include <locale.h>
#include <stdlib.h>
#include "visualiser.h"

#define cell_at(y, x) (cells[x + y * max_x])
#define cell_under_ant cell_at(ant->y, ant->x)
cell *cells;
static char *cell_states;

// get max_x and get max_y are used to pass the static var to langton.c for torus wrapping
int get_max_x() {
   return max_x;
};

int get_max_y() {
   return max_y;
};

void start_visualisation(struct ant* ant) {
   // initialise the ncurses library, setting the 2D plane's width
   setlocale(LC_ALL, "");
   initscr();
   curs_set(FALSE);
   max_x = getmaxx(stdscr);
   max_y = getmaxy(stdscr);

   // initialise cells, ant's coords and direction
   cells = calloc(max_y*max_x, sizeof(cell));
   ant->x = max_x/2;
   ant->y = max_y/2;
   ant->direction = RIGHT;

   // initialise cell states string for rendering
   cell_states = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}

void visualise_and_advance(struct ant* ant, struct rule* rule) {
      /* Draw cells and ant */
      for (int y=0; y<max_y; y++)
      {
         for (int x=0; x<max_x; x++)
         {
            mvprintw(y,x,
               ant_is_at(y,x)
                 ? direction_to_s(ant->direction)
                 : (cell_at(y,x) > 0)
                    ? "%c", &cell_states[cell_at(y, x)]
                    : " "
            );
         }
      }
      refresh();
      
      /* Advance to next step */
      //cell_at(ant->y, ant->x)
      // apply_rule(&cell_under_ant, ant)
      apply_rule_general(&cell_under_ant, ant, rule);
      move_forward(ant);
}

// Check if the user has input "q" to quit
bool not_quit() {
   return 'q' != getch();
}

void end_visualisation() {
   free(cells);
   endwin();
}

// returns a chevron to visualise the ant's direction
const char* direction_to_s(enum direction d) {
   return UP   == d ? "^" :
          DOWN == d ? "v" :
          LEFT == d ? "<" :
          /* else */  ">" ;
}

