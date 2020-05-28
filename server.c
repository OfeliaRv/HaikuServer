#include "poem.h"

int main()
{
    int poem_id = create_queue();
    printf("my id is %d \n", poem_id);

    int category = read_value(poem_id);
    printf("Main queue read.");

    // kill(getpid(), rand(SIGINT, SIGQUIT);
    // for (int i = 0; i < 100; i++)
    // {
        if (category == 1)
        {
            printf("japanese\n");
        }
        else if (category == 2)
        {
            printf("western\n");
        }
        // sleep(1);
    // }
    printf("Main class accessed. Server was stopped.");
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
    printf("myyyyyyyyy id is %d \n", msg_id);
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

int read_value(int id)
{
    printf("i entered.");

    int r;
    int category;
    r = msgrcv(id, &category, sizeof(category) , 25, 0); //message is retrieved from a queue
    printf("i recieved.");
    if (r == -1)
        perror("msgrcv");
    printf("%d\n", category);

    return category;
}