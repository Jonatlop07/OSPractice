#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>

#define PORT 3535

int main (int argc, char *argv[]) {

   int r;
   int client_fd;
   struct sockaddr_in client;
   char buffer[16];

   client_fd = socket(AF_INET, SOCK_STREAM);

   if (client_fd < 0) {
      perror("Error en socket");
      exit(-1);
   }

   client.sin_family = AF_INET;
   client.sin_port = htons(PORT);
   inet_aton(argv[1], &client.sin_addr);

   r = connect(client_fd, (struct sockaddr *) &client, (socklen_t) sizeof(struct sockaddr));

   if (r < 0) {
      perror("Error en connect");
      exit(-1);
   }

   r = recv(client_fd, buffer, 10, 0);
   
   if (r < 0) {
      perror("Error en recv");
      exit(-1);
   }

   buffer[r] = 0;

   printf("\nMensaje: %s", buffer);

   return 0;
}
