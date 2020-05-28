// C program to implement sighup(), sigint()
// and sigquit() signal functions

#include "poem.h"


int access_queue() // access queue using unique key
{
    key_t key = ftok("server.c", 'E');
    if (key == -1)
        perror("ftok");
    int poem_id = msgget(key, 0);
    if (poem_id == -1)
        perror("msgget");

    return poem_id;
}

void write_value(int id, char *category) // function to add message to the queue
{
    // Poem p;
    int r;
    int poem_sig_type = 25;
    char *chosen_category;
    strcpy(chosen_category, category);

    r = msgsnd(id, &chosen_category, sizeof chosen_category - sizeof poem_sig_type, 0); // Data is placed on to a message queue
    if (r == -1)
        perror("msgsnd");
}

int main()
{
    int poem_id = access_queue();
    char category_num[10][10] = { "SIGINT" , "SIGQUIT" };
    char *category = category_num[rand() % sizeof(sizeof((category_num)) / sizeof((category_num[0])))];
    write_value(poem_id, category);

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