#include "struct.h"

/**
 * @brief Prints the contents of an Employee struct to standard output.
 *
 * @param employee Pointer to the Employee struct to print
 */
void printEmployee(Employee *employee)
{
    outputEmployee(stdout, employee);
}

/**
 * @brief Prints the contents of an Employee struct to a stream,
 * such as an already-opened file.
 *
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
 * @brief Prints the contents of an Employee struct to a stream,
 * such as an already-opened file. This output is unformatted, meaning
 * it doesn't contain any names for data fields, just the raw data.
 *
 * @param stream A pointer to a FILE struct representing an already-open
 *     stream, such as stdout, stderr, or a file.
 * @param employee Pointer to the Employee struct to print
 */
void outputEmployeeRaw(FILE *stream, Employee *employee)
{
    fprintf(stream, "%s %d %s\n",
            employee->name, employee->salary, employee->department);
}
/**
 * @brief Creates an employee struct and fills it with provided data.
 *
 * @param salary The employee's salary.
 * @param emp_name The employee's name.
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

/**
 * @brief Create an employee based on user input.
 *
 * @return A pointer to the newly created employee.
 */
Employee* prompt_for_employee()
{
    char* line;
    char emp_name[100];
    char emp_department[100];
    int emp_salary;
    int state = 0;
    int cont = 1;
    while (cont)
    {
        switch (state)
        {
        case 0:
            line = readline("Enter the employee's name: ");
            state = 1;
            break;
        case 1:
            if (sscanf(line, "%1000[0-9a-zA-Z ]s", emp_name)) state = 2;
            else
            {
                state = 0;
                printf("Please try again.\n");
                free(line);
            }
            break;
        case 2:
            free(line);
            line = readline("Enter the employee's department: ");
            state = 3;
            break;
        case 3:
            if (sscanf(line, "%1000[0-9a-zA-Z ]s", emp_department)) state = 4;
            else
            {
                state = 2;
                printf("Please try again.\n");
            }
            break;
        case 4:
            free(line);
            line = readline("Enter the employee's salary: ");
            state = 5;
            break;
        case 5:
            if (sscanf(line, "%d", &emp_salary))
            {
                cont = 0;
                free(line);
            }
            else
            {
                state = 4;
                printf("Please try again.\n");
            }
            break;
        }
    }
    Employee* emp = (Employee*)malloc(sizeof(Employee));
    emp->name = strdup(emp_name);
    emp->department = strdup(emp_department);
    emp->salary = emp_salary;
    return emp;
}

/**
 * @brief Free an employee struct.
 *
 * @param emp The struct to free.
 */
void free_employee(Employee* emp)
{
    free(emp->name);
    free(emp->department);
    free(emp);
}

/**
 * @brief Reads an employee from a text file in the
 * format written by outputEmployeeRaw.
 *
 * @param stream The file stream to read from.
 *
 * @return An employee struct, created from the text file.
 */
Employee* read_employee(FILE *stream)
{
    char*  line = NULL;
    size_t len = 0;
    size_t readsize;
    char*  emp_name = (char*)malloc(sizeof(char) * 100);
    char*  emp_department = (char*)malloc(sizeof(char) * 100);
    int    emp_salary;
    if ((readsize = getline(&line, &len, stream)) != -1)
    {
        sscanf(line, "%s %d %s", emp_name, &emp_salary, emp_department);
        return make_employee(emp_salary, emp_name, emp_department);
    }
    else
    {
        printf("No line.\n");
        return NULL;
    }
    if (line) free(line);
}

/**
 * @brief Writes an employee struct to a binary file
 * This file stream must be opened in binary mode.
 *
 * @param stream The output file steam.
 * @param employee The employee to write.
 */
void outputEmployeeBinary(FILE *stream, Employee *employee)
{
    size_t str_length;
    fwrite(&(employee->salary), sizeof(int), 1, stream);
    str_length = strlen(employee->name);
    fwrite(&str_length, sizeof(size_t), 1, stream);
    fwrite(employee->name, strlen(employee->name), 1, stream);
    str_length = strlen(employee->department);
    fwrite(&str_length, sizeof(size_t), 1, stream);
    fwrite(employee->department, strlen(employee->department), 1, stream);
}

/**
 * @brief Reads one employee in from a binary file.
 * The file stream must be opened in binary mode.
 *
 * @param stream The stream to read from.
 *
 * @return A pointer to the newly created employee.
 */
Employee* read_employee_binary(FILE *stream)
{
    int emp_salary;
    fread(&emp_salary, sizeof(int), 1, stream);
    size_t emp_name_len;
    fread(&emp_name_len, sizeof(size_t), 1, stream);
    char* emp_name = (char*)malloc(emp_name_len + 1);
    emp_name[emp_name_len] = '\0';
    fread(emp_name, emp_name_len, 1, stream);
    size_t emp_dept_len;
    fread(&emp_dept_len, sizeof(size_t), 1, stream);
    char* emp_dept = (char*)malloc(emp_dept_len + 1);
    emp_dept[emp_dept_len] = '\0';
    fread(emp_dept, emp_dept_len, 1, stream);
    Employee* emp = (Employee*)malloc(sizeof(Employee));
    emp->salary = emp_salary;
    emp->department = strdup(emp_dept);
    emp->name = strdup(emp_name);
    return emp;
}

