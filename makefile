HOME=/home/apj
CC=gcc
CFLAGS=-W -Wall -ansi -pedantic -I $(HOME)/include/
LDFLAGS=-lgraphics -L $(HOME)/lib/ -lX11 -lpthread
EXEC=jeu
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

jeu: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c %.h
	$(CC) -o $@ -c $< $(CFLAGS)

jeu.o: jeu.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
			
