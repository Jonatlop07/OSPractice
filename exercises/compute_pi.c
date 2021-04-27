#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <math.h>

#define READ 0
#define WRITE 1

#define LEIBNIZ_FACTOR 4
#define MAX_ERROR 0.00001

int main() {
   
   int parent_fd[ 2 ], child_fd[ 2 ];

   pid_t process_id;
   
   int result;

   if ( pipe( parent_fd ) < 0 || pipe( child_fd ) < 0 ) {
      perror( "Error en pipes" );
      exit( -1 );
   }
   
   process_id = fork();
   
   if ( process_id < 0 ) {
      perror( "Error en fork" );
      exit( -1 );
   }

   if ( process_id == 0 ) {
      double computation_result;
      int current_index, i = 0;
      
      while ( i < 100000  ) { 
         result = read( parent_fd[ READ ], &current_index, sizeof( current_index ) );
      
         if ( result != sizeof( current_index ) ) {
            perror( "Error al obtener datos mediante pipe del padre" );
            exit( -1 );
         }

         computation_result = pow( -1, current_index ) / ( 2 * current_index + 1 );

         write( child_fd[ WRITE ], &computation_result, sizeof( computation_result ) );
         ++i;
      }
   } else {
      close( parent_fd[ READ ] );
      close( child_fd[ WRITE ] );

      int i = 0, current_child_index = 0;
      double child_computation, total = 0;

      while ( fabs( M_PI / LEIBNIZ_FACTOR - total ) > MAX_ERROR ) { 
         total += pow( -1, i ) / ( 2 * i + 1 );
 
         current_child_index = i + 1;
         write( parent_fd[ WRITE ], &current_child_index , sizeof( current_child_index ) );
         
         result = read( child_fd[ READ ], &child_computation, sizeof( child_computation ) );
      
         if ( result != 0 && result != sizeof( child_computation ) ) {
            perror( "Error al obtener datos mediante pipe del hijo" );
            exit( -1 );
         }
        
         total += child_computation;
         i     += 2;
      }
     
      close( parent_fd[ WRITE ] );
      close( child_fd[ READ ] );
       
      printf( "El número PI aproximado es: %f\n", total * LEIBNIZ_FACTOR ); 
   }

   return 0;
}
