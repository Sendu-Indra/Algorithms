#include <stdio.h>
#include <stdlib.h>

#define MAX 47

static int knownF[MAX] = { 0, 1 };

//Top-down dynamic programming (memoization) solution
int F_TDDP( int N )
{
    if( knownF[N] ) return knownF[N];
    if( N > 1 ) return knownF[N] = F_TDDP( N - 2 ) + F_TDDP( N - 1 );
    else return knownF[N];
}

//bottom up dynamic programming solution
int F_BUDP( int N )
{
    int i;

    for( i = 2; i <= N; i++ )
        knownF[i] = knownF[i-2] + knownF[i-1];

    return knownF[N];
}

int main( int argc, char *argv[] )
{
    printf( "%d\n", F_TDDP( atoi( argv[1] ) ) );
    printf( "%d\n", F_BUDP( atoi( argv[1] ) ) );
}
