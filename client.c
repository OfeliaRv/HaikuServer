// C program to implement sighup(), sigint()
// and sigquit() signal functions
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

// function declaration
void sigint();
void sigquit();
void choose_signal(int num);
int r2();

int main()
{
    int pid;
    int num;
    /* get child process */
    if ((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }
    for (int i = 0; i < 100; i++)
    {
        if (pid == 0)
        { /* child */

            num = r2();
            if (num == 0)
            {
                sigint();
            }
            else if (num == 1)
            {
                sigquit();
            }
        }
        //  for (;;)
        //     ; /* loop for ever */

        else /* parent */
        {    /* pid hold id of child */

            sleep(1); /* pause for 1 sec */
            printf("\nPARENT: sending SIGINT\n\n");
            kill(pid, SIGINT);

            sleep(1); /* pause for 1 sec */
            printf("\nPARENT: sending SIGQUIT\n\n");
            kill(pid, SIGQUIT);
            sleep(1);
        }
    }
    return 0;
}
void sigint()
{
    signal(SIGINT, sigint); /* reset signal */
    printf("CHILD: I have received a SIGINT\n");
}
void sigquit()
{
    printf("My DADDY has Killed me!!!\n");
    exit(0);
}


int r2()
{
    srand(time(NULL));
    return (rand() % 2);
}