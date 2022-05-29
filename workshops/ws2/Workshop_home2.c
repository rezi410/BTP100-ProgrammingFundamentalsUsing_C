#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double amount, GST;
	float balanceOwing, balance;
	int loonies, quarters, dimes, nickels, pennies;

	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amount);

	GST = amount * .13 + .005;
	printf("GST: %.2lf\n", GST);	
	balanceOwing = amount + GST;
	printf("Balance owing: $%.2lf\n", balanceOwing);

	loonies = balanceOwing;
	printf("Loonies required: %d, ",loonies);

	balanceOwing = balanceOwing - loonies;
	printf("balance owing $%1.2lf\n", balanceOwing);

	balanceOwing = balanceOwing * 100;
	quarters = balanceOwing/25;
	printf("Quarters required: %d, ", quarters);

	balance =(float) ((balanceOwing/100) - (quarters * .25));
	printf("balance owing $%1.2lf\n", balance);

	dimes = (int)(balance*100) / 10;
	printf("Dimes required: %d, ", dimes);
	
	balance = (float)balance - (dimes * .1);
	printf("balance owing $%1.2lf\n", balance);

	nickels = (int)(balance * 100)/5;
	printf("Nickels required: %d, ", nickels);

	balance = (float)balance - (nickels * .05);
	printf("balance owing $%1.2lf\n", balance);

	pennies = (int)(balance * 100)/1;
	printf("Pennies required: %d, ", pennies);

	balance = (float)balance - (pennies * .01);
	printf("balance owing $%1.2lf\n", balance);

	return 0;
}