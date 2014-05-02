/**
 * Dining Philosophers Problem  
 * Carlos Agudo
 */

#include <unistd.h> 
#include <stdlib.h> 
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>


/*** DECLARE RANDOM FACTOR AND POSSIBLE STATES ***/
#define RANDOM_FACTOR 5
#define PHILOSOPHERS 6
#define THINKING 0
#define HUNGRY 1 
#define EATING 2

/*** SOME VARIABLES ***/
pthread_mutex_t forkSemaphore[PHILOSOPHERS];
int philoStates[PHILOSOPHERS];
int currentlyUsedForks[PHILOSOPHERS];
static int philoMeals[PHILOSOPHERS];
static int notFedAll = 1;

/*** SOME FUNCTIONS ***/
void grabFork(int philo, int forkIndex);
void putDownFork(int philo, int forkIndex);
void * thoughtProcess(void *philo);


int main() {
    pthread_t philoThread[PHILOSOPHERS];   
    int philosopherNumbers[PHILOSOPHERS];  
    int i;
    
    for (i = 0; i < PHILOSOPHERS; i++) {
        philoStates[i] = THINKING; 
        currentlyUsedForks[i] = 0;
        philosopherNumbers[i] = i;
        pthread_mutex_init(&forkSemaphore[i], NULL); //Initialize mutexes with a 0
        pthread_create(&philoThread[i], NULL, thoughtProcess, &philosopherNumbers[i]); 
    }
    printf("\n /*** Philosopers are THINKING ***/\n");
    
    for (i = 0; i < PHILOSOPHERS; i++) {
        pthread_join(philoThread[i], NULL); //Rejoin the threads after all the philosophers have eaten
    }
}

/*** RANDOMIZES STATE CHANGE FROM THINKIG TO HUNGRY ***/
void isPhilosopherGettingHungry(int philo){
    if (rand() % RANDOM_FACTOR == 0 ) { 
        philoStates[philo] = HUNGRY;
        printf("Philosopher %d is HUNGRY\n", philo);
    }
    sleep(1);
}

void makePhiloGrabbForksAndEat(int philo){
    if (philo % 2 == 0) {   
        grabFork(philo, philo);   
        grabFork(philo, (philo + 1) % PHILOSOPHERS);  
    } else {    
        grabFork(philo, (philo + 1) % PHILOSOPHERS);  
        grabFork(philo, philo);   
    }
    philoStates[philo] = EATING;
    printf("Philosopher %d is EATING\n", philo);
}

void grabFork(int philo, int forkIndex) {
    pthread_mutex_lock(&forkSemaphore[forkIndex]);    //Waits for fork and locks it
    currentlyUsedForks[forkIndex]++;
    printf("Philosopher %d is GRABBING fork# %d\n", philo, forkIndex);
    if (currentlyUsedForks[forkIndex] > 1) {
        printf("MORE THAN ONE PHILOSOPHER GRABBED SAME FORK\n");   
    }
    sleep(1);
}

void putDownFork(int philo, int forkIndex) {
    printf("Philosopher %d is PUTTING DOWN fork# %d\n", philo, forkIndex);
    currentlyUsedForks[forkIndex]--;
    pthread_mutex_unlock(&forkSemaphore[forkIndex]);  //Sets the mutex for fork available
    sleep(1);
}

void checkIfAllPhilosophersWereFed(int philo){
    notFedAll = 0;
    philoMeals[philo]+=1;
    for(int i = 0; i < 6; i++){
        if(philoMeals[i] == 0){
            notFedAll = 1;
        }
    }   
    if( notFedAll == 0){
        printf("\n/*** Philosophers Result ***/\n");
        for(int i = 0; i < 6; i++){
            printf("Philosopher# %d had %d meals\n" ,i,philoMeals[i]);
        }
        exit(1);
    }
}

/*** RANDOMIZES STATE CHANGE FROM EATING TO THINKING ***/
void isPhilosopherGettingFull(int philo){
    if (rand() % RANDOM_FACTOR == 0 ) { 
        if (philo % 2 == 0) {
            putDownFork(philo, philo);  
            putDownFork(philo, (philo + 1) % PHILOSOPHERS);  
        } else {
            putDownFork(philo, (philo + 1) % PHILOSOPHERS);  
            putDownFork(philo, philo);    
        }
        philoStates[philo] = THINKING;
        printf("Philosopher %d is THINKING\n", philo);
    }
}

/*** PROCESS FROM THINKIGN to HUNGRY to EATINK and BACK  ***/
void *thoughtProcess(void *philo) {
    while (1) {
        int philPosition = *((int*)philo);
        if (philoStates[philPosition] == THINKING) {
            isPhilosopherGettingHungry(philPosition);
        } else if (philoStates[philPosition] == HUNGRY) {
            makePhiloGrabbForksAndEat(philPosition);
        } else if (philoStates[philPosition] == EATING) {
            isPhilosopherGettingFull(philPosition);
        } 
        sleep(1);
    }
    return 0;
}




