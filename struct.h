#ifndef STRUCT_H
#define STRUCT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>

/**
 * @brief A struct to hold information about an employee.
 */
typedef struct
{
    int salary; ///< Montly employee salary.
    char *name; ///< Pointer to employee name.
    char *department; ///< Pointer to employee department.
} Employee;

void printEmployee(Employee *employee);
void outputEmployee(FILE *stream, Employee *employee);
Employee* make_employee(int salary, char* emp_name, char* department);
Employee* prompt_for_employee();
void free_employee(Employee* emp);
void outputEmployeeRaw(FILE *stream, Employee *employee);
Employee* read_employee(FILE *stream);
void outputEmployeeBinary(int stream, Employee *employee);
Employee* read_employee_binary(int stream);
char* str_padleft(const char* str, char pad, size_t bytes);

#endif

