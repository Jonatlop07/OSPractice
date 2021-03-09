#include <stdio.h>
#include <stdlib.h>

int main () {
   
   FILE *fileIn;   
   fileIn = fopen( "in.txt", "r" ); // modos: w, r, a, ab

   if ( fileIn == NULL  ) {
      printf( "error leyendo archivo\n" );
      return -1;
   }

   int numero1, numero2; 

   fscanf( fileIn, "%d", &numero1 );
   fscanf( fileIn, "%d", &numero2 );

   fclose( fileIn );

   FILE *fileOut;
   fileOut = fopen( "out.txt", "w" );

   if ( fileOut == NULL ) {
      printf( "error creando archivo\n" );
   }

   fprintf( fileOut, "la suma de los numeros es: %d\n", ( numero1 + numero2 ) );

   fclose( fileOut );

   return 0;
}
