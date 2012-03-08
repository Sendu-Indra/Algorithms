/*
 * Closest Point:
 *
 * Given d, we want to know how many pairs from N randomly generated points in the unit square can be connected
 * by a straight line of length less than d.
 *
 * Naive Method: solution using an array
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct _point
{
    double x;
    double y;
};

typedef struct _point Point;

double getDistance( const Point *one, const Point *two )
{
    return sqrt( pow( ( one->x - two->x ), 2 ) + pow( ( one->y - two->y ), 2 ) );
}

double getRandPoint( Point *a )
{
    a->x = ( double )rand() / ( double )RAND_MAX;
    a->y = ( double )rand() / ( double )RAND_MAX;
}

int main( int argc, char *argv[] )
{
    int cnt = 0, N, i, j;
    double d;
    Point *a;

    if( argc == 3 )
    {
        N = atoi( argv[1] );
        d = atof( argv[2] );
        a = ( Point * )malloc( sizeof( Point ) * N );
    }
    else
    {
        return;
    }

    for( i = 0; i < N; i++ )
        getRandPoint( &a[i] );
    for( i = 0; i < N; i++ )
        printf( "%f %f\n", a[i].x, a[i].y );
    for( i = 0; i < N; i++ )
        for( j = i + 1; j < N; j++) 
            if( getDistance( &a[i], &a[j] ) < d ) cnt++;

    printf( "%d pairs are closer than %f\n", cnt, d );
}
