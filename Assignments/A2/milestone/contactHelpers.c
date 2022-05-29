

#define _CRT_SECURE_NO_WARNINGS


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        contents below...                        |
// +-------------------------------------------------+


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "contactHelpers.h"

#define MAXCONTACTS 5

// Clear the standard input buffer
void clearKeyboard(void)
{
    while (getchar() != '\n'); 
}

// pause function definition goes here:
void pause(void)
{
      printf("\n(Press Enter to Continue)");    
      clearKeyboard();
}

int getInt(void)
{
    char n1;
    int value;
    scanf("%d%c", &value, &n1);
    if (n1 != '\n')
    {
        clearKeyboard();
    }

    while (n1 != '\n')
    {
        printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        scanf("%d%c", &value, &n1);
        if (n1 != '\n')
        {
            clearKeyboard();
        }

    };
    return value;

}

// getIntInRange function definition goes here:
int getIntInRange(int min, int max)                
{
    int validInt = 0;                                     
    int k = 0;                                             

    validInt = getInt();                                   
    while (k == 0)                                       
    {
        if (validInt < min || validInt > max)          
        {
            printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);   
            scanf("%d", &validInt);  
            clearKeyboard();
        }
        else
        {
            k = 1;
        }
    }                                                              

    return validInt; 
}


int yes(void)
{
    char yN, remain;
    int validch = 2;

    do
    {
        scanf("%c%c", &yN, &remain);

        if ((yN == 'Y' || yN == 'y') && (remain == '\n'))
        {
           validch = 1;
       }
        else if ((yN == 'N' || yN == 'n') && (remain == '\n'))
        {
            validch = 0;
        }
        else
        {
            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
            clearKeyboard();
            
        }
   } while (validch == 2);

    return validch;
}

// menu function definition goes here:
int menu(void)
{
    int select;
    int out = 1;

    printf("Contact Management System\n");
    printf("-------------------------\n");
    printf("1. Display contacts\n");
    printf("2. Add a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search contacts by cell phone number\n");
    printf("6. Sort contacts by cell phone number\n");
    printf("0. Exit\n\n");
    printf("Select an option:> ");
    scanf("%d", &select);
    clearKeyboard();

    while (out == 1)
    {
        if (select < 0 || select > 6)
        {
            printf("*** OUT OF RANGE *** <Enter a number between 0 and 6>: ");
            scanf("%d", &select);
            clearKeyboard();
            out = 1;
        }
        else
        {
            out = 0;
        }
    }

    return select;
}



// contactManagerSystem function definition goes here:
void contactManagerSystem(void)
{
    struct Contact contact[MAXCONTACTS] =
    { { { "Rick", {'\0'}, "Grimes" },
        { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
        { "4161112222", "4162223333", "4163334444"} },
      {
        {"Maggie", "R.", "Greene"},
        { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
        { "9051112222", "9052223333", "9053334444"} },
      {
        { "Morgan", "A.", "Jones" },
        { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
        { "7051112222", "7052223333", "7053334444" } },
      {
        { "Sasha", {'\0'}, "Williams" },
        { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
        { "9052223333", "9052223333", "9054445555" } },
    };
    int option = 0;
    int choice = 0;
    

    while (choice == 0)
    {
        option = menu();
        switch (option)
        {
        case 1:
            printf("\n");
            displayContacts(contact, MAXCONTACTS);
            pause();
            printf("\n");
            break;
        case 2:
            printf("\n");
            addContact(contact, MAXCONTACTS);
            pause();
            printf("\n");
            break;
        case 3:
            printf("\n");
            updateContact(contact, MAXCONTACTS);
            pause();
            printf("\n");
            break;
        case 4:
            printf("\n");
            deleteContact(contact, MAXCONTACTS);
            pause();
            printf("\n");
            break;
        case 5:
//            printf("\n");
            searchContacts(contact, MAXCONTACTS);
            pause();
            printf("\n");
            break;
        case 6:
            printf("\n");
            sortContacts(contact, MAXCONTACTS);
            pause();
            printf("\n");
            break;
        case 0:
            printf("\nExit the program? (Y)es/(N)o: ");
            choice = yes();
            printf("\n");
            if (choice == 1)
            {
                printf("Contact Management System: terminated\n");
            }
            if (choice == 0)
            {
                break;
            }
        }
    }

}




void getTenDigitPhone(char phoneNum[])
{
   int i, check = 0;
   char c;
    do
    {
        for (i = 0; i < 10; i++)
        {
            c = phoneNum[i];
           if ((isdigit(c)!=0) && (strlen(phoneNum) == 10))   // if it is a digit, it does not euqal 0
            {
                check = 1;
            }
            else
            {
                check = 0;
                printf("Enter a 10-digit phone number: ");
                scanf("%10[^\n]", phoneNum);
                clearKeyboard();
                i = 11;
           }
        }

    } while (check != 1);

}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
    int i;

    for (i = 0; i < size; i++)
    {
        if ( strcmp(contacts[i].numbers.cell, cellNum) == 0 )
        {
            return i;
        }
    }

    return -1;
}

// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void)
{
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                              Contacts Listing                               |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}


// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int count)
{
    printf("+-----------------------------------------------------------------------------+\n");
    printf("Total contacts: %d\n", count);
}


// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact* contact)
{
    if (strcmp(contact->name.middleInitial, "") == 0)
    {
        printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
    }
    else
    {
        printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
    }
        printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
    
    if (contact->address.apartmentNumber > 0)
    {
        printf("       %d %s, Apt# %d, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.apartmentNumber, contact->address.city, contact->address.postalCode);
    }
    else
    {
        printf("       %d %s, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.city, contact->address.postalCode);
    }

}


// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size)
{
    displayContactHeader();
    int k = 0;
    int footer = 0;
    for (k = 0; k < size; k++)
    {
        if (strlen (contacts[k].numbers.cell) > 0)
        {
            displayContact(&contacts[k]);
            footer += 1;
        }
    }
    displayContactFooter(footer);
}


// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contacts[], int size)
{
    char phone[11];
    int ph_found;
    printf("\nEnter the cell number for the contact: ");
    scanf("%10[^\n]", phone);
    clearKeyboard();
    getTenDigitPhone(phone);

    ph_found=findContactIndex(contacts,size,phone);
    if (ph_found == -1)
    {
        printf("*** Contact NOT FOUND ***\n");
    }
    else
    {
        printf("\n");
        displayContact(&contacts[ph_found]);
    }
}


// addContact:
// Put empty function definition below:
void addContact(struct Contact contacts[], int size)
{
    int slot;
    char cell[11] = { '\0' };
    slot=findContactIndex(contacts, size, cell);
    if (slot != -1)
    {
        getContact(&contacts[slot]);
        printf("--- New contact added! ---\n");
    }
    else
    {
        printf("*** ERROR: The contact list is full! ***\n");
    }
}


// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contacts[], int size)
{
    int update;
    char cell_no[11];
    printf("Enter the cell number for the contact: ");
    scanf("%10[^\n]", cell_no);
    clearKeyboard();
    getTenDigitPhone(cell_no);
        update = findContactIndex(contacts, size, cell_no);

        if (update==-1)
        {
           printf("*** Contact NOT FOUND ***\n");
          
        }
        else
        {
            printf("\nContact found:\n");
            displayContact(&contacts[update]);
            printf("\n");
            printf("Do you want to update the name? (y or n): ");
            if (yes()==1)
                getName(&contacts[update].name);

            printf("Do you want to update the address? (y or n): ");
            if (yes()==1)
            {
                getAddress(&contacts[update].address);
            }

            printf("Do you want to update the numbers? (y or n): ");
            if (yes()==1)
            {
                getNumbers(&contacts[update].numbers);
            }

                printf("--- Contact Updated! ---\n");
        }
        
}

//deleteContact:
void deleteContact(struct Contact Contacts[], int size)
{
    char cell_num[11];
    int result;
    int m;
    printf("Enter the cell number for the contact: ");
    scanf("%10[^\n]", cell_num);
    clearKeyboard();
    result = findContactIndex(Contacts, size, cell_num);
    if (result == -1)
    {
        printf("*** Contact Not Found ***\n");
    }
    else
    {
        printf("\nContact found:\n");
        displayContact(&Contacts[result]);
        printf("\n");
        printf("CONFIRM: Delete this contact? (y or n): ");
        m = yes();

        if (m == 1)
        {
            Contacts[result].numbers.business[0] = '\0';
            Contacts[result].numbers.cell[0] = '\0';
            Contacts[result].numbers.home[0] = '\0';
            printf("--- Contact deleted! ---\n");
        }
    }
}


// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact contacts[], int size)
{
    printf("<<< Feature to sort is unavailable >>>\n");
}
