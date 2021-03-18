#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main () {

   pid_t pid;
   pid = fork();

   if ( pid == -1 ) {
      perror( "Error en fork" );
      exit( -1 );
   }

   if ( pid == 0 ) {
      printf( "Child process\n" ); 
   } else {
      printf( "Parent process\n" );
   }

   return 0;
}

