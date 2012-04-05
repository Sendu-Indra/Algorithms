#include <stdio.h>

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
    int p;
    int j, temp, i = left + 1;

    //MEDIAN OF THREE
    findPivot( array, left, right );
    p = array[left];

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

    if( right > left )
    {
        pivot = partition( array, left, right );
        quickSort( array, left, pivot - 1 );
        quickSort( array, pivot + 1, right );
    }
}

int main()
{
    int i;
    int test[] = { 3, 8, 2, 5, 1, 4, 7, 6 };
    int size = sizeof( test ) / sizeof( test[0] );

    quickSort( test, 0, size - 1 );

    for( i = 0; i < size; i++ )
        printf( "%d\n", test[i] );
    
    return 0;
}
