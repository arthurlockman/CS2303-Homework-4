#ifndef STRUCT_H
#define STRUCT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define some structures
typedef struct
{
    int salary; // Monthly salary in UK pounds sterling
    char *name; // Pointer to character string holding name of employee.
    char *department;
} Employee;


// function prototypes
void printEmployee(Employee *employee);
void outputEmployee(FILE *stream, Employee *employee);
Employee* make_employee(int salary, char* emp_name, char* department);

#endif
