# CS2303-Homework-4
Homework 4 for WPI CS 2303 by Arthur Lockman.

## Lab Questions
The variable harry was stored at address 0x7fff5fbff4a8, or 140734799803560. The variable bluejay was stored at 0x7fff5fbff498, or 140734799803544. It seems then that the stack grows down in memory, meaning that local variables are stored in sequentially lower memory addresses. The local variable y is stored closer to the top of the stack because it would have a lower address, meaning that it has been allocated most recently and is at the top of the stack.

##Compiling

To compile the program, simply type the following command in the command prompt in the program directory:

    make

To build a debug version of stest, type this command:

    make debug

To make the doxygen docs, type this command:

    make docs

Finally, to remove all previous builds, type this:

    make clean

##Programs

This homework required the creation of 5 programs: stest, employee_read_binary, employee_write_binary, employee_write_text, and employee_read_file. Each of these is detailed below.

###stest

The program stest is a demonstration of basic File IO and getting data from user input. To run stest, enter the following command. This also details an example of output.

    user@system:~/CS2303-Homework-4$ ./stest
    Starting program stest.
    Enter the employee's name: Jim
    Enter the employee's department: Shipping
    Enter the employee's salary: 80000
    Employee. Name = Harry Palmer, Salary = 5000, Department = Engineering
    Employee. Name = Erik Grantby, Salary = 10000, Department = Marketing
    Employee. Name = Fry, Salary = 1000, Department = Shipping
    Employee. Name = Leela, Salary = 500000, Department = Receiving
    Employee. Name = Jim, Salary = 80000, Department = Shipping
    About to write to file.
    Ending program stest.

This program creates an output file called stest.txt. The example above produces this file:

    Employee. Name = Harry Palmer, Salary = 5000, Department = Engineering
    Employee. Name = Erik Grantby, Salary = 10000, Department = Marketing
    Employee. Name = Fry, Salary = 1000, Department = Shipping
    Employee. Name = Leela, Salary = 500000, Department = Receiving
    Employee. Name = Jim, Salary = 80000, Department = Shipping

###employee_write_text

The program employee_write_text reads in a number of employee data structures from user input, and writes them to a text file that can be read by employee_read_file. An example of running this program can be found below:

    user@system:~/CS2303-Homework-4$ ./employee_write_text
    How many employees are there? 2
    Enter the employee's name: John
    Enter the employee's department: Marketing
    Enter the employee's salary: 20000
    Enter the employee's name: Alfred
    Enter the employee's department: Weapons
    Enter the employee's salary: 100
    Employee. Name = John, Salary = 20000, Department = Marketing
    Employee. Name = Alfred, Salary = 100, Department = Weapons

This program produces an output file called employee_output.txt. Running the sample above creates this output file:

    John 20000 Marketing
    Alfred 100 Weapons

The file format follows the form (employee name, salary, department) for each line. 

###employee_read_file

The program employee_read_file reads in the file created by employee_write_text (employee_output.txt) and displays the contents. Running it with the data file created above produces the following output:

    user@system:~/CS2303-Homework-4$ ./employee_read_file
    Employee. Name = John, Salary = 20000, Department = Marketing
    Employee. Name = Alfred, Salary = 100, Department = Weapons

###employee_write_binary

The program employee_write_binary reads in a number of employee data structures from user input, and writes them to a binary file that can be read by employee_read_binary. An example of running this program can be found below:

    user@system:~/CS2303-Homework-4$ ./employee_write_binary
    How many employees are there? 3
    Enter the employee's name: Kermit
    Enter the employee's department: Production
    Enter the employee's salary: 333
    Enter the employee's name: Piggy
    Enter the employee's department: Makeup
    Enter the employee's salary: 500
    Enter the employee's name: Gonzo
    Enter the employee's department: Effects
    Enter the employee's salary: 2300
    Employee. Name = Kermit, Salary = 333, Department = Production
    Employee. Name = Piggy , Salary = 500, Department = Makeup
    Employee. Name = Gonzo, Salary = 2300, Department = Effects

Running the above sample produces the binary file named employee_output.dat (contents obtained using hexdump)

    00000000  03 00 00 00 4d 01 00 00  06 00 00 00 00 00 00 00  |....M...........|
    00000010  4b 65 72 6d 69 74 0a 00  00 00 00 00 00 00 50 72  |Kermit........Pr|
    00000020  6f 64 75 63 74 69 6f 6e  f4 01 00 00 06 00 00 00  |oduction........|
    00000030  00 00 00 00 50 69 67 67  79 20 06 00 00 00 00 00  |....Piggy ......|
    00000040  00 00 4d 61 6b 65 75 70  fc 08 00 00 05 00 00 00  |..Makeup........|
    00000050  00 00 00 00 47 6f 6e 7a  6f 07 00 00 00 00 00 00  |....Gonzo.......|
    00000060  00 45 66 66 65 63 74 73                           |.Effects|
    00000068

The general format for this file is this: the first integer-sized block of data contains the number of employees stored in the file. The next integer-sized block contains the employee salary. The next integer-sized block contains the length of the employee's name. The next n sized block contains the employee's name. The next integer-sized block contains the length of the employee's department. The next n sized block contains the employee's department. This pattern is then repeated for each employee in the file as specified by the first block in the file. Using this format eliminates the need for padding strings, and minimizes file size as unnecessary padding characters are not included.

###employee_read_binary

The program employee_read_binary reads in the file created by employee_write_binary (employee_output.dat) and displays the contents. Running it with the data file created above produces the following output:

    user@system:~/CS2303-Homework-4$ ./employee_read_binary
    Employee. Name = Kermit, Salary = 333, Department = Production
    Employee. Name = Piggy , Salary = 500, Department = Makeup
    Employee. Name = Gonzo, Salary = 2300, Department = Effects

