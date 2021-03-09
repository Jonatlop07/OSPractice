#include <stdlib.h>
#include <stdio.h>

struct vector {
   int length;
   int currentLength;
   int *elements;
} v;

void init ( int length ) {
   v.currentLength = 0;
   v.length = length;
   v.elements = malloc( length * sizeof( int ) ); 
}

void add ( int element ) {
   if ( v.length == v.currentLength ) {
      int *aux = malloc( v.length * 2 * sizeof( int ) );
      
      for ( int i = 0; i < v.length; i++ ) {
         *( aux + i ) = *( v.elements + i );
      }
      
      *( aux + v.length ) = element;
      v.length *= 2;
      v.currentLength++;
      free( v.elements );
      v.elements = aux;
   } else {
      *( v.elements + v.currentLength ) = element;
      v.currentLength++;
   }
}

void get ( int position ) {
   if ( position >= v.currentLength ) {
      return -1;
   }
   return *( v.elements + position );
}

void pop_back () {
   if ( v.currentLength == 0 ) {
      return ;
   }
   v.currentLength--;
}

void pop_pos ( int position ) {
   if ( position < 0 || position >= currentLength ) {
      return ;
   }
   
   int *aux = malloc( v.length * sizeof( int ) );
   int j = 0;

   for ( int = 0; i < v.currentLength - 1; i++ ) {
      if ( i != position ) {
         *( aux + i ) = v.elements[ i ];
      } else {
      }
   }
}

int main () {
   
   return 0;
}
