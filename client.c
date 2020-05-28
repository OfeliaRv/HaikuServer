// C program to implement sighup(), sigint()
// and sigquit() signal functions

#include "poem.h"


int access_queue() // access queue using unique key
{
    key_t key = ftok("/etc/passwd", 'E');
    if (key == -1)
        perror("ftok");
    int poem_sig_id = msgget(key, 0);
    if (poem_sig_id == -1)
        perror("msgget");

    return poem_sig_id;
}

void write_value(int id, char *text) // function to add message to the queue
{
    // Poem p;
    int r;
    p.poem_sig_type = 25;
    strcpy(p.poem_text, text);

    r = msgsnd(id, &p, sizeof p - sizeof p.poem_sig_type, 0); // Data is placed on to a message queue
    if (r == -1)
        perror("msgsnd");
}

int main()
{
    char category_num[] = { SIGINT , SIGQUIT};
    char category = category_num[rand() % sizeof(sizeof((category_num)) / sizeof((category_num[0])))];

    return 0;
}

// void sigint()
// {
//     signal(SIGINT, sigint); /* reset signal */
//     printf("CHILD: I have received a SIGINT\n");
// }

// void sigquit()
// {
//     printf("My DADDY has Killed me!!!\n");
//     exit(0);
// }

// int r2()
// {
//     srand(time(NULL));
//     return (rand() % 2);
// }