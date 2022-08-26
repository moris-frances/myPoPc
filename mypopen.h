#ifndef MYPOPEN_H
#define MYPOPEN_H

#include <stdio.h>
#include <stdlib.h>

//popen(command, "r") returns a file pointer (to a pipe) 
//where the output of the shell command can be read.

//popen(command, "w") returns a file pointer (to a pipe) where where the
//input to the shell command command can be written to
FILE *mypopen(char *command, char rights);
//waits for all processes to finish and closes the file descriptor returned by mypopen()
void mypclose(FILE * fd);

#endif