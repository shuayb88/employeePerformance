Employee Performance Management System
This is a C-based program that allows a company to track employee information, calculate performance scores based on salary and experience, and manage records dynamically.

Features
Add Employees: Input name, ID, salary, department, and years of experience.

Update Records: Modify employee details by their unique ID.

Display Records: Shows all employees sorted automatically by their performance score in descending order.

Search: Find employees by name using a substring search.

Dynamic Memory: The program uses malloc and realloc to handle a variable number of employees without needing a fixed array size.

Project Structure
main.c: Contains the main menu loop and program control.

employee.h: Header file containing the struct Employee definition and function declarations.

employee_functions.c: Contains the implementation of the core functions (add, search, update, sort).
