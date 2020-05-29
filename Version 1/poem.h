#ifndef __POEM__
#define __POEM__

#include <stdio.h>                  // printf(),perror(), file functions
#include <stdlib.h>                 // exit(), srand(), rand()
#include <sys/msg.h>                // msgget(), msgsnd(), msgctl(), msgrcv()
#include <string.h>                 // strcpy(), strcat()
#include <sys/ipc.h>                // ftok()
#include <signal.h>                 // signal(), SIGINT, SIGQUIT 
#include <sys/types.h>              // key_t
#include <unistd.h>                 // sleep()
#include <time.h>                   // time(), clock()

#define MAX 1024

struct poem
{
    long msg_type;
    int mtext;                      // integer value of SIGINT or SIGQUIT
};

// function declaration in client.c
int r2();
void write_value(int id, int category);
int access_queue();

// function declaration in server.c
int create_queue();
void remove_queue(int id);
struct poem read_value(int id);

#endif