#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <stdio.h>

#include <stdlib.h>

#include <string.h>



struct Employee{

        char Name[100];

        int ID;

        float Salary;

        char Department[50];

        int YOE;

        float Performance;



};


//Function Prototypes

void addEmployee(struct Employee **arr, int *n);

void updateEmployee(struct Employee **arr, int *n);

void displayEmployees(struct Employee **arr, int *n);

void searchEmployeeByName(struct Employee **arr, int *n);

void sortEmployeesByPerformance(struct Employee **arr, int *n);

#endif




           
