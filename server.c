#include "poem.h"

int main()
{
    int poem_id = create_queue();
    struct poem p;
    p = read_value(poem_id);
    printf("Main queue read.");

    // kill(getpid(), rand(SIGINT, SIGQUIT);
    // for (int i = 0; i < 100; i++)
    // {
        if (p.mtext == 1)
        {
            printf("\nServer recieves Japanese\n");
        }
        else if (p.mtext == 2)
        {
            printf("\nServer recieves Western\n");
        }
        // sleep(1);
    // }
    printf("Main class accessed. Server was stopped.\n");
    remove_queue(poem_id);
    return 0;

}

int create_queue()
{
    key_t key = ftok("server.c", 'E'); // generating a unique key
    if (key == -1)
        perror("ftok");

    int msg_id = msgget(key, IPC_CREAT | 0666);
    if (msg_id == -1)
        perror("msgget");
    printf("Queue created\n");
    return msg_id;
}

void remove_queue(int id)
{
    int r;
    r = msgctl(id, IPC_RMID, NULL); // destroy message queue
    if (r == -1)
        perror("msgctl");
    printf("Queue removed\n");
}

struct poem read_value(int id)
{
    struct poem p;
    int r;
    r = msgrcv(id, &p, sizeof p - sizeof p.msg_type , 25, 0); //message is retrieved from a queue
    if (r == -1)
        perror("msgrcv");
    return p;
}