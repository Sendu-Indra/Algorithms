#include <stdio.h>
#include <stdlib.h>

#define STRING_LENGTH 10
#define ARRAY_SIZE 10000

unsigned long long comparisons = 0;

void findPivot( int *array, int left, int right )
{
    if( right > left )
    {
        int median, temp;
        int mid = ( left + right ) / right;
        int a = array[left];
        int b = array[right];
        int c = array[mid];

        if ( ( a < b && c > b ) || ( c < b && a > b ) )
            median = right;
        if ( ( c < a && b > a ) || ( b < a && c > a ) )
            median = left;
        if ( ( b < c && a > c ) || ( a < c && b > c ) )
            median = mid;

        temp = array[left];
        array[left] = array[median];
        array[median] = temp;
    }
}

int partition( int *array, int left, int right )
{
    int p;// = array[left];
    int j, temp, i = left + 1;

    // ALWAYS USING MEDIAN OF THREE
    findPivot( array, left, right );
    p = array[left];

    /*  ALWAYS USING THE LEFT PIVOT 
     *
     *  p = array[left];
     *
     */
    
    /*  ALWAYS USING THE RIGHT PIVOT 
     *
     *  p = array[right];
     *  array[right] = array[left];
     *  array[left] = p;
     *
     */

    for( j = left + 1; j <= right; j++ )
    {
        if( array[j] < p )
        {
            temp = array[j];
            array[j] = array[i];
            array[i] = temp;
            i++;
        }
    }

    //set pivot
    temp = array[left];
    array[left] = array[i-1];
    array[i-1] = temp;
    return i - 1;
}

void quickSort( int *array, int left, int right )
{
    int pivot, i;

    comparisons += right - left;

    if( right > left )
    {
        pivot = partition( array, left, right );

        /*for( i = 0; i < 8; i++ )
            printf( "%d ", array[i] );

        printf( "\n" );*/

        quickSort( array, left, pivot - 1 );
        quickSort( array, pivot + 1, right );
    }
}

int main()
{
    FILE *file;
    char string[STRING_LENGTH];
    int array[ARRAY_SIZE], i = 0;
    int test[] = { 3, 8, 2, 5, 1, 4, 7, 6 };
    int size = sizeof( test ) / sizeof( test[0] );

    file = fopen( "QuickSort.txt", "r" );    

    if( file != NULL )
    {
        while( fgets( string, 10, file ) != NULL && i < ARRAY_SIZE )
        {
            array[i] = atoi( string );
            i++;
        }

        fclose( file );
    }

    quickSort( array, 0, ARRAY_SIZE - 1 );

    printf( "\ncomparisons = %lld\n", comparisons );
    
    return 0;
}
