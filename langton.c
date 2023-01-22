#include <stdio.h>
#include "langton.h"
#include "visualiser.h"
#include <ncurses.h>

void turn_left(struct ant *ant) {
    enum direction d = ant->direction;

    // handle each case of anticlockwise rotation
    if (d == UP) {
        ant->direction = LEFT;
    }
    else if (d == DOWN) {
        ant->direction = RIGHT;
    }
    else if (d == LEFT) {
        ant->direction = DOWN;
    }
    else {
        ant->direction = UP;
    }
};

void turn_right(struct ant *ant) {
    enum direction d = ant->direction;

    // handle each case of clockwise rotation
    if (d == UP) {
        ant->direction = RIGHT;
    }
    else if (d == DOWN) {
        ant->direction = LEFT;
    }
    else if (d == LEFT) {
        ant->direction = UP;
    }
    else {
        ant->direction = DOWN;
    }
};

void move_forward(struct ant *ant) {
    enum direction d = ant->direction;

    // get max_x and max_y
    int max_x = getmaxx(stdscr);
    int max_y = getmaxy(stdscr);

    if (d == UP) {
        ant->y -= 1;
        // if the ant is at the top of screen, wrap y to bottom
        if (ant->y < 0) {
            ant->y = max_y-1;
        }
    }
    else if (d == DOWN) {
        ant->y += 1;
        // if the ant is at the bottom of screen, wrap y to top
        if (ant->y >= max_y) {
            ant->y = 0;
        }
    }
    else if (d == LEFT) {
        ant->x -= 1;
        // if the ant is at the left of screen, wrap x to right
        if (ant->x < 0) {
            ant->x = max_x-1;
        }
    }
    else {
        ant->x += 1;
        // if the ant is at the right of screen, wrap x to left
        if (ant->x >= max_x) {
            ant->x = 0;
        }
    }
};

void apply_rule(enum colour *colour, struct ant *ant) {
    if (*colour == WHITE) {
        // turn right, flip cell colour
        turn_right(ant);
        *colour = BLACK;
    }
    else {
        // otherwise, turn left, flip cell colour
        turn_left(ant);
        *colour = WHITE;
    }
};

void apply_rule_general(enum colour *colour, struct ant *ant, struct rule *rule) {
    // get the current state's rule
    char state_rule = rule->rules[*colour];

    // rotate based on state's rule
    if (state_rule == 'L') {
        turn_left(ant);
    }
    else {
        turn_right(ant);
    }

    // increment state's rule
    state_rule = rule->rules[*colour + 1];

    // check if cell needs looping, otherwise increment cell
    if (state_rule == '\0') {
        *colour = 0;
    }
    else {
        *colour = *colour + 1;
    }
};