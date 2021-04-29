compile_execute:
	@gcc -o mutex_prod_cons mutex_prod_cons.c -lpthread -lm
	@./mutex_prod_cons
