#include "poem.h"
  

void choose_signal();
  
void main() 
{ 
    int pid; 
  
    /* get child process */
    if ((pid = fork()) < 0) { 
        perror("fork"); 
        exit(1); 
    } 
  
    if (pid == 0) { /* child */
        signal(SIGINT, sigint); 
        signal(SIGQUIT, sigquit); 
        for (;;) 
            ; /* loop for ever */
    } 
  
    else /* parent */
    { /* pid hold id of child */
  
        sleep(3); /* pause for 3 secs */
        printf("\nPARENT: sending SIGINT\n\n"); 
        kill(pid, SIGINT); 
  
        sleep(3); /* pause for 3 secs */
        printf("\nPARENT: sending SIGQUIT\n\n"); 
        kill(pid, SIGQUIT); 
        sleep(3); 
    } 
} 
  

void choose_signal(int number){
    if (number = 1){
        signal(SIGINT, sigint); /* reset signal */
        printf("CHILD: I have received a SIGINT\n"); 
    }
    else if (number = 0){
        printf("My DADDY has Killed me!!!\n"); 
        exit(0); 
    }
}
