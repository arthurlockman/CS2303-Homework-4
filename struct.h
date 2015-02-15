#ifndef STRUCT_H
#define STRUCT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>

// Define some structures
typedef struct
{
    int salary; // Monthly salary in UK pounds sterling
    char *name; // Pointer to character string holding name of employee.
    char *department;
} Employee;

typedef struct
{
    int salary;
    char name[100];
    char department[100];
} EmployeeBin;

// function prototypes
void printEmployee(Employee *employee);
void outputEmployee(FILE *stream, Employee *employee);
Employee* make_employee(int salary, char* emp_name, char* department);
Employee* prompt_for_employee();
void free_employee(Employee* emp);
void outputEmployeeRaw(FILE *stream, Employee *employee);
Employee* read_employee(FILE *stream);
void outputEmployeeBinary(FILE *stream, Employee *employee);
Employee* read_employee_binary(FILE *stream);
char* str_padleft(const char* str, char pad, size_t bytes);

#endif

