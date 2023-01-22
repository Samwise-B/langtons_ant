#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "visualiser.h"
#include "langton.h"

//#define cell_at(y, x) (cells[x + y * max_x])
//char *cell_states = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(int argc, char *argv[]) {
    struct rule *rule;
    char *rule_string;
    int count;
    if (argc == 1) {
        count = 3;
        // set rules to argument
        rule_string = "LR";
    }
    //printf("%d\n", argc);
    if (argc == 2) {
        // loop over ruleset, ensure format is correct and count size for memory allocation
        count = 1;
        char c = argv[1][0];
        while (c != '\0') {
            //printf("%c\n", c);
            // check the ruleset has correct format
            if (c != 'L' && c != 'R') {
                printf("ruleset must consist of only L and R. E.g. 'LRLRLR'\n");
                exit(1);
            }
            c = argv[1][count];
            count++;
        }
        if (count > 37) {
            printf("ruleset cannot be longer than 36 characters\n");
            exit(1);
        }

        //printf("%d\n", count);
        // create struct
        // set rules to argument
        rule_string = argv[1];
    }
    if (argc > 2) {
        printf("Usage: ./ant <ruleset>\n");
        printf("E.g. ./ant LLR\n");
        exit(1);
    }

    // allocate rule struct memory
    rule = malloc(sizeof(char) * (count));
    if (rule == NULL) {
        printf("Error creating rules, exiting...\n");
        return 1;
    }

    // set rules to argument
    rule->rules = rule_string;
    //printf("rule->rules: %s\n", rule->rules);

    // create ant
    struct ant *ant;
    ant = malloc(sizeof(struct ant));
    if (ant == NULL) {
        printf("Error creating ant, exiting...\n");
        return 1;
    }
    // start visualisation
    start_visualisation(ant);
    /*
    cell *cells;
    

    max_x = 5;
    max_y = 5;
    cells = calloc(max_y*max_x, sizeof(cell));
    ant->x = max_x/2;
    ant->y = max_y/2;
    ant->direction = RIGHT;

    //printf("cell: %d %d", WHITE, BLACK);
    
    int row, col;
    count = 0;

    // enter main loop
    //not_quit()
    //count <= 5
    */
    while(not_quit()) {
        /*
        printf("ant: (%d, %d) %d\n", ant->x, ant->y, ant->direction);

        
        for (row=0; row < max_y; row++) {
            for (col=0; col < max_x; col++) {
                //printf("%d %d", row, col);
                //int c = cell_to_s(row, col, cells);
                printf("%c", cell_states[cell_at(row, col)]);
                //printf("%d", cells[row * max_y + col]);
            };
            printf("\n");
        };
        
        //cell_at(ant->y, ant->x)
        //apply_rule(&cell_under_ant, ant);

        apply_rule_general(&cell_at(ant->y, ant->x), ant, rule);

        
        move_forward(ant);
        count++;
        */
        visualise_and_advance(ant, rule);
    }
    //free(cells);
    end_visualisation();
    // free memory for any and rule
    free(ant);
    free(rule);
    ant = NULL;
    rule = NULL;
    return 0;
}