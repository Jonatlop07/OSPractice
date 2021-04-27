compile_execute:
	@gcc -o semaphores semaphores.c -lpthread -lm
	@./semaphores
