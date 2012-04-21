#include <stdio.h>
#include <stdlib.h>

int binSearch( int *a, int target, int min, int max )
{
    int mid = ( min + max ) / 2;

    if( min > max ) 
        return 0;
    if( target == a[mid] ) 
        return 1;
    if( target > a[mid] ) 
        return binSearch( a, target, mid + 1, max );
    if( target < a[mid] ) 
        return binSearch( a, target, min, mid - 1 );
}

int findPivot( int *a, int min, int max )
{
    int mid = ( min + max ) / 2;

    if( a[mid] > a[mid+1] ) 
        return mid;
    if( a[mid] > a[min] ) 
        return findPivot( a, mid + 1, max );
    else 
        return findPivot( a, min, mid - 1 );
}

int searchRotatedArray( int *a, int min, int max, int target )
{
    int pivot = findPivot( a, min, max );

    if( target >= a[min] && target <= a[pivot] ) 
        return binSearch( a, target, min, pivot );
    if( target >= a[pivot + 1] && target <= a[max] ) 
        return binSearch( a, target, pivot + 1, max );
    else 
        return 0;
}

int main( int argc, char *argv[] )
{
    int a[] = { 3, 4, 5, 6, 1, 2 };
    int size = sizeof( a ) / sizeof( a[0] );

    if( argc > 1 )
        printf( "%d\n", searchRotatedArray( a, 0, size - 1, atoi( argv[1] ) ) );
}
