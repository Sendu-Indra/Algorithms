#include <stdio.h>
#include <stdlib.h>

void selectionSort( int *a, int max )
{
    int i, j, temp, min;

    for( i = 0; i < max - 1; i++ ) 
    {
        min = i;

        for( j = min + 1; j < max; j++ )
        {
            if( a[min] > a[j] )
                min = j;
        }

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

    //print array after sort
    for( i = 0; i < max; i++ )
        printf( "%d\n", a[i] );
}


void insertionSort( int *a, int max )
{
    int i, pos, val;

    for( i = 1; i < max; i++ )
    {
        val = a[i];
        pos = i;

        while( pos > 0 && ( val < a[pos-1] ) )
        {
            a[pos] = a[pos-1];
            pos--;
        }

        a[pos] = val;
    }

    //print array after sort
    for( i = 0; i < max; i++ )
        printf( "%d\n", a[i] );
}


void bubbleSort( int *a, int max )
{
    int i, j, temp;

    printf( "max: %d\n", max );

    for( i = max - 1; i >= 0; i-- )
    {
        for( j = 0; j < i; j++ )
        {
            if( a[j] > a[j+1] )
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    //print array after sort
    for( i = 0; i < max; i++ )
        printf( "%d\n", a[i] );
}


int main()
{
    int test[] = { 1, 2, 3, 4, 12, 123, 84, 1, 4, 6, 3, 2, 5, 7, 9, 8 };

    bubbleSort( test, sizeof( test ) / sizeof( test[0] ) );
}
