#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include <errno.h>

int main()
{
    FILE *outfile = fopen("employee_output.txt", "r"); //Open file for reading
    
    if (outfile == NULL)
    {
        printf("Error in employee_read_file: %d (%s)\n", errno, strerror(errno));
        return 1;
    }

    //Count number of lines in output file.
    int ch;
    int lines;
    while ((ch = fgetc(outfile)) != EOF)
    {
        if ( ch == '\n' )
            lines++;
    }
    rewind(outfile);
    
    Employee** emp_array = (Employee**)malloc(sizeof(Employee) * lines);
    int i;
    for (i = 0; i < lines; i++)
    {
        emp_array[i] = read_employee(outfile);
        printEmployee(emp_array[i]);
    }

    for (i = 0; i < lines; i++)
        free_employee(emp_array[i]);
    
    fclose(outfile);
}

