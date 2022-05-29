#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10                                                  // initialize the number of elements: days, high and low values as 10
#include <stdio.h>

int main()
{
	printf("---=== IPC Temperature Calculator V2.0 ===---\n");    // title of application

	int days, i, highest, lowest, dayHigh, dayLow, dayNO, sum=0;       // initialize all variables
	double average;                                                         
	int high[SIZE];                                                  
	int low[SIZE];

	printf("Please enter the number of days, between 3 and 10, inclusive: ");   // prompt user input number of days
	scanf("%d", &days);                                                         // user input   

	while(days<3 || days>10)                                                    // if user input the value out of range, repeat until user put correct input
	{ 
		printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");    // prompt user to enter number of days again
		scanf("%d", &days);                                                              // user input
	}

		for (i= 1; i<=days; i++)                           // use to repeat number of days: day 1, day 2, ...., day(days)
		{                                                            
			printf("Day %d - High: ", i);                 // prompt user enter high temperature on the corresponding days
			scanf("%d", &high[i-1]);                      // user input of high temp & store the value in array high temperature         
			printf("Day %d - Low: ", i);                  // prompt user enter low temperature on the corresponding days        
			scanf("%d", &low[i-1]);                       // user input of low temp & store the value in array low temperature       
		}

		printf("\nDay  Hi  Low\n");                       // display the names of parallel array        

		for (i = 1; i <= days; i++)                       // repeat parallel arrays of high and low values on each day            
		{
			printf("%d%5d%6d\n", i, high[i - 1], low[i - 1]);       // display parallel array of high and low values on each day    

			if (i == 1)                                   // stating if it is day 1, then the following:
			{
				highest = high[i-1];                      // the first day of high temperature is set as highest
				lowest = low[i-1];                        // the first day of low temperature is set as lowest
				dayHigh = 1;                              // dayHigh = day 1 
				dayLow = 1;                               // dayLow = day 1
			}

			else                                            // starting from day 2, 3, 4,.....so on, has the following:
			{
				if (high[i-1] > highest)                    //  if high temperature greater than the previous highest         
				{
					highest = high[i-1];                    // second high temperature will set as highest, and third, and forth,..., so on
					dayHigh = i;                            // dayHigh will change depending on which day has highest value
				}

				if (low[i-1] < lowest)                      // if low temperature is lower than the previous lowest                    
				{
					lowest = low[i-1];                      // second low temperature will set as lowest, and third, and forth,..., so on
					dayLow = i;                             // dayLow will change depending on which day has lowest temperature
				}
			}

		}

		printf("\nThe highest temperature was %d, on day %d\n", highest, dayHigh);       // display the highest temperature on corresponding day
		printf("The lowest temperature was %d, on day %d\n", lowest, dayLow);          // display the lowest temperature on corresponding day  


		printf("\nEnter a number between 1 and 5 to see the average temperature for the entered number of days, enter a negative number to exit: ");
		scanf("%d", &dayNO);                                 // prompt user input number of days between 1 and 5
		                                                     // user input number of days (1-5)
		
		int j = 0;
		while (j==0)                                          // used to itearte average temp, enter the number again, and invalid entry.
		{		
			if (1 <= dayNO && dayNO<= 5)                        // if user input the number in correct range
			{
				for (i = 1; i <= dayNO; i++)                    // to calculate sum, use for loop to store each days of sum
				{ 
					sum = sum + high[i - 1] + low[i - 1];          // sum of each day high and low value
				}                                               
				    average =(double) sum / dayNO / 2;        // average temperature between high and low value

			    printf("\nThe average temperature up to day %d is: %.2lf\n", dayNO, average);     // display average temperature
				sum = 0;                                                                          // clear previous sum and set it to 0
				printf("\nEnter a number between 1 and 5 to see the average temperature for the entered number of days, enter a negative number to exit: ");
				scanf("%d", &dayNO);				                             // prompt user enter the number of days again
			}                                                                    // user input again

			if (dayNO==0 || dayNO > 5)                                          // if user input number of days out range
			{
				printf("\nInvalid entry, please enter a number between 1 and 5, inclusive: ");  // invalid range, prompt user enter again
				scanf("%d", &dayNO);                                                          // user input again
			}

			if (dayNO < 0)                                                      // if user input negative value
			{
				printf("\nGoodbye!");                                             // display goodbye!
				break;                                                          // out of loop
			}

		}

	return 0;
}
