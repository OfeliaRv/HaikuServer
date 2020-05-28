#include "poem.h"

int main()
{
    char japanese_haikus[100][100] = {"1.txt", "2.txt", "3.txt", "4.txt", "5.txt", "6.txt"};
    char western_haikus[100][100] = {"1.txt", "2.txt", "3.txt", "4.txt", "5.txt", "6.txt", "7.txt", "8.txt"};

    int my_poem_id = create_queue();
    Poem p[MAX]; //messages stored to an array
    int count = 100;

    for (int i = 0; i < count; i++)
    {
        p[count] = read_value(my_poem_id); //reads value it 0th place in messages array
    }

    printf("Main class accessed. Server was stopped.");
    remove_queue(my_poem_id);

    return 0;
}

int create_queue()
{
    key_t key = ftok("/etc/passwd", 'E'); // generating a unique key
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

Poem read_value(int id)
{
    Poem p;
    int r;
    r = msgrcv(id, &p, sizeof p - sizeof p.poem_type, 25, 0); //message is retrieved from a queue
    if (r == -1)
        perror("msgrcv");
    printf("%s\n", p.poem_text);
    return p;
}