#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include <errno.h>

/** 
 * @brief Reads a number of employees from a binary file created by 
 * employee_write_binary. Assumes the format written by that program.
 * If the format differs, the program will not work as intended.
 * 
 * @return 1 if file failure, otherwise 0.
 */
int main()
{
    FILE *infile = fopen("employee_output.dat", "rb");
    if (infile == NULL)
    {
        printf("Error in employee_read_binary: %d (%s)\n", errno, strerror(errno));
        return 1;
    }
    int num_employees;
    fread(&num_employees, sizeof(int), 1, infile);
    
    Employee** employees = (Employee**)malloc(num_employees * sizeof(Employee));
    int i;
    for (i = 0; i < num_employees; i++)
    {
        employees[i] = read_employee_binary(infile);
        printEmployee(employees[i]);
    }

    for (i = 0; i < num_employees; i++)
    {
        free_employee(employees[i]);
    }
    fclose(infile);
}
