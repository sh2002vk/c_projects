#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void shell_loop(){
    char* input = NULL;
    size_t len = 0;     // size_t is always positive, used to represent size of objects

    while (1) {
        getline(&input, &len, stdin);   // use this instead of scanf to read whole line at once
        input[strcspn(input, "\n")] = 0;          // get rid of newline

        if (strcmp(input, "END") == 0) {
            printf("ENDING PROGRAM\n");
            break;
        } else {
            printf("%s", input);
            printf("\n");
        }
    }
    free(input);
}

int main(int argc, char* argv[]){
    // LOAD FILES

    // RUN EXECUTION LOOP
    shell_loop();

    // SHUTDOWN COMMANDS

    return 0;
}

