compile_execute:
	@gcc -o pipes pipes.c -lpthread -lm
	@./pipes
