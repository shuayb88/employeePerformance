#include "employee.h"

int main(){



        int n = 0;

        int choice;

        struct Employee *e = NULL;

        

        while(1){

            printf("Employee Performance Management System\n");

            printf("1. Add Employee\n");

            printf("2. Update Employee\n");

            printf("3. Display all Employees\n");

            printf("4. Search Employee by Name\n");

            printf("5. Exit\n");

	    printf("Enter your choice: ");

            scanf ("%d", &choice);

            

            if(choice==1) addEmployee(&e, &n);

            else if(choice==2) updateEmployee(&e, &n);

            else if(choice==3) displayEmployees(&e, &n);

            else if(choice==4) searchEmployeeByName(&e, &n);

            else if(choice==5){

                printf("Exiting...\n");

                break;

            }

            else printf("Please select one of the given options.\n");

        }

        

        

        free(e);

        return 0;

}
