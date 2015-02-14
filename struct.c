#include "struct.h"

/** Prints the contents of an Employee struct to standard output.
 * @param employee Pointer to the Employee struct to print
 */
void printEmployee(Employee *employee)
{
    outputEmployee(stdout, employee);
}

/** Prints the contents of an Employee struct to a stream,
 * such as an already-opened file.
 * @param stream A pointer to a FILE struct representing an already-open
 *     stream, such as stdout, stderr, or a file.
 * @param employee Pointer to the Employee struct to print
 */
void outputEmployee(FILE *stream, Employee *employee)
{
    fprintf(stream, "Employee. Name = %s, Salary = %d, Department = %s\n",
            employee->name, employee->salary, employee->department);
}

/** 
 * @brief Creates an employee struct and fills it with provided data.
 * 
 * @param salary The employee's salary.
 * @param name The employee's name.
 * @param department The employee's department.
 * 
 * @return A pointer to the newly-created employee.
 */
Employee* make_employee(int salary, char* emp_name, char* department)
{
    Employee * emp = (Employee*)malloc(sizeof(Employee));
    emp->salary = salary;
    emp->name = strdup(emp_name);
    emp->department = strdup(department);
    return emp;
}

