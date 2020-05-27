// C program to implement sighup(), sigint()
// and sigquit() signal functions

#include "poem.h"

int access_queue()  // access queue using unique key
{
    key_t key = ftok ("/etc/passwd", 'E') ;
    if (key == -1) perror ("ftok");
    int poem_sig_id = msgget(key, 0);
    if (poem_sig_id == -1) perror("msgget");

    return poem_sig_id;
}

void write_value(int id, char* text)  // function to add message to the queue
{
    Poem p; 
    int r;
    p.poem_sig_type = 25;
    strcpy(p.poem_text, text);

    r = msgsnd (id , &p, sizeof p - sizeof p.poem_sig_type , 0);     // Data is placed on to a message queue
    if (r == -1) perror("msgsnd");
}

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