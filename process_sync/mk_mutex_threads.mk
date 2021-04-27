compile_execute:
	@gcc -o mutex_threads mutex_threads.c -lpthread
	@./mutex_threads
