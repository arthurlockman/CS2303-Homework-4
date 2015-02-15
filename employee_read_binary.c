#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include <errno.h>

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
