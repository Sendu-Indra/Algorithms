#include <stdio.h>
#include "graph_adjacency_list.h"

typedef struct _stack
{
    Node *top;
    int length;
} Stack;

void sinit( Stack *s )
{
    s->top = NULL;
    s->length = 0;
}

void push( Stack *s, int v )
{
    Node *n;

    n = ( Node * )malloc( sizeof( Node ) );
    n->vertex = v;
    n->next = s->top;
    s->top = n;
    s->length++;
}

void pop( Stack *s )
{
    Node *n;

    if( s->length != 0 )
    {
        n = s->top;
        s->top =  s->top->next;
        free( n );
        s->length--;
    }
}

int main()
{
    Stack s;
    Node *v_list[MAX]; 
    Node *n;
    int i, found = 0, target = 5;
    int visited[5] = { 0 };

    sinit( &s );
    
    //initialize and create the graph
    init( v_list );
    create( v_list );

    push( &s, 0 );
    visited[0] = 1;

    while( s.length != 0 )
    {
        n = s.top;
        pop( &s );

        printf( "%d", n->vertex );

        if( n->vertex == target )
        {
            found = 1;
            break;
        }
        else
        {
            n = v_list[n->vertex];

            while( n != NULL )
            {
                if( !visited[n->vertex] )
                {
                    visited[n->vertex] = 1;
                    push( &s, n->vertex );
                }

                n = n->next;
            }
        }
    }

    printf( "found %d\n", found );
}
