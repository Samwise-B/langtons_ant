CC=gcc
CFLAGS=-I
LIBS=-lncursesw
DEPS = visualiser.h langton.h

all: library main.o
	$(CC) -Wall -Wextra -g main.o -L./ -lant -o ant
library: $(DEPS)
	gcc -fPIC -c langton.c -o langton.o $(CFLAGS) $(LIBS)
	gcc -fPIC -c visualiser.c -o visualiser.o $(CFLAGS) $(LIBS)
	gcc -shared langton.o visualiser.o -o libant.so $(LIBS)
	gcc -c main.c -o main.o $(CFLAGS) $(LIBS)
clean:
	rm -rf langton langton.o visualiser.o main.o libant.so