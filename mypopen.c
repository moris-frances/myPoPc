#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/wait.h>


FILE *mypopen(char *command, char rights){

    char *args[] = {"/usr/bin/sh","-c", command, NULL};

    //pipe ends file descriptors
    //fd[0] - read
    //fd[1] - write
    int fd[2];
    if(pipe(fd)==-1){
         fputs("pipe problem\n",stderr);
    }

    
    int pid = fork();

    if(pid==-1){
        fputs("pid problem\n",stderr);
        return NULL;
    }

    if(rights=='r'){
        if(pid == 0){

            //inside the child process
            close(fd[0]);
            fd[1] = dup2(fd[1], STDOUT_FILENO);
            execv(args[0], args);
            close(fd[1]);
            
        }else{
            //parent process
            FILE *pipefdRead = fdopen(fd[0],"r"); 
            close(fd[1]);
            return pipefdRead;
        }
    }else if(rights=='w'){

        if(pid == 0){

            //inside the child process
            close(fd[1]);
            fd[0]= dup2(fd[0], STDIN_FILENO);
            execv(args[0], args);
        }else{
            
            //parent process
            FILE *pipefdWrite = fdopen(fd[1],"w");
            close(fd[0]);
            //returning the write end of the pipe
            return pipefdWrite;
        }

    
    }
    fputs("Only options are \"r\" and \"w\" \n",stderr);
    return NULL;

    
}

int mypclose(FILE * fd){
    int fdStat = fclose(fd);
    wait(&fdStat);
    return 0;
}





