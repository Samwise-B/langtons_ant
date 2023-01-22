#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "visualiser.h"
#include "langton.h"

int main(int argc, char *argv[]) {
    struct rule *rule;
    char *rule_string;
    int count;
    if (argc == 1) {
        count = 3;
        // set rules to argument
        rule_string = "LR";
    }

    if (argc == 2) {
        // loop over ruleset, ensure format is correct and count size for memory allocation
        count = 1;
        char c = argv[1][0];
        while (c != '\0') {
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

        // set rules to argument
        rule_string = argv[1];
    }
    if (argc > 2) {
        printf("Usage: ./ant <ruleset>\n");
        printf("E.g. ./ant LLR\n");
        exit(1);
    }

    // allocate rule struct memory
    rule = malloc(sizeof(struct rule));
    if (rule == NULL) {
        printf("Error creating rules, exiting...\n");
        return 1;
    }

    // set rules to argument
    rule->rules = rule_string;

    // create ant
    struct ant *ant;
    ant = malloc(sizeof(struct ant));
    if (ant == NULL) {
        printf("Error creating ant, exiting...\n");
        return 1;
    }
    // start visualisation
    start_visualisation(ant);

    // loop until 'q' pressed
    while(not_quit()) {
        visualise_and_advance(ant, rule);
    }
    
    end_visualisation();
    // free memory for any and rule
    free(ant);
    free(rule);
    ant = NULL;
    rule = NULL;
    return 0;
}