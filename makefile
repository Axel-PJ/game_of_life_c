HOME=/home/apj
CC=gcc
CFLAGS=-W -Wall -ansi -pedantic -I $(HOME)/include/
LDFLAGS=-lgraphics -L $(HOME)/lib/ -lX11 -lpthread
EXEC=graph
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

graph: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: graph.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
			
