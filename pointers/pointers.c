#include <stdlib.h>
#include <stdio.h>

#define ROWS 3
#define COLS 3

int main () {
   
   int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

   int *p = arr;

   printf( "el dato de arr[0] es: %d\n", *p ); 
   printf( "la direccion de arr[0] es: %p\n", p ); 
   printf( "el dato de arr[1] es: %d\n", *( p + 1 ) );
   printf( "la direccion de arr[1] es: %p\n", p + 1);

   int *p1 = malloc( 10 * sizeof( int ) ); 

   printf( "el tamanio de p1 es: %lu\n", sizeof( *p1 ) );

   for ( int i = 1; i <= 10; i++ ) {
      arr[i - 1] = i;
   }

   for ( int i = 0; i < 10; i++ ) {
      *(p + i) = i + 1;
      printf( "el p[i] es: %d\n", *(p + i) );
   }

   free( p1 );

   int matrix [ ROWS ][ COLS ] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };

   int *m = malloc( 9 * sizeof( int ) );
   int x = 1, y = 1;

   printf( "m[1][1] = %d\n", *( m + COLS * x + y ) ); 

   free( m );

   int *( *m2 ) = malloc( ROWS * sizeof( int * ) );

   for ( int i = 0; i < ROWS; i++ ) {
      *( m2 + i ) = malloc( COLS * sizeof( int ) );

      for ( int j = 0; j < COLS; j++ ) {
         *( *(m2 + i) + j ) = j;
      }
   }

   for ( int i = 0; i < ROWS; i++ ) {
      for ( int j = 0; j < COLS; j++ ) {
         printf( "elemento m2[%d][%d] es: %d\n", i, j, *( *(m2 + i) + j ) );
      }
   }

   return 0;
}
