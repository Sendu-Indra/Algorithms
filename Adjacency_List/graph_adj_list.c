#include <stdio.h>
#include <stdlib.h>
#include "graph_adjacency_list.h"

void init( Node *v_list[] )
{
    int i; 
    for( i = 0; i < MAX; i++ )
        v_list[i] = NULL;
}

Node * get_node( int v )
{
    Node *node;

    node = ( Node * )malloc( sizeof( Node ) );
    node->next = NULL;
    node->vertex = v;

    return node;
}

void create( Node *v_list[] )
{
    int v1, v2;
    Node *node, *p;

    printf( "enter two vertices that will create an edge: " );
    scanf( "%d %d", &v1, &v2 );

    while( v1 >= 0 && v2 >= 0 && v1 <= MAX - 1 && v2 <= MAX - 1 ) 
    {
        p = v_list[v1]; 
        node = get_node( v2 );

        if( p == NULL )
            v_list[v1] = node;
        else
        {
            while( p->next != NULL )
                p = p->next;

            p->next = node;
        }

        p = v_list[v2];
        node = get_node( v1 );

        if( p == NULL )
            v_list[v2] = node;
        else
        {
            while( p->next != NULL )
                p = p->next;

            p->next = node;
        }

        printf( "enter two vertices that will create an edge: " );
        scanf( "%d %d", &v1, &v2 );
    }
}
