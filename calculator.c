/* A simple cli calculator program
 * @sh2002vk
 * */

#include <stdio.h>
#include "stdlib.h"
#include <ctype.h>
#include "string.h"

int is_valid(char* input){
    if (input == NULL){
        return 0;
    }
    int seen = 0;

    if (*input == '+' || *input == '-') {
        input++;
    }

    while (*input != '\0'){
        if (!seen && *input == '.'){
            seen = 1;
        }
        else if ((!seen || seen) && !isdigit(*input)) {
            return 0;
        }
        input++;
    }
    return 1;
}

int main(int argc, char* argv[]) {
    // input format: x + y

    if (argc != 4){
        fprintf(stderr, "not enough or too many args");
        return 1;
    }

    if (!is_valid(argv[1]) || !is_valid(argv[3])){
        fprintf(stderr, "inputs not valid");
        return 1;
    }

    float start = atof(argv[1]);
    float end = atof(argv[3]);

    if (strlen(argv[2]) != 1) {
        fprintf(stderr, "operand not valid");
        return 1;
    }

    char operation = argv[2][0];    // argv[2] is a string, so argv[2][0] is getting the first char of that string
    float output;

    if (operation == '+') {
        output = (float) (start + end);
    } else if (operation == '-') {
        output = (float) (start - end);
    } else if (operation == '*') {
        output = (float) (start * end);
    } else if (operation == '/') {
        // update the 0 check to account for float instability using fabs function from math lib
        if (end == 0) {
            fprintf(stderr, "division by %f not allowed", end);
            return 1;
        }
        output = (float) (start / end);
    } else{
        fprintf(stderr, "unrecognized operand");
        return 1;
    }

    fprintf(stdout, "%f", output);
    return 0;
}
