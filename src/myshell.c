// to do: add more functions (fix help)

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_BUFFER 1024                        // max line buffer
#define MAX_ARGS 64                            // max # args
#define SEPARATORS " \t\n"                     // token separators

int main (int argc, char ** argv)
{
    int flag = 0;
    int arraySize = 0;

    char *realArray [arraySize];

    char buf[MAX_BUFFER];                      // line buffer
    char * args[MAX_ARGS];                     // pointers to arg strings
    char ** arg;                               // working pointer thru args
    char *function = realArray[0], *option = realArray[1];
    char * prompt = "==>" ;                    // shell prompt
    /* keep reading input until "quit" command or eof of redirected input */

    while (!feof(stdin)) { 
        /* get command line from input */
        fputs (prompt, stdout); // write prompt

        if (fgets (buf, MAX_BUFFER, stdin )) { // read a line
            /* tokenize the input into args array */
            arg = args;
            *arg++ = strtok(buf,SEPARATORS);   // tokenise input

            while ((*arg++ = strtok(NULL,SEPARATORS)));

            // last entry will be NULL 
            if (args[0]) {                     // if there's anything there
            /* check for internal/external command */
            if (!strcmp(args[0],"clr")) { // "clear" command
                system("clear");
                continue;
            }

            if (!strcmp(args[0],"dir")) { // "lists contents of the directory" command
                system("ls -al");
                continue;
            }

            if (!strcmp(args[0],"cd")) { // "cd" command
                system("");
                continue;
            }

            if(strcmp(function, "help") == 0){
                flag = 1;
                if(strcmp(option, "clr\n") == 0){
                system("sed -n -e 1,16p ../manual/readme");
                continue;
            }

            if (!strcmp(args[0],"quit"))   // "quit" command
                break;                     // break out of 'while' loop
            
            /* else pass command onto OS (or in this instance, print them out) */
            arg = args;
            while (*arg) {
                fprintf(stdout,"%s ",*arg++);
                fputs ("\n", stdout);
            }
        }
    }
    return 0; 
}
}
}