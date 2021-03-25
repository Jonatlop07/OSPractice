#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int main () {

   pid_t pid;
   int r;
   int pipefd[2];
   char buffer[11];

   r = pipe(pipefd);

   if (r < 0) {
      perror("error en pipe");
      exit(-1);
   }

   pid = fork();

   if (pid < 0) {
      perror("error en fork");
      exit(-1);
   }

   if (pid == 0) {
      close(pipefd[0]);
      r = write(pipefd[1], "hola mundo", 10);

      if (r != 10){
         // validar error
      }
      close(pipefd[1]);
      exit(0);
   } else {
      close(pipefd[1]);
      r = read(pipefd[0], buffer, 10);
      buffer[r] = 0;
      // validar error
      close(pipefd[0]);
      printf("El mensaje del hijo es %s\n", buffer);
   }
   
   return 0;
}
