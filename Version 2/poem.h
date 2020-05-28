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

// typedef struct {
//     enum { japanese , western } poem_type; // same with signal type for now
//     char poem_text[MAX];
//     char poem_author[MAX];
//     long poem_sig_type;
// } Poem;


// function declaration in client.c
// void sigint();
// void sigquit();
void choose_signal(int num);
// int r2();

// function declaration in server.c
int create_queue();
void remove_queue(int id);
char read_value (int id);

#endif