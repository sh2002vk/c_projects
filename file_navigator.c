/* A project to mimick the bash functions to navigate directories, built in C
 * @sh2002vk
 * */
#include <stdio.h>
#include <dirent.h>

int main(int argc, char* argv[]){
    DIR *folder;
    folder = opendir(".");

    if(folder == NULL)
    {
        puts("Unable to read directory");
        return(1);
    }
    else
    {
        puts("Directory is opened!");
    }
    closedir(folder);

    return 0;
}