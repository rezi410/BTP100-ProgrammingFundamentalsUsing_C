
#define _CRT_SECURE_NO_WARNINGS

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+


#include <stdio.h>
#include <ctype.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
#include "contacts.h"
#include "contactHelpers.h"
#include <string.h>
// getName
void getName(struct Name* name)
{
    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]", name->firstName);
    clearKeyboard();

    printf("Do you want to enter a middle initial(s)? (y or n): ");
    if (yes())
    {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]", name->middleInitial);
        clearKeyboard();
    }
    else
    {
        name->middleInitial[0] = '\0';
    }
    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]", name->lastName);
    clearKeyboard();
}

// getAddress:
void getAddress(struct Address* address)
{
 
    int number, flag;

    printf("Please enter the contact's street number: ");
    do {
        flag = 0;
        number = getInt();
        if (number <= 0)
        {
            printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
            //scanf("%d", &number);
            //clearKeyboard();
        }
        else
        {
            address->streetNumber = number;
            flag = 1;
        }

    } while (flag == 0);

    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]", address->street);
    clearKeyboard();

    printf("Do you want to enter an apartment number? (y or n): ");

    if (yes())
    {
 
            printf("Please enter the contact's apartment number: ");
            address->apartmentNumber = getInt();

            if (address->apartmentNumber <= 0)
            {
               printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
               scanf("%d", &address->apartmentNumber);
               clearKeyboard();
            }
    }
    else
    {
        address->apartmentNumber = '\0';
    }

    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]", address->postalCode);
    clearKeyboard();

    printf("Please enter the contact's city: ");
    scanf("%40[^\n]", address->city);
    clearKeyboard();
}

// getNumbers:
void getNumbers(struct Numbers* numbers)
{
    printf("Please enter the contact's cell phone number: ");
    scanf("%10[^\n]", numbers->cell);
    clearKeyboard();
    getTenDigitPhone(numbers->cell);
    printf("Do you want to enter a home phone number? (y or n): ");
    if (yes())
    {
        printf("Please enter the contact's home phone number: ");
        scanf("%10[^\n]", numbers->home);
        clearKeyboard();
        getTenDigitPhone(numbers->home);
    }
    else
    {
        strcpy(numbers->home, "\0");
    }

    printf("Do you want to enter a business phone number? (y or n): ");
    if (yes())
    {
        printf("Please enter the contact's business phone number: ");
        scanf("%10[^\n]", numbers->business);
        clearKeyboard();
        getTenDigitPhone(numbers->business);
    }
    else
    {
        strcpy(numbers->business, "\0");
    }
}

// getContact:
// Define Empty function definition below:
void getContact(struct Contact* contact)
{
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}
