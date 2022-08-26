#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> 
#include "mypopen.h"
#define BUFFER_LEN 100

int main(int argc, char **argv)
{
    
    FILE *fpOut = mypopen("ls", 'r');
    if(fpOut==NULL){
        return 1;
    }
    FILE *fpIn = mypopen("wc -c", 'w');
    if(fpIn==NULL){
        return 1;
    }
    char buffer[BUFFER_LEN];

    while(fgets(buffer, sizeof(buffer), fpOut)) 
    {
        fprintf(fpIn, "%s\n", buffer);
    }
    mypclose(fpOut);
    mypclose(fpIn);
    
    return 0;
}