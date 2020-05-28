// C program to implement sighup(), sigint()
// and sigquit() signal functions

#include "poem.h"

int main()
{
    struct poem p;
    int poem_id = access_queue();
    int type = r2();
    printf("Client sends [%d] \n", type);
    write_value(poem_id, type);
    return 0;
}


int access_queue() // access queue using unique key
{
    int poem_id;
    key_t key = ftok("reader.c", 'E');
    if (key == -1)
        perror("ftok");
    poem_id = msgget(key, 0);
    if (poem_id == -1)
        perror("msgget");
    return poem_id;
}

void write_value(int id, int category) // function to add message to the queue
{
    struct poem p;
    p.msg_type = 25;
    p.category = category;
    int r;
    r = msgsnd(id, &p, sizeof p - sizeof p.msg_type, 0); // Data is placed on to a message queue
    if (r == -1) perror("msgsnd");
}

int r2()
{
    srand(time(NULL));
    return (rand() % 2 + 1);
}
