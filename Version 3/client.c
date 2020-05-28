// C program to implement sighup(), sigint()
// and sigquit() signal functions

#include "poem.h"

void signal_handler(int signal)
{
    int poem_id = access_queue();
    /* Display a message indicating we have received a signal */
    if (signal == SIGINT)
    {
        printf("\nSend a SIGINT signal to server.\n");
        write_value(poem_id, SIGINT);
    }
    else if (signal == SIGQUIT)
    {
        printf("\nSend a SIGQUIT signal to server.\n");
        write_value(poem_id, SIGQUIT);
    }
    exit(1);
}


int main()
{
    if (signal(SIGINT, signal_handler) == SIG_ERR)
    {
        printf("\ncan't catch SIGINT\n");
    }
    if (signal(SIGQUIT, signal_handler) == SIG_ERR)
    {
        printf("\ncan't catch SIGQUIT\n");
    }
 
    // A long long wait so that we can easily issue a signal to this process
    while (1)
        sleep(1);

    return 0;
}

int access_queue() // access queue using unique key
{
    int poem_id;
    key_t key = ftok("server.c", 'E');
    if (key == -1)
        perror("ftok");
    poem_id = msgget(key, 0);
    if (poem_id == -1)
        perror("msgget");
    return poem_id;
}

void write_value(int id, int signal) // function to add message to the queue
{
    struct poem p;
    p.msg_type = 25;
    p.signal = signal;
    int r;
    r = msgsnd(id, &p, sizeof p - sizeof p.msg_type, 0); // Data is placed on to a message queue
    if (r == -1)
        perror("msgsnd");
}
