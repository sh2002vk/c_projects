/* A c program that mimicks the cli to navigate directories
 * TODO: add more error checking and robustness
 * @sh2002vk
 * */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#define MAX_DIRS 256
#define MAX_FILES 1024
#define MAX_LEN 256

int is_directory(struct dirent* entry){
    if (entry->d_type == DT_DIR){
        return 1;
    }
    return 0;
}

int is_file(struct dirent* entry) {
    if (entry->d_type == DT_REG) {
        return 1;
    }
    return 0;
}

int main(int argc, char* argv[]){
    DIR *folder = NULL;
    struct dirent *entry = NULL;
    char* directories[MAX_DIRS];
    char* files[MAX_FILES];
    int dir_count;
    int file_count;

    int path_size = 1;
    char* path = malloc(path_size * sizeof(char));      // start with size 1
    strcat(path, "/");                                     // start at root

    folder = opendir(path);
    if(folder == NULL) {
        printf("Unable to read directory\n");
        return 1;
    } else {
        printf("Directory is opened!\n");
    }

    printf("starting at computer root\n");
    char* buf = malloc(256*sizeof(char));
    while (1){

        dir_count = 0;
        file_count = 0;

        while ((entry = readdir(folder)) != NULL) {
            // LOOP THROUGH THIS DIRECTORY
            if (is_directory(entry) && dir_count < MAX_DIRS) {
                directories[dir_count] = malloc(MAX_LEN * sizeof(char));
                if (directories[dir_count] != NULL) {  // if malloc was successful
                    strncpy(directories[dir_count], entry->d_name, MAX_LEN-1);  // leave a space for the terminator
                    directories[dir_count][MAX_LEN-1] = '\0';
                    dir_count ++;
                }
            } else if (is_file(entry) && file_count < MAX_FILES) {
                files[file_count] = malloc(MAX_LEN * sizeof(char));
                if (files[file_count] != NULL) {  // if malloc was successful
                    strncpy(files[file_count], entry->d_name, MAX_LEN-1);
                    files[file_count][MAX_LEN-1] = '\0';
                    file_count ++;
                }
            }
        }

        closedir(folder);

        // LIST DIRECTORIES AND FILES
        printf("DIRECTORIES ARE:\n");
        for (int i = 0; i < dir_count; i++) {
            if (directories[i] != NULL){
                printf("%s\n", directories[i]);
                free(directories[i]);
                directories[i] = NULL;
            }
        }
        printf("\nFILES ARE:\n");
        for (int i = 0; i < file_count; i++) {
            if (files[i] != NULL) {
                printf("%s\n", files[i]);
                free(files[i]);
                files[i] = NULL;
            }
        }

        printf("What directory would you like to go to?: ");
        char* filename = malloc(256 * sizeof(char));
        scanf("%255s", filename);
        if (strcmp(filename, "RETURN") == 0) {
            char* last = strchr(path, '/');
            if (last != path) {
                *last = '\0'; // cut off at last slash
            } else {
                path[1] = '\0'; // go back to root
            }
        } else {
            path_size += strlen(filename) + 1;
            path = realloc(path, path_size * sizeof(char));
            strcat(path, "/");
            strcat(path, filename);
        }

        if (strcmp(filename, "END") == 0) {  // 0 is true
            printf("ending..\n");
            free(filename);
            break;
        }
        free(filename);

        folder = opendir(path);
        if (folder == NULL) {
            printf("Unable to open directory: %s\n", path);
            break;
        }
    }
    free(buf);
    free(path);

    return 0;
}
