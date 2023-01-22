CC=gcc
CFLAGS=-I
LIBS=-lncursesw
DEPS = visualiser.h langton.h

all: langton.o visualiser.o $(DEPS)
	$(CC) -Wall -Wextra -g main.c langton.o visualiser.o -o ant $(LIBS)
	./ant LR
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)
library: $(DEPS)
	gcc -fPIC -c langton.c -o langton.o $(CFLAGS) $(LIBS)
	gcc -fPIC -c visualiser.c -o visualiser.o $(CFLAGS) $(LIBS)
	gcc -shared langton.o visualiser.o -o libant.so $(LIBS)
clean:
	rm -rf ant langton.o visualiser.o libant.so