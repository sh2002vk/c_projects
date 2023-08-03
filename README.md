# Projects in C
A repo to store fun projects i'm making to improve my understanding of c. Mostly building low level systems from scratch.
Refer to the project list at the end of the readme for details.

## How to run:
- ```gcc <filename>.c -o <filename>.exe```
- ```./<filename>.exe [args]```

## Project List
### Command line calculator
[*Project*](https://github.com/sh2002vk/c_projects/blob/main/calculator.c) \
Simple program in C that carries out addition, subtraction, multiplication and 
division from command line arguments. Error checking is implemented, but maybe it can be made more robust. \
Expected format: *X OPERAND Y*

### Directory Navigator
[*Project*](https://github.com/sh2002vk/c_projects/blob/main/file_navigator.c) \
A c program that mimicks the ls, cd and open commands from the command line. Uses the dirent library
to open and access directories. Currently does NOT support going back directoeries. It starts from the root and 
goes as deeper from there. 

### Shell from scratch
[*Project*](https://github.com/sh2002vk/c_projects/blob/main/shell.c) \
A simple, unix-based shell with the following command schema: 
| TYPE    | OPERATION | ARGS       | NOTES                             | IMPLEMENTED |
| ------- | --------- | ---------- | --------------------------------- | ----------- |
| file    | list      | NONE       | List all files                    | YES         |
| file    | print     | NONE       | Print the current path            | YES         |
| file    | enter     | directory  | Go into a directory               | YES         |
| file    | make      | filename   | Make a new file in given directory| NO          |
| system  | status    | NONE       | Get current running processes     | NO          |
| system  | resources | NONE       | Current resource use              | NO          |
| system  | info      | NONE       | Returns OS and version            | NO          |
| system  | free      | NONE       | Free disk space left              | NO          |

Most of the actual operations are yet to be implemented. I will also add process creation and destruction.  

  
