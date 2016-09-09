#include "stdio.h"

void main( )
{
	int arr[5] = { 25, 17, 31, 13, 2 } ;
	int i, j, k, temp ;
					
	printf ( "Insertion sort.\n" ) ;
	printf ( "\nArray before sorting:\n") ;
							
	for ( i = 0 ; i <= 4 ; i++ )
		printf ( "%d\t", arr[i] ) ;

	for ( i = 1 ; i <= 4 ; i++ )
	{
		for ( j = 0 ; j < i ; j++ )
		{
			if ( arr[j] > arr[i] )
			{
				temp = arr[j] ;
				arr[j] = arr[i] ;
				
				for ( k = i ; k > j ; k-- )
					arr[k] = arr[k - 1] ;

				arr[k + 1] = temp ;
			}
		}
	}

	printf ( "\n\nArray after sorting:\n") ;

	for ( i = 0 ; i <= 4 ; i++ )
		printf ( "%d\t", arr[i] ) ;

}
