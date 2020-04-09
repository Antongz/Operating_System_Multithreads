#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 

void *threadSum(void *var) 
{ 
    int *myid = (int *)var;
    static int sum = 0; // static sum to be shared by all threads
    sum++;
    printf("\tThreadId: %d <> StaticSum: %d \n", *myid, sum); 
} 
  
int main() 
{   system("clear");
    pthread_t tid[3];
    // Creating 3 threads
    for (int i = 0; i < 3; i++){
    	/*
    	arg 1 : Pointer to the thread identifier
    	arg 2 : Pointer to the structure of Attibutes
    	arg 3 : Subroutine to be executed by thread
    	arg 4 : Arguments to the subroutine
    	*/
        pthread_create(&tid[i], NULL, threadSum, (void *)&tid[i]); 
    }
    // exit code
    pthread_exit(NULL); 
    return 0; 
} 