#include "poem.h"

int main()
{
    int arr[2] = { SIGINT , SIGQUIT };
    struct poem p;
    int poem_id = access_queue(); 
    
    for (int i = 1; i <= 100; i++)
    {
        int n = r2();   // generating random array index between 0 and 1
        int category = arr[n];
        printf("Client sends [%d]: %d \n", i, category);
        write_value(poem_id, category);  // writing to the queue, sends to server 
        sleep(1);
    }

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

void write_value(int id, int category) // function to add message to the queue
{
    struct poem p;
    p.msg_type = 25;
    p.mtext = category;
    int r;
    r = msgsnd(id, &p, sizeof p - sizeof p.msg_type, 0); // Data is placed on to a message queue
    if (r == -1)
        perror("msgsnd");
}

int r2()  // generates random value between 0 and 1
{
    srand(clock());
    return (rand() % 2);
}