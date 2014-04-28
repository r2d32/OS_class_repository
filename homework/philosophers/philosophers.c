/**
 * Dining Philosophers Problem  
 * Carlos Agudo
 */


#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>


/********** DECLARE RANDOM FACTOR AND POSSIBLE STATES **********/
#define RANDOMIZE 5
#define PHILOSOPHERS 6
#define THINKING 0
#define HUNGRY 1 
#define EATING 2

/********** SOME VARIABLES **********/
pthread_mutex_t forkSemaphore[PHILOSOPHERS];
int state[PHILOSOPHERS];
int currentlyUsedForks[PHILOSOPHERS];
static int philoMeals[PHILOSOPHERS];
static int notFedAll = 1;

/********** SOME FUNCTIONS **********/
void grabFork(int philo, int chopNum);
void putDownFork(int philo, int chopNum);
void * thoughtProcess(void *philo);

int main() {	
}

void *thoughtProcess(void *philo) {
}

void grabFork(int philo, int chopNum) {

}

void putDownFork(int philo, int chopNum) {
}


