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
    Poem p;
    int r;
    p.poem_sig_type = 25;
    strcpy(p.poem_text, text);

    r = msgsnd(id, &p, sizeof p - sizeof p.poem_sig_type, 0); // Data is placed on to a message queue
    if (r == -1)
        perror("msgsnd");
}

int main()
{
    char japanese_haikus[100][100] = {"1.txt", "2.txt", "3.txt", "4.txt", "5.txt", "6.txt"};
    char western_haikus[100][100] = {"1.txt", "2.txt", "3.txt", "4.txt", "5.txt", "6.txt", "7.txt", "8.txt"};
    int category_num;

    for (int i = 0; i < 100; i++)
    {
        // category_num = r2();
        // kill(getpid(), rand(SIGINT, SIGQUIT);
        if (category_num == 0)
        {
            char ch;
            char haiku[100];
            strcpy(haiku, japanese_haikus[0]);
            char path[20] = "japanese/";
            FILE *fp = fopen(strcat(path, haiku), "r");
            while ((ch = fgetc(fp)) != EOF)
            {
                printf("%c", ch);
            }
            printf("\n");
        }
        else if (category_num == 1)
        {
            char ch;
            char haiku[100];
            strcpy(haiku, western_haikus[0]);
            char path[20] = "western/";
            FILE *fp = fopen(strcat(path, haiku), "r");
            while ((ch = fgetc(fp)) != EOF)
            {
                printf("%c", ch);
            }
            printf("\n");
        }
        sleep(1);
    }

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