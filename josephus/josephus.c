/*
 *
 * Josephus Problem: 
 *
 * N people numbered 1 to N around a circle. Starting from person '1' we remove the Mth person 
 * until there is one survivor. Determine the survivor.
 *
 */

#include <stdio.h>
#include <stdlib.h>

struct _node 
{
    int val;
    struct _node *next;
};

typedef struct _node Node;

int main()
{
    /* Use these values as a test, result should be 8.*/

    int i, N = 9, M = 5;
    Node *first, *x;

    x = ( Node * )malloc( sizeof( Node ) );
    x->val = 1;
    first = x;

    for( i = 2; i <= N; i++ )
    {
        x = x->next = ( Node * )malloc( sizeof( Node ) );
        x->val = i;
    }

    x->next = first;
    
    while( x->next != x )
    {
        for( i = 1; i < M; i++ )
            x = x->next;
        x->next = (x->next)->next;
    }

    printf( "%d\n", x->val );
}
