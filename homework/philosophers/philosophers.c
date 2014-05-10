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

        // JD: This "console log" approach to providing feedback is technically correct,
        //     but in the end is not very readable---one needs to read vertically and
        //     keep track of who does what manually.  This defeats the very purpose of
        //     the output, which is to let people easily perceive the state of the
        //     system and detect how errors arise.  Better approach is to print a
        //     "snapshot" of the philosophers and forks---this will tell the user what
        //     is going on at that moment,
        printf("Philosopher %d is HUNGRY\n", philo);
    }
    sleep(1);
}

void makePhiloGrabbForksAndEat(int philo){
    // JD: OK, asymmetry, I can go with that...
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
        // JD: This is a violation---you should bail out right here.
        exit(-1);
    }
    sleep(1);
}

void putDownFork(int philo, int forkIndex) {
    printf("Philosopher %d is PUTTING DOWN fork# %d\n", philo, forkIndex);
    // JD: You can also sanity-check here---make sure that the fork is indeed
    //     being used before putting it down.
    currentlyUsedForks[forkIndex]--;
    pthread_mutex_unlock(&forkSemaphore[forkIndex]);  //Sets the mutex for fork available
    sleep(1);
}

// JD: I see what you're trying to do here but this function is actually never called.
//     Presumably this part is unfinished.
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




