#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include <errno.h>

/** 
 * @brief Read in employees from a text file created by 
 * employee_write_text.
 * 
 * @return 1 if file failure, otherwise 0.
 */
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

