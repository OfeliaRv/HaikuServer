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

#define MAX 1024

typedef struct {
    enum { japanese , western} poem_type;
    char poem_text[MAX];
    char poem_author[MAX];
} Poem;

#endif