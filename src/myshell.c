#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


#define MAX_BUFFER 1024                        // max line buffer
#define MAX_ARGS 64                            // max # args
#define SEPARATORS " \t\n"                     // token separators

int main (int argc, char ** argv)
{
    char buf[MAX_BUFFER];                      // line buffer
    char * args[MAX_ARGS];                     // pointers to arg strings
    char ** arg;                               // working pointer thru args
    //char * prompt = "==>" ;                    // shell prompt
    /* keep reading input until "quit" command or eof of redirected input */

    start();
    
    while (!feof(stdin)) { 
        /* get command line from input */
        prompt();

        if (fgets (buf, MAX_BUFFER, stdin )) { // read a line
            /* tokenize the input into args array */
            arg = args;
            *arg++ = strtok(buf,SEPARATORS);   // tokenise input

            while ((*arg++ = strtok(NULL,SEPARATORS)));

            if(args[0] == NULL) // keeps shell running after external command input
            {
                continue;
            }
 
            /* check for internal/external command */
            if (!strcmp(args[0],"clr")) { // "clear" command
                system("clear");
                continue;
            }

            if (!strcmp(args[0],"cd")) { // "cd" command
                cd(args);
                continue;
            }

            if (!strcmp(args[0],"dir")) { // "dir" command
                dir();
                continue;
            }

            if (!strcmp(args[0],"echo")) { // "echo" command
                echo(args);
                continue;
            }

            if (!strcmp(args[0],"pause")) { // "pause" command
                shellPause();
                continue;
            }

            if (!strcmp(args[0],"environ")) { // "environ" command
                environStr(args);
                continue;
            }

            if (!strcmp(args[0],"help")) { // "help" command
                system("more ../manual/readme.md");
                continue;
            }

            if (!strcmp(args[0],"quit")) {   // "quit" command
                break;    // breaks the loop
            }       

            else {
                externalCMD(args); // calls external commands function
                continue;
            }
        }
    }
}


/*
Student Name: Dylan Corbari
Student Number: 20341171
In submitting this project, I declare that the project material, which I now submit, is my own work. Any assistance received by ways of online resources has been cited and acknowledged within my work. I make this declaration in the knowledge that a breach of the rules pertaining to project submission will carry serious consequences including a mark of 0 for this assignment.
*/
