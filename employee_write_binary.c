#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * @brief Writes a binary file containing input employees. This file
 * has the following format:
 *
 * first 16 bits: number of employees in file
 * next 16 bits: employee 1's salary
 * next 16 bits: number of characters in employee name
 * next n bits: employee name
 * next 16 bits: number of characters in employee department
 * next n bits: employee department
 *
 * This pattern repeats for as many employees as specified in the first block.
 *
 * @return
 */
int main()
{
    int cont = 1;
    char* line;
    int num_employees;

    while (cont)
    {
        line = readline("How many employees are there? ");
        if (sscanf(line, "%d", &num_employees)) cont = 0;
        free(line);
    }

    Employee** emp_array = (Employee**)malloc(sizeof(Employee) * num_employees);
    int i;
    for (i = 0; i < num_employees; i++)
    {
        emp_array[i] = prompt_for_employee();
    }
    int outfile = open("employee_output.dat", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR |
                       S_IXUSR | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
    if (outfile < 0)
    {
        printf("Error in employee_write_binary: %d (%s)\n", errno, strerror(errno));
        return 1;
    }

    write(outfile, &num_employees, sizeof(int));
    for (i = 0; i < num_employees; i++)
    {
        printEmployee(emp_array[i]);
        outputEmployeeBinary(outfile, emp_array[i]);
        free_employee(emp_array[i]);
    }

    close(outfile);
}

