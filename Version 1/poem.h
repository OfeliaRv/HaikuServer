#ifndef __POEM__
#define __POEM__

#include <stdio.h>
#include <sys/msg.h>
#include <string.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <signal.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <time.h>
#include <stdlib.h>

#define MAX 1024

struct poem
{
    long msg_type;
    int mtext;
};

// function declaration in client.c
int r2();

// function declaration in server.c
int create_queue();
void remove_queue(int id);
struct poem read_value(int id);


#endif