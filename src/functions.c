#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
#include "functions.h"

#define MAX_BUFFER 1024                        // max line buffer
#define MAX_ARGS 64                            // max # args
#define SEPARATORS " \t\n"                     // token sparators

void start() // welcome screen to the os
{  
    printf("-------------------------------"); 
    printf("\n\n\t----  Dylans Shell  ----"); 
    printf("\n\n\t-CA216 Assignment-");
    printf("\n\n\tName: Dylan Corbari");
    printf("\n\n\tStudent Number: 20341171");
    printf("\n\n-------------------------------"); 
    char* username = getenv("USER"); 
    printf("\n\nUSER is: @%s", username);
    printf("\nType \"help\" to access this shell's user manual. *must be ran from bin/src/manual directory*");
    printf("\n");
    printf("\n");
}

void prompt() // displays the prompt for input commands
{
    char cwd[1024];
    getcwd(cwd, sizeof(cwd)); // gets the cwd
    printf("\n%s$ ", cwd); // prints the cwd
}

void cd(char *argv[])
{
    char cdir[128];
    getcwd(cdir, sizeof(cdir));

    if(argv[1] == NULL) {
        printf("%s\n", cdir); //print current directory
    }

    else {
        chdir(argv[1]);
        getcwd(cdir, sizeof(cdir));
        setenv("PWD", cdir, 1);
    }
}

void dir() // used https://www.geeksforgeeks.org/c-program-list-files-sub-directories-directory/ and https://www.tutorialspoint.com/c-program-to-list-all-files-and-sub-directories-in-a-directory
{          // neither really worked so took out some return 1 stuff they had
    struct dirent *de;  // Pointer for directory entry
  
    // opendir() returns a pointer of DIR type. 
    DIR *dr = opendir(".");
  
    if (dr == NULL)  // opendir returns NULL if couldn't open directory
    {
        printf("Could not open current directory" );
    }
  
    while ((de = readdir(dr)) != NULL)
            printf("%s\n", de->d_name);
  
    closedir(dr);    
}

void echo(char *argv[])
{
    int i;
    for (int i = 1; argv[i]; i=i+1)
        printf("%s ", argv[i]);

    printf("\n");
}

void shellPause()
{
    printf("press enter to continue\n");
    while(getchar() != '\n');
}

void environStr(char **args) // got from lab 4D
{
    extern char **environ;

    for(int i=0; environ[i] != NULL; i++)
        printf("%s\n",environ[i]);
}

int externalCMD(char **args) // used https://brennan.io/2015/01/16/write-a-shell-in-c/ section labelled "How shells start processes"
{
	pid_t pid, wpid;
  	int status;

  	pid = fork();
	if (pid == 0) {
    // Child process
    if (execvp(args[0], args) == -1) {
    	perror("myshell");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    // Error forking
    perror("myshell");
  } else {
    // Parent process
    do {
      	wpid = waitpid(pid, &status, WUNTRACED);
    } 
	while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
}

/*
Student Name: Dylan Corbari
Student Number: 20341171
In submitting this project, I declare that the project material, which I now submit, is my own work. Any assistance received by ways of online resources has been cited and acknowledged within my work. I make this declaration in the knowledge that a breach of the rules pertaining to project submission will carry serious consequences including a mark of 0 for this assignment.
*/
