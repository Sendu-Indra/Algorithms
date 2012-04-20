#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    int test = 32;
    int *a = ( int * )malloc( sizeof( int ) * test );
    
    for( i = 0; i < test; i++)
        a[i] = 1;

    for( i = 2; i < test; i++ )
        if( a[i] == 1 )
            for( j = i; j*i < test; j++ )
                a[j*i] = 0;
    
    for( i = 2; i < test; i++)
        if( a[i] == 1 )
            printf( "%d\n", i );

    free( a );
}
