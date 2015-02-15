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

    FILE *outfile = fopen("employee_output.txt", "w"); // Open or create file for writing
    if (outfile == NULL)
    {
        printf("Error in employee_write_text: %d (%s)\n", errno, strerror(errno));
        return 1;
    }

    for (i = 0; i < num_employees; i++)
    {
        printEmployee(emp_array[i]);
        outputEmployeeRaw(outfile, emp_array[i]);
        free_employee(emp_array[i]);
    }

    fclose(outfile); // Close the file
}

