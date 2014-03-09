/* 
** 
** CMSI387: Operating System
** access.c
**
** Description: TThis program demonstrates invocation of the access // JD: OOK.
** system call (33) using the syscall function.
**
** Contributions made by Abdul Alzaid, Carlos Agudo, and Jonathan Piatos
**
*/

#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/unistd.h>
#include <unistd.h> 
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    //Only check access for read only
    int result = syscall(33, argv[1], R_OK);

    if (result == 0) {
    	//message used simply for testing the syscall
        // JD: The phrasing of your message can be better.  As it is, it sounds
        //     like this program *gives* access to the file---it doesn't; it
        //     just checks if it is there.
        char *successMessage = "Read Access is Granted\n";
        syscall(4, 2, successMessage, strlen(successMessage));
    }
    // JD: Along the same lines, because this system call *checks* for the
    //     availability of a permission, I think it is fair to expect it to
    //     also provide a message in case access is *not* available.
}
