#include <stdio.h>
#include "langton.h"
#include "visualiser.h"
#include <ncurses.h>

void turn_left(struct ant *ant) {
    enum direction d = ant->direction;

    //printf("turn left\n");
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

    //printf("turn right\n");
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
    //printf("dir: %d\n", ant->direction);
};

void move_forward(struct ant *ant) {
    //printf("MOVING\n");
    //printf("%d %d\n", ant->x, ant->y);
    enum direction d = ant->direction;

    // get max_x and max_y
    int max_x = getmaxx(stdscr);
    int max_y = getmaxy(stdscr);

    //printf("max_x, max_y: %d %d", get_max_x(), get_max_y());

    if (d == UP) {
        //printf("move up\n");
        ant->y -= 1;
        // if the ant is at the top of screen, wrap y to bottom
        if (ant->y < 0) {
            ant->y = max_y-1;
        }
    }
    else if (d == DOWN) {
        ant->y += 1;
        //printf("move down: %d, max: %d\n", ant->y, max_y);
        // if the ant is at the bottom of screen, wrap y to top
        if (ant->y >= max_y) {
            ant->y = 0;
        }
    }
    else if (d == LEFT) {
        //printf("move left\n");
        ant->x -= 1;
        // if the ant is at the left of screen, wrap x to right
        if (ant->x < 0) {
            ant->x = max_x-1;
        }
    }
    else {
        //printf("move right\n");
        ant->x += 1;
        // if the ant is at the right of screen, wrap x to left
        if (ant->x >= max_x) {
            ant->x = 0;
        }
    }
};

void apply_rule(enum colour *colour, struct ant *ant) {
    //printf("cell colour: %d\n", *colour);
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
    //printf("APPLYING RULE: %s\n", rule->rules);
    // get the current state's rule
    char state_rule = rule->rules[*colour];
    //printf("cell state: %d, state rule: %c\n", *colour, state_rule);

    // rotate based on state's rule
    if (state_rule == 'L') {
        //printf("turn left\n");
        turn_left(ant);
    }
    else {
        //printf("turn right\n");
        turn_right(ant);
    }

    // increment state's rule
    state_rule = rule->rules[*colour + 1];
    //printf("state rule (check): %c\n", state_rule);

    // check if cell needs looping, otherwise increment cell
    if (state_rule == '\0') {
        //printf("looping\n");
        *colour = 0;
    }
    else {
        //printf("incrementing\n");
        *colour = *colour + 1;
    }
    //printf("new state: %d, new state rule: %c\n", *colour, state_rule);
};