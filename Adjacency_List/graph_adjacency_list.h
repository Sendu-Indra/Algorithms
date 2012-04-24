#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct _node
{
    int vertex;
    int seen;
    struct _node *next;
} Node;

void create( Node *v_list[] );
void init( Node *v_list[] );
