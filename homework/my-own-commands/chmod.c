/* 
**
** CMSI387: Operating System
** chmod.c
**
** Description: This program demonstrates invocation of the chmod
** system call (15) using the syscall function.  
**
** Contributions made by Abdul Alzaid, Carlos Agudo, and Jonathan Piatos
**
*/

#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/unistd.h>
#include <unistd.h> 
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // JD: OK but still hardcoded.  Technically within bounds of the assignment,
    //     but really, with 3 brains working on this, you couldn't have done
    //     *some* argument parsing so that this command becomes more flexible?
	int result = syscall(15, argv[1], 00004);

	if (result == 0) {
		char *successMessage = "Read Access is Changed\n";
		syscall(4, 2, successMessage, strlen(successMessage));
	} else if(result == -1) {
		char *errorMessage = "Read Access could not be changed\n";
		syscall(4, 2, errorMessage, strlen(errorMessage));
	}

}
