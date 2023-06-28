all: compile

compile: codigo.o
		gcc -o compile codigo.o 

codigo.o: codigo.c
		gcc -o codigo.o codigo.c -c 


run:
	./compile