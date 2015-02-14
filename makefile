all: stest employee_engine employee_read_file

debug: stestdebug

stest: stest.o struct.o
	gcc -g stest.o struct.o -lreadline -o stest

stest.o: stest.c struct.h
	gcc -g -c stest.c

stestdebug: stestdebug.o struct.o
	gcc -g stestdebug.o struct.o -lreadline -o stestdebug

stestdebug.o: stest.c struct.h 
	gcc -g -c stest.c -o stestdebug.o -DDEBUG

employee_engine: struct.o employee_engine.o
	gcc -g struct.o employee_engine.o -lreadline -o employee_engine

employee_engine.o: employee_engine.c struct.h
	gcc -g -c employee_engine.c -o employee_engine.o

employee_read_file: struct.o employee_read_file.o
	gcc -g employee_read_file.o struct.o -lreadline -o employee_read_file

employee_read_file.o: employee_read_file.c struct.h
	gcc -g -c employee_read_file.c -o employee_read_file.o

struct.o: struct.c struct.h
	gcc -g -c struct.c -o struct.o

clean:
	rm -f *.o stest stestebug

docs:
	doxygen
	chmod a+r html/*
	cp -p html/* ~/public_html/cs2303assig4

