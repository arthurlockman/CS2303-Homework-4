all: stest employee_write_text employee_read_file employee_write_binary employee_read_binary

debug: stestdebug

stest: stest.o struct.o
	gcc -g stest.o struct.o -lreadline -o stest

stest.o: stest.c struct.h
	gcc -g -c stest.c

stestdebug: stestdebug.o struct.o
	gcc -g stestdebug.o struct.o -lreadline -o stestdebug

stestdebug.o: stest.c struct.h 
	gcc -g -c stest.c -o stestdebug.o -DDEBUG

employee_read_binary: struct.o employee_read_binary.o
	gcc -g -lreadline struct.o employee_read_binary.o -o employee_read_binary

employee_read_binary.o: employee_read_binary.c struct.h
	gcc -g -c employee_read_binary.c -o employee_read_binary.o

employee_write_binary: struct.o employee_write_binary.o
	gcc -g -lreadline struct.o employee_write_binary.o -o employee_write_binary

employee_write_binary.o: employee_write_binary.c struct.h
	gcc -g -c employee_write_binary.c -o employee_write_binary.o

employee_write_text: struct.o employee_write_text.o
	gcc -g -lreadline struct.o employee_write_text.o -o employee_write_text

employee_write_text.o: employee_write_text.c struct.h
	gcc -g -c employee_write_text.c -o employee_write_text.o

employee_read_file: struct.o employee_read_file.o
	gcc -g -lreadline employee_read_file.o struct.o -o employee_read_file

employee_read_file.o: employee_read_file.c struct.h
	gcc -g -c employee_read_file.c -o employee_read_file.o

struct.o: struct.c struct.h
	gcc -g -c struct.c -o struct.o

clean:
	rm -f *.o stest stestdebug employee_read_file employee_write_text employee_write_binary employee_read_binary employee_output.txt employee_output.dat

docs:
	doxygen
	chmod a+r html/*
	cp -p html/* ~/public_html/cs2303assig4

