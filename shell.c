#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <limits.h>

void get_current_path(char* path, size_t path_size){
    getcwd(path, path_size);
}

int list_directory(char* path){
    DIR *d;             // a directory object
    struct dirent *dir; // used to navigate directories

    d = opendir(path);
    printf("STARTING DIRECTORY\n\n---");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            printf("%s\n", dir->d_name);
            printf("---\n");
        }
        closedir(d);
    }
    printf("\n\nENDING DIRECTORY\n");
    return 0;
}

int enter(char* path, char* directory) {
    strcat(path, directory); // add to path. note that path already has the size of a max directory
    if (chdir(path) != 0) {
        return 1;
    }
    return 0;

}

void handle_system_commands(char* commands) {
    printf("commands s: %s\n", commands);
}

void handle_file_commands(char* commands){
    char path[PATH_MAX];
    get_current_path(path, sizeof(path));
    if (path[0] == '\0') {
        printf("unable to find current path\n");
        return;
    }

    // Parse commands for usage by internal functions
    char* words[256];
    int wordCount = 0;

    char* word = strtok(commands, " ");
    while(word != NULL) {
        words[wordCount++] = word;
        word = strtok(NULL, " ");
    }

    if (wordCount == 0) {
        printf("No operation provided\n");
        return;
    }

    // Handle the operations
    if (!strcmp(words[0], "list")) {
        list_directory(path);
    } else if (!strcmp(words[0], "print")) {
        printf("current path: %s\n", path);
    } else if (!strcmp(words[0], "enter")) {
        if (enter(path, words[1]) != 0) {  // words [1] is the directory we're going into
            printf("failed to enter directory %s\n", words[1]);
        } else {
            get_current_path(path, sizeof(path));   // update the current path
            printf("changed to directory: %s\n",path);
        }
    } else {
        printf("invalid operation\n");
    }
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

