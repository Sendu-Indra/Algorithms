/*
 * Closest Point:
 *
 * Given d, we want to know how many pairs from N randomly generated points in the unit square can be connected
 * by a straight line of length less than d.
 *
 * Better method: solution using compound data structures - A 2D array of lists
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/** Structures **/
typedef struct _point 
{
    double x, y;
} Point;

typedef struct _node
{
    struct _node *next;
    Point p;
} Node;

typedef Node * NodePtr;

/** Global variables **/
static NodePtr **grid;
static int cnt = 0, G, G2, N;
static float d;

/** Functions **/
float distance( Point p1, Point p2 )
{
    return sqrt( pow( ( p2.y - p1.y ), 2 ) + pow( ( p2.x - p1.x ), 2 ) );
}

void gridInsert( float x, float y )
{
    int X = x * G + 1, Y = x * G + 1, i, j;
    Point p;
    NodePtr s, t;

    p.x = x;
    p.y = y;

    t = malloc( sizeof( Node ) );
    t->p = p;
    t->next = grid[X][Y];

    for( i = X - 1; i <= X + 1; i++ )
        for( j = Y - 1; j <= Y + 1; j++ )
            for( s = grid[i][j]; s != 0; s = s->next )
                if( distance( s->p, t->p ) < d ) 
                {
                    cnt++;
                }

    grid[X][Y] = t;
}

int main( int argc, char *argv[] ) 
{
    int i, j;
    double rand1, rand2;

    if( argc > 1 )
    {
        N = atoi( argv[1] ); 
        d = atof( argv[2] ); 
        G = 1 / d;
        G2 = G + 2;
    }
    else
        return;

    grid = malloc( G2 * sizeof( NodePtr * ) );

    for( i = 0; i < G2; i++ )
    {
       grid[i] = malloc( G2 * sizeof( NodePtr ) );
    }

    for( i = 0; i < G2; i++ )
        for( j = 0; j < G2; j++ )
            grid[i][j] = 0;

    for( i = 0; i < N; i ++ )
    {
        rand1 = ( float )rand() / RAND_MAX;
        rand2 = ( float )rand() / RAND_MAX;
        printf( "%f, %f\n", rand1, rand2 );
        gridInsert( rand1, rand2 ); 
    }

    printf( "%d pairs withing %f\n", cnt, d );
}
