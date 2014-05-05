/**
 * Carlos Agudo
 * CMSI387- Assignment myshellc
 * fork-exec.c
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>


// METHOD TO EXECUTE "cd" IN THE SHELL//

// JD: OK, fine, but what kind of a name is "rjhchdir" ???
//
//     Plus, the spacing in the function declaration and if-clause
//     is quite horrible.
int rjhchdir( char * directory){
    if(directory != NULL){
        printf("You changed directory to %s.\n", directory);
        chdir(directory);
    } else {
        printf("You changed to your home directory.\n");
    }
    return 0;
}

/*******************************************************/
/* PROGRAM TO DEMOSNTRATE THE USE OF fork() AND exec() */
/*******************************************************/

int main() {

    // VARIABLES FOR THE SHELL COMMANDS //
    char *args[256];
    char command[256];
    int i;

    // JD: Uhhhh...what are these?  They are completely unused.  You put comments
    //     on some really obvious code, but for this one you say nothing???
    char line[4096] = {0};
    char safeline[4096] = {0};


    while (!feof(stdin)) {

        // POINTERS AND VARIABLES FOR THE LOOP //
        int waitCharacterPresent = 0;
        char *argument;
        char *commandContext;
        const char *spaceDelimiter = " ";
        const char *waitCharacter = "&";

        // SHELL INPUT //
        printf("Please enter command > ");
        fgets(command, 256, stdin);
        // JD: *Almost* there with proper Ctrl-D handling, but sometimes segfaulting because
        //     of something you missed regarding fgets.

        int commandLength = strlen(command);
        command[commandLength - 1] = 0;

        // REMOVE ENDING SPACES //
        // JD: while, if, and for are not functions, and so it is better to distinguish
        //     them by adding a space between the keywords and the left parenthesis.
        while(strcmp(&command[commandLength - 2], spaceDelimiter) == 0){
            command[commandLength - 2] = 0;
            commandLength--;
        }

        // EVALUATE TO REMOVE OR NOT "&" //
        if(strcmp(&command[commandLength - 2], waitCharacter) == 0){
            command[commandLength - 2] = 0;
            waitCharacterPresent = 1;
        }

        // PARSES "arguments" INTO A SEQUENCE OF COMMANDS AND SETS "i" //
        for(argument = strtok_r(command, spaceDelimiter, &commandContext), i = 0;
            argument;argument = strtok_r(NULL, spaceDelimiter, &commandContext), i++){
            args[i] = argument;
            printf( "%s\n",argument );

        }

        // ADD NULL TO MATHC THE PARAMETERS FOR "execvp()" //
        args[i] = NULL;

        // CHECK FOR THE DIFFERENT SET OF COMMANDS //
        if(strcmp(args[0], "cd") == 0) {
            if(args[1]== NULL) {
                // JD: WTF does "Pleas wite" mean?  >:-)
                printf("Pleas wite a directory after 'cd'\n");
            } else {
                // JD: I still can't get over that name. "rjh"?  You didn't copy this
                //     code from someone else did you? (with initials R.J.H.)
                rjhchdir(args[1]);
            }

        } else if(strcmp(args[0], "exit-shell") == 0) {
            printf("Exiting the shell.\n");
            break;

        } else if(strcmp(args[0], "secret-system-call") == 0) {  
            syscall(351);

        } else {

            /* Variable that will store the fork result. */
            pid_t pid;

            /* Perform the actual fork. */
            pid = fork();
            if (pid < 0) {
                /* Error condition. */
                fprintf(stderr, "Fork failed\n");
                return -1;

            } else if (pid == 0) {
                /* Child process. */
                printf("Running...\n");
                execvp(args[0], args);

            } else {
                /* Parent process. */
                int result;
                if (!waitCharacterPresent) {
                    wait(&result);
                }
                printf("All done; result = %d\n", result);
            }
        }
    } 
}