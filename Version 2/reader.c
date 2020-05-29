#include "poem.h"

int main()
{
    int poem_id = create_queue();    // creating queue and assigning its id value
    struct poem p;

    p = read_value(poem_id);

    // printing 3 random Haikus of the same type
    read_haiku(p.category);
    read_haiku(p.category);
    read_haiku(p.category);

    printf("Main class accessed. Server was stopped.\n");
    remove_queue(poem_id);    //removing queue
    return 0;
}

int create_queue()
{
    key_t key = ftok("reader.c", 'E');     // generating a unique key
    if (key == -1)
        perror("ftok");

    int msg_id = msgget(key, IPC_CREAT | 0666);
    if (msg_id == -1)
        perror("msgget");
    printf("Queue created\n\n"); 

    return msg_id;
}

void remove_queue(int id)
{
    int r;
    r = msgctl(id, IPC_RMID, NULL); // destroy message queue
    if (r == -1)
        perror("msgctl");
    printf("Queue removed\n\n");
}

struct poem read_value(int id)
{
    struct poem p;
    int r;
    r = msgrcv(id, &p, sizeof p - sizeof p.msg_type, 25, 0); //message is retrieved from a queue
    if (r == -1)
        perror("msgrcv");
    return p;
}

void read_haiku(int category)
{
    char japanese_haikus[100][100] = {"1.txt", "2.txt", "3.txt", "4.txt", "5.txt", "6.txt"};
    char western_haikus[100][100] = {"1.txt", "2.txt", "3.txt", "4.txt", "5.txt", "6.txt", "7.txt", "8.txt"};
    if (category == 1)
    {
        char ch;
        char haiku[100];
        int rand = r6();      // random Haiku between 0 and 6 
        strcpy(haiku, japanese_haikus[rand]);  // copying randomly chosen Haiku to the haiku[] array
        char path[20] = "japanese/";   // identifying path
        FILE *fp = fopen(strcat(path, haiku), "r");
        while ((ch = fgetc(fp)) != EOF)
        {
            printf("%c", ch);
        }
        printf("\n\n");

    }
    else if (category == 2)
    {
        char ch;
        char haiku[100];
        int rand = r8();    // random Haiku between 0 and 8 
        strcpy(haiku, western_haikus[rand]);       // copying randomly chosen Haiku to the haiku[] array
        char path[20] = "western/";     // identifying path
        FILE *fp = fopen(strcat(path, haiku), "r");
        while ((ch = fgetc(fp)) != EOF)
        {
            printf("%c", ch);
        }
        printf("\n\n");
    }
    sleep(1);
}

int r6()    // generates random number between 0 and 6
{
    srand(clock());
    return (rand() % 6);
}

int r8()    // generates random number between 0 and 6
{
    srand(clock());
    return (rand() % 8);
}