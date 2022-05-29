#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 2                                                    // define the number of employee size to be 2

struct employee                                                   // declared a struct to represent employee data
{
	int ID;                                                       // declared ID number as an integer
	int Age;                                                     // declared age as an integer
	double Salary;                                               // declared salary as a double
};


int main(void)                                                         // main function
{
	int option = 0, i = 0, j = 0;                                       // declare and initialize option=0, i=1
//	int counter = 0;                                         // initialize counter=0 to find if array is full or not
	struct employee emp[SIZE] = { {0} };                          // initializing all elements of emp array as zero

	printf("---=== EMPLOYEE DATA ===---\n\n");                  // displaying title of application

	do
	{
		printf("\n1. Display Employee Information\n");              // dispaly employee information
		printf("2. Add Employee\n");                                // display add employee
		printf("0. Exit\n\n");                                      // display exit

		printf("Please select from the above options: ");             // display to select option 1, 2, or 3
		scanf("%d", &option);                                          // user input option number 1, 2, or 3
		printf("\n");                                                 // adding a new line


		switch (option)                                               // switch statment options set as 0,1,2,default
		{
		case 0:	                                                       // if user input case 0:

			printf("Exiting Employee Data Program. Good Bye!!!");       // display the folowing message then exit

			break;                                                      // exit the program

		case 1:                                                          // if user input case 1

			printf("EMP ID  EMP AGE EMP SALARY\n");                      // display the following statement
			printf("====== ====== ==========\n");
			for (i = 0; i <= SIZE; i++)                            // run the employee data for SIZE=2 times
			{
				if (emp[i].ID > 0)                          // where employee ID > 0 (which is valid), display the next statement
				{
					printf("%6d%9d%11.2lf", emp[i].ID, emp[i].Age, emp[i].Salary);   // display employees ID, Age, and Salary
					emp[i].ID = 0;                                               // set the condition conflict as while loop to stop executing while loop
					printf("\n");                                                 // adding a new line
				}
			}
			break;

		case 2:                                                           // if user input case 2:

			printf("Adding Employee\n");                                        // display following message
			printf("===============\n");                                         // display the following message

			if (j < SIZE)                                                  // using j to find if emp[array] is full or not + store new employee data by increasing 1
			{
				printf("Enter Employee ID:");                                        // display add employee
				scanf("%d", &emp[j].ID);                                         // user input emp id, store it in emp array id
				printf("Enter Employee Age:");                                       // display enter employee age
				scanf("%d", &emp[j].Age);                                        // user input employee age, store it in emp array age
				printf("Enter Employee Salary:");                                    // display enter employee salary
				scanf("%lf", &emp[j].Salary);                                    // user input salary, store it in emp array salary                                                                      
				j++;                                                            // j increased by 1
			}
			else
			{
				printf("ERROR!!! Maximum Number of Employees Reached\n");
			}
			break;

		default:                                                                 // if user input option is not correct (should be 0,1 or 2)
			printf("ERROR: Incorrect Option: Try Again\n\n");                    // dispaly following error message
		}

	} while (option != 0);                                                        // if user input option!=0, then run the application again

	return 0;
}