#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>

#define PORT 3535
#define BACKLOG 2

int main() {

   int r;   
   int server_fd, client_fd;
   struct sockaddr_in server, client;
   socklen_t socklen;

   server_fd = socket(AF_INET, SOCK_STREAM, 0);

   if (server_fd < 0) {
      perror("Error en socket");
      exit(-1);
   }

   server.sin_family = AF_INET;
   server.sin_port = htons(PORT);
   server.sin_addr.s_addr = INADDR_ANY;
   bzero(server.sin_zero, 8); 

   r = bind(server_fd, (struct sockaddr *) &server, sizeof(struct sockaddr));

   if (r < 0) {
      perror("Error en bind");
      exit(-1);
   }

   r = listen(server_fd, BACKLOG);

   if (r < 0) {
      perror("Error en listen");
      exit(-1);
   }
   
   client_fd = accept(server_fd, (struct sockaddr *) &client, &socklen);

   if (client_fd < 0) {
      perror("Error en accept");
      exit(-1);
   }

   r = send(client_fd, "Hola mundo", 10, 0);

   if (r < 0) {
      perror("Error en send");
      exit(-1);
   }

   close(client_fd);
   close(server_fd);

   return 0;
}
