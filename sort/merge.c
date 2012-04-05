#include <stdio.h>
#include <stdlib.h>

void _mergeSort( int *a, int left, int right );
void merge( int *a, int left, int mid, int right );

void mergeSort( int *a, int size )
{
    int i;

    _mergeSort( a, 0, size - 1 );

    for( i = 0; i < size; i++ )
        printf( "%d\n", a[i] );
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
    {
        temp[i] = a[left + i];
    }


    for( i = 0; i < size; i++ )
    {
        if( k <= size - 1 )
        {
            if( j <= ( size - 1 ) / 2 )
            {
                if( temp[j] < temp[k] )
                {
                    a[i + left] = temp[j++];
                }
                else
                {
                    a[i + left] = temp[k++];
                }
            }
            else
            {
                a[i + left] = temp[k++];
            }
        }
        else
        {
            a[i + left] = temp[j++];
        }
    }

    free( temp );
}

int main()
{
    int test[] = { 19, 9, 2, 35, 22, 12, 9, 1, 14, 123, 1, 23 };
    int size = sizeof( test ) / sizeof( test[0] );

    mergeSort( test, size );
    
    return 0;
}
