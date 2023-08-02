#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_directory

void handle_system_commands(char* commands) {
    printf("commands s: %s\n", commands);
}

void handle_file_commands(char* commands){
    printf("commands f: %s\n", commands);
}


void process_command(char* type, char* commands) {
    printf("operation: %s\n", type);
    if (strcmp(type, "file") == 0) {
        handle_file_commands(commands);
    } else if (strcmp(type, "system") == 0) {
        handle_system_commands(commands);
    } else {
        printf("INVALID COMMAND CALL\n");
    }
}

void shell_loop(){
    char* input = malloc(256 * sizeof(char));
    size_t len = 0;                        // size_t is always positive, used to represent size of objects

    while (1) {
        getline(&input, &len, stdin);      // use this instead of scanf to read whole line at once
        input[strcspn(input, "\n")] = 0;   // get rid of newline

        if (strcmp(input, "END") == 0) {
            printf("ENDING PROGRAM\n");
            break;
        } else {
            char* type = strtok(input, " ");
            char* commands = strtok(NULL, "\n");
            process_command(type, commands);
        }
    }

    free(input);
}

int main(int argc, char* argv[]){
    // TODO: LOAD FILES

    // RUN EXECUTION LOOP
    shell_loop();

    // TODO: SHUTDOWN COMMANDS

    return 0;
}

