#include <stdio.h>
#include <stdlib.h>

//linear search doesn't require an ordered list
int linSearch( int *a, int size, int target )
{
    int i;

    for( i = 0; i < size; i++ )
    {
        if( a[i] == target )
            return 1;
    }

    return 0;
}


//binary search requires a sorted list
int binSearch( int *a, int min, int max, int target )
{
    int middle = ( min + max ) / 2;

    if( max < min )
        return 0;
    if( a[middle] == target ) 
        return 1;
    else if( a[middle] < target )
        return binSearch( a, middle + 1, max, target );
    else 
        return binSearch( a, min, middle - 1, target );
}


int main() 
{
    int test[] = { 2, 1, 3, 4, 5, 7, 8 };
    int btest[] = { 10, 12, 18, 22, 31, 40 };

    if( linSearch( test, sizeof( test ) / sizeof( test[0] ), 6 ) )
        printf( "lin search: found\n" );
    else
        printf( "lin search: not found\n" );

    if( binSearch( btest, 0, sizeof( btest ) / sizeof( btest[0] ) - 1, 10 ) )
        printf( "bin search: found\n" );
    else
        printf( "bin search: not found\n" );

    return;
}
