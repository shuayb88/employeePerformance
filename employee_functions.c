#include "employee.h"

void addEmployee(struct Employee **arr, int *n){

       	int buffer;

        (*n)++;       

        void *temp = realloc(*arr, (*n) * sizeof(struct Employee));



        if(temp==NULL){

                printf("Memory allocation failed\n");

                exit(0);

        }



        *arr = temp;

        struct Employee *e = &(*arr)[(*n)-1];



	while ((buffer = getchar()) != '\n' && buffer != EOF);

        printf("Enter name of employee: ");
	
	fgets(e->Name, sizeof(e->Name), stdin);

        e->Name[strcspn(e->Name, "\n")] = 0;
       
	// scanf("%s", e->Name);



        printf("Enter employee ID: ");

        scanf("%d", &e->ID);



        printf("Enter salary: ");

        scanf("%f", &e->Salary);

	getchar();

        printf("Enter department: ");
	fgets(e->Department, sizeof(e->Department), stdin);

    	e->Department[strcspn(e->Department, "\n")] = 0;
        //scanf("%s", e->Department);



        printf("Enter years of experience: ");

        scanf("%d", &e->YOE);

        

        //printf("Performance score: ");

        //scanf("%f", &e->Performance);

        

        e->Performance = (0.3 * e->YOE) + (0.7 * e->Salary)/1000;

	getchar();

        //free(temp);    

}



void updateEmployee(struct Employee **arr, int *n){

        

        int search_term;

        

        //Search for Employee

        printf("Enter Employee ID to update: ");

        scanf("%d", &search_term);

        

        for(int i=0; i<*n; i++){

            if(search_term == (*(*arr+i)).ID){

                struct Employee *e = *arr + i;

                printf("Enter new salary: ");

                scanf("%f", &e->Salary);

                

                printf("Enter new department: ");

                scanf("%s", e->Department);

                

                e->Performance = (0.3 * e->YOE) + (0.7 * e->Salary)/1000;

            }

        }

        

        printf("Employee information updated successfully!\n");

    

    

}



void displayEmployees(struct Employee **arr, int *n){

    

    sortEmployeesByPerformance(arr, n);

    

    printf("Employee Records (sorted by Performance Score):\n");

    for(int i=0; i<*n; i++){

        

        printf("Name: %s\n", (*arr)[i].Name);

        printf("Employee ID: %d\n", (*arr)[i].ID);

        printf("Salary: %.2f\n", (*arr)[i].Salary);

        printf("Department: %s\n", (*arr)[i].Department);

        printf("Years of Experience: %d\n", (*arr)[i].YOE);

        printf("Performance Score: %.2f\n", (*arr)[i].Performance);
	//printf("\n");
    
    }

	printf("\n");    

}



void searchEmployeeByName(struct Employee **arr, int *n){

    char nameSearch[100];

    char *found;

    int resultsCount = 0;

    int buffer;
    struct Employee *searchResults = NULL;

    while ((buffer = getchar()) != '\n' && buffer != EOF);

    printf("Enter name to search: ");
	
    fgets(nameSearch, sizeof(nameSearch), stdin);

    nameSearch[strcspn(nameSearch, "\n")] = '\0';



    //scanf("%s", nameSearch);

    

   // printf("Search Results: ");

    

    for(int i=0; i<*n; i++){

        found = strstr((*(*arr+i)).Name, nameSearch);

        if (found != NULL){

            

            resultsCount++;

            searchResults = realloc(searchResults, resultsCount * sizeof(struct Employee));

            searchResults[resultsCount - 1] = (*arr)[i];

        }

    }

    

    if(resultsCount == 0){

        printf("Name not found.\n");

        return;

    }

    

    displayEmployees(&searchResults, &resultsCount);

    free(searchResults);    

}



void sortEmployeesByPerformance(struct Employee **arr, int *n){

    

    struct Employee temp;

    

    for(int i=0; i<(*n); i++){

        

        for(int j=0; j< (*n-1); j++){

            if((*arr)[j].Performance < (*(*arr+j+1)).Performance){

                temp = (*arr)[j];

                (*arr)[j] = (*arr)[j + 1];

                (*arr)[j + 1] = temp;

            }

        }

    }

    

    

}
