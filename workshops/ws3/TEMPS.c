

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include <stdio.h>
#define NUMS 4

int main()
{
	int i, highValue, lowValue, highest, lowest, highDay, lowDay;
	double avareage, maxTotal, minTotal;


	printf("---=== IPC Temperature Analyzer ===---");

	for (i = 1; i <= NUMS; i++)
	{
		int j = 0;
		while (j == 0)
		{
			printf("\nEnter the high value for day %d: ", i);
			scanf("%d", &highValue);
			printf("\nEnter the low value for day %d: ", i);
			scanf("%d", &lowValue);

			if (highValue<41 && lowValue>-41 && highValue > lowValue)
			{
				j++;
			}
			else {
				printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.");
			}

		}
	}

	return 0;
}
