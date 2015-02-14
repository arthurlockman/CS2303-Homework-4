all: stest

debug: stestdebug

stest: stest.o struct.o
	gcc -g stest.o struct.o -o stest

stest.o: stest.c struct.h
	gcc -g -c stest.c

stestdebug: stestdebug.o struct.o
	gcc -g stestdebug.o struct.o -o stestdebug

stestdebug.o: stest.c struct.h 
	gcc -g -c stest.c -o stestdebug.o -DDEBUG

struct.o: struct.c struct.h
	gcc -g -c struct.c -o struct.o

clean:
	rm -f *.o stest stestebug

docs:
	doxygen
	chmod a+r html/*
	cp -p html/* ~/public_html/cs2303assig4

