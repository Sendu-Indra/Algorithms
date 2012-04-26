#include <stdio.h>
#include <stdlib.h>
#include "graph_adjacency_list.h"

typedef struct _queue
{
    Node *front;
    Node *rear;
    int length;
} Queue;

void q_init( Queue *q )
{
    q->front = NULL;
    q->rear = NULL;
    q->length = 0;
}

void enqueue( Queue *q, int v )
{
    Node *node;

    node = ( Node * )malloc( sizeof( Node ) );
    node->vertex = v;

    if( q->length == 0 )
    {
        q->front = node;
        q->rear = node;
    }
    else
    {
        q->rear->next = node;
        q->rear = node;
    }

    q->length++;
}

void dequeue( Queue *q )
{
    Node *node;

    if( q->length == 0 )
        return;

    node = q->front;

    if( q->front->next == NULL )
    {
        q->front = NULL;
        q->rear = NULL;
    }
    else
    {
        q->front = q->front->next;
    }

    free( node );

    q->length--;
}

int main()
{
    Node *v_list[MAX]; 
    Queue *q;
    Node *n;
    int i, visited[MAX];
    int target = 1;
    int found = 0;

    q = ( Queue * )malloc( sizeof( Queue ) );

    for( i = 0; i < 5; i++ )
        visited[i] = 0;

    //initialize the queue
    q_init( q );

    //initialize and create the graph
    init( v_list );
    create( v_list );

    enqueue( q, 0 );
    visited[0] = 1;

    while( q->length != 0 )
    {
        n = q->front;
        dequeue( q );

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
                    enqueue( q, n->vertex );
                }

                n = n->next;
            }
        }
    }

    printf( "found %d\n", found );
}
