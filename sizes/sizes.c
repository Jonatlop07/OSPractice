#include "stdio.h"

void main() {
   int a, b, c;
   char p;
   float x;
   double y;
   short d;

   printf("Tamanio de d: %lu\n", sizeof(d));
   printf("Tamanio de y: %lu\n", sizeof(y));
   printf("Tamanio de x: %lu\n", sizeof(x));
   printf("Tamanio de las referencias: a/%lu, p/%lu, x/%lu, y/%lu, d/%lu\n",
          sizeof(&a), sizeof(&p), sizeof(&x), sizeof(&y), sizeof(&y));
}
