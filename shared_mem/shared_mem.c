int main () {
   pid_t pid;
   key_t key = 1234;
   int shm_id;
   float a,b,c;
   int status, cpid, r;

   smh_id = shmget(key, 2*sizeof(float), 0666|IPC_CREAT); // RWXRWXRWX
   
   if (shm_id < 0){
      perror("Error en shmget");
      exit(-1);
   }
   ap = (float *)shmat(shm_id, 0, 0);

   if (ap < 0){
      perror("Error en shmat");
      exit(-1);
   }

   *ap = 3.145926535;

   pid = fork();

   if (pid < 0){
      *(ap+1) = 0.707;
   } else{
      if (wait(&status) == pid) {
         printf("\n %1.01f  %1.3f ", *ap, *(ap+1));
      }
   }

   r = shmdt(ap);

   if (r < 0) {
      perror("Error shmdt");
      exit(-1);
   }
}
