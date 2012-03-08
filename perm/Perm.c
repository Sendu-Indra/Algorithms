/*
 *
 * Permutation 1 to n:
 *
 * Enter value n and the program spits out all the string perumutations of
 * '1' to 'n'.
 *
 */

#include <stdio.h>
#include <stdlib.h>

void _perm( char *a, int pos, int n )
{
    int i, j; 

    if( pos == n )
    {
        a[pos] = 0;
        printf( "%s\n", a );
        return;
    }

    for( i = 1; i <= n; i++ )
    {
        for( j = 0; j < pos; j++ )
           if( a[j] == i + '0' )
               break;

        if( j == pos )
        {
            a[pos] = i + '0';
            _perm( a, pos + 1, n );
        }
    }
}

int main( int argc, char *argv[] )
{
    int n;
    char *a;

    if( argc > 1 )
    {
        n = atoi( argv[1] );
        a = ( char * )malloc( n + 1 );
        _perm( a, 0, n );
        free( a );
    }
    else
        printf( "Enter a number next time!\n" );
}
