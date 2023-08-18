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
to open and access directories. Currently does NOT support going back directories. It starts from the root and 
goes as deeper from there.
  
