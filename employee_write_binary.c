#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include <errno.h>

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
    FILE *outfile = fopen("employee_output.dat", "wb");
    if (outfile == NULL)
    {
        printf("Error in employee_write_binary: %d (%s)\n", errno, strerror(errno));
        return 1;
    }
    
    fwrite(&num_employees, sizeof(int), 1, outfile);
    for (i = 0; i < num_employees; i++)
    {
        printEmployee(emp_array[i]);
        outputEmployeeBinary(outfile, emp_array[i]);
        free_employee(emp_array[i]);
    }
    
    fclose(outfile);
}

