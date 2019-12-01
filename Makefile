CC=gcc
DEPS=xadrez.h validador.h

%.o : %.c $(DEPS)
	$(CC) -o $@ -c $<

main : main.o tabuleiro.o validador.o movimentos.o xadrez.h
	$(CC) -o $@ main.o tabuleiro.o validador.o movimentos.o
	
clean :
	rm *.o
