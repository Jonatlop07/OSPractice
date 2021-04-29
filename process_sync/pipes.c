#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>
#include <pthread.h>
#include <unistd.h>

pid_t pid;
int pipefd[2];
int buffer;
int data = 0;

struct datos_tipo{
	int dato;
	int p;
}

* proceso(void *datos) {
	struct datos_tipo *datos_proceso;
	datos_proceso = (struct datos_tipo *) datos;
	int a, i, j, p, r;
   
   //Bloqueo con pipe
   r = read(pipefd[0], &buffer, sizeof(int)); 

   if (r < 0) {
      perror("Error en read");
      exit(-1);
   }

	a = datos_proceso -> dato;
	p = datos_proceso -> p;

	for(i = 0; i <= p; i++) {
      printf("%i ",a);
   }

	fflush(stdout);
	sleep(2);

	for(i = 0; i <= p; i++) {
		printf("- ");
	}

   r = write(pipefd[1], &data, sizeof(data)); 
   //Desbloqueo con pipe

   if (r < 0) {
      perror("Error en write: ");
      exit(-1);
   }

	fflush(stdout);
}

int main()
{
	int error;
	char *valor_devuelto;
	/* Variables para hilos*/
	struct datos_tipo hilo1_datos, hilo2_datos;
	pthread_t idhilo1, idhilo2, idhilo3, idhilo4;

	hilo1_datos.dato = 1;
	hilo2_datos.dato = 2;
	hilo1_datos.p = 10;
	hilo2_datos.p = 5;

   error = pipe(pipefd);
   
   if (error < 0) {
      perror("Error en pipe");
      exit(-1);
   } 

   error = write(pipefd[1], &data, sizeof(data));

   if (error < 0) {
      perror("Error en write 1: ");
      exit(-1);
   }

	error = pthread_create(&idhilo1, NULL, (void *)proceso, (void *)(&hilo1_datos));

	if (error != 0)
	{
		perror ("No puedo crear hilo");
		exit (-1);
	}

	error = pthread_create(&idhilo2, NULL, (void *)proceso, (void *)(&hilo2_datos));

	if (error != 0)
	{
		perror ("No puedo crear thread");
		exit (-1);
	}

	pthread_join(idhilo2, (void **)&valor_devuelto);
	pthread_join(idhilo1, (void **)&valor_devuelto);

   close(pipefd[0]);
   close(pipefd[1]);

	return 0;
}
