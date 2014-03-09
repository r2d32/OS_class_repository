/*
** 
** CMSI387: Operating System
** chmod.c // JD: You mean open.c.  Watch your copy-pastes.
**
** This program demonstrates invocation of the open system call
** (5) using the syscall function.  Some of its output is then displayed.
**
** Contributions made by Abdul Alzaid, Carlos Agudo, and Jonathan Piatos
**
*/

#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/stat.h> 
#include <fcntl.h> 
#include <linux/unistd.h>
#include <unistd.h> 
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // JD: This looks like it is invoked just fine, but in the end it is not
    //     a good choice for a standalone command because its usefulness is
    //     not really apparent unless you have additional follow-up activities.
	int result = syscall(5, argv[1], O_RDONLY, 00400);

	if (result > 0) {
        // JD: "Permission" is spelled with 2 s's.  And what exactly is a
        //     "user permission descriptor?"
		printf("Opened file with user permision Descriptor %d\n", result);
	} else if (result == -1){
		char *errorMessage = "Could not open file\n";
		syscall(4, 2, errorMessage, strlen(errorMessage));
	}

}
