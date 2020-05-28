// C program to implement sighup(), sigint()
// and sigquit() signal functions

#include "poem.h"


int access_queue() // access queue using unique key
{
    int poem_id;
    key_t key = ftok("server.c", 'E');
    if (key == -1) perror("ftok");
    poem_id = msgget(key, 0);
    if (poem_id == -1) perror("msgget");
    return poem_id;
}

void write_value(int id, int category) // function to add message to the queue
{
    // Poem p;
    int r;
    int poem_sig_type = 25;
    r = msgsnd(id, &category, sizeof(category), 0); // Data is placed on to a message queue
    if (r == -1) perror("msgsnd");
}

int r2()
{
    srand(time(NULL));
    int number = (rand() % 2  + 1);
    return number;
}

int main()
{
    int poem_id = access_queue();
    int category = r2();
    printf("i choose %d \n" , category);
    write_value(poem_id, category);
    printf("i wrote %d \n" , category);


    return 0;
}
