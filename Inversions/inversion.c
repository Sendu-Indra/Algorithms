#include <stdio.h>
#include <stdlib.h>

#define STRING_LENGTH 10
#define ARRAY_SIZE 100000

static unsigned long long count = 0;

void _mergeSort( int *a, int left, int right );
void merge( int *a, int left, int mid, int right );

void mergeSort( int *a, int size )
{
    int i;

    _mergeSort( a, 0, size - 1 );

    for( i = 0; i < size; i++ )
        printf( "%d\n", a[i] );

    //number if inverions 'count'
    printf( "%lld\n", count );
}

void _mergeSort( int *a, int left, int right )
{
    int mid;

    if( right == left )
        return;
    
    mid = ( left + right ) / 2;

    _mergeSort( a, left, mid );
    _mergeSort( a, mid + 1, right );
    merge( a, left, mid, right );
}

void merge( int *a, int left, int mid, int right )
{
    int size = right - left + 1, i;
    int *temp = ( int * )malloc( sizeof( int ) * size );
    int j = 0, k =  (size - 1) / 2 + 1;

    for( i = 0; i < size; i++ )
        temp[i] = a[left + i];

    for( i = 0; i < size; i++ )
    {
        if( k <= size - 1 )
            if( j <= ( size - 1 ) / 2 )
                if( temp[j] < temp[k] )
                    a[i + left] = temp[j++];
                else
                {
                    a[i + left] = temp[k++];
                    count += ( ( ( ( size - 1 ) / 2 ) - j ) + 1 );
                }
            else
            {
                a[i + left] = temp[k++];
                count += ( ( ( ( size - 1 ) / 2 ) - j ) + 1 );
            }
        else
            a[i + left] = temp[j++];
    }
        
    free( temp );
}

int main()
{
    FILE *file;
    char string[STRING_LENGTH];
    int array[ARRAY_SIZE], i = 0;

    file = fopen( "IntegerArray.txt", "r" );    

    if( file != NULL )
    {
        while( fgets( string, 10, file ) != NULL && i < ARRAY_SIZE )
        {
            array[i] = atoi( string );
            i++;
        }

        fclose( file );
    }

    mergeSort( array, ARRAY_SIZE );
    
    return 0;
}
