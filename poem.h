#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include <stdio.h>
#include <sys/msg.h>
#include <string.h>
#include <sys/ipc.h>
#include <stdlib.h>

#define MAX 1024

typedef struct {
    enum { japanese , western} poem_type;
    char poem_text[MAX];
    char poem_author[MAX];
} Poem;

#endif