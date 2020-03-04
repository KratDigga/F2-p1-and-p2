//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "contactHelpers.h"
#define MAXCONTACTS 5


//--------------------------------
// Function Definitions
//--------------------------------

// Clear the standard input buffer
void clearKeyboard(void) {
    while (getchar() != '\n')   ; // empty execution code block on purpose
}

// pause function stops the program and prompts the user to input the enter key to continue
void pause(void) { 
	printf("(Press Enter to Continue)");
	clearKeyboard();
  printf("\n");
}

// getInt function takes the input of the user and outputs it to the display:
int getInt(void) { //
	int value;
	char NL = 'x';

	scanf(" %d%c", &value, &NL);
	  while (NL != '\n') { // makes it so that any characters enter in to the STDIN it will not be accepted
		  clearKeyboard();
	    	printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		      scanf(" %d%c", &value, &NL);
	  }
	          return value;

}

/* getIntInRange function keeps the Int function in a set range which is set with min and max. 
It does this by setting an int (in this case iLoc) to the Int function and uses a while loop to set parameters*/
int getIntInRange(int min, int max) {
	int iLoc = getInt();

	while ((iLoc < min) || (iLoc > max)) {
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		  iLoc = getInt();
	}
      	return iLoc;
}

// yes function takes 2 (or 4 single character inputs) values from the users input y or n (which is not case sensitive)
int yes(void) {
	int input = -1;
	char sCharacter1 = 'x';
	char sCharacter2 = 'x';

	scanf(" %c%c", &sCharacter1, &sCharacter2);
  	while (!((sCharacter2 == '\n') && ((sCharacter1 == 'Y') || (sCharacter1 == 'y') || (sCharacter1 == 'N') || (sCharacter1 == 'n')))) {
		  clearKeyboard();
		    printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
	      	scanf(" %c%c", &sCharacter1, &sCharacter2);
	  }
	          if ((sCharacter1 == 'Y') || (sCharacter1 == 'y')) {
		          input = 1;
	          }
	              else if ((sCharacter1 == 'N') || (sCharacter1 == 'n')) {
		            input = 0;
	              }
              return input;
}

// menu:
int menu(void)
{
	int range;
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

	range = getIntInRange(0, 6);
	printf("\n");

	return range;
}

// contactManagerSystem:
void contactManagerSystem(void)
{
	struct Contact contacts[MAXCONTACTS] =
	{ { { "Rick",{ '\0' }, "Grimes" },
	{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
	{ "4161112222", "4162223333", "4163334444" } },
 {
	 { "Maggie", "R.", "Greene" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9051112222", "9052223333", "9053334444" } },
 {
	 { "Morgan", "A.", "Jones" },
	{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
	{ "7051112222", "7052223333", "7053334444" } },
 {
	 { "Sasha",{ '\0' }, "Williams" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9052223333", "9052223333", "9054445555" } },
	};

	int option = 0;

	while (option == 0) {

		switch (menu())
		{
		case 1:
			displayContacts(contacts, MAXCONTACTS);
			pause();
			break;
		case 2:
			addContact(contacts, MAXCONTACTS);
			pause();
			break;
		case 3:
			updateContact(contacts, MAXCONTACTS);
			pause();
			break;
		case 4:
			deleteContact(contacts, MAXCONTACTS);
			pause();
			break;
		case 5:
			searchContacts(contacts, MAXCONTACTS);
			pause();
			break;
		case 6:
			printf("<<< Feature to sort is unavailable >>>\n\n");
			pause();
			break;
		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			option = yes();
			printf("\n");
			if (option == 1){
				printf("Contact Management System: terminated\n");
			}
			break;

		default:
			break;
		}
	}
}

void getTenDigitPhone(char phoneNum[]) {
	int i = 0;
	scanf(" %[^\n]s", phoneNum);
	clearKeyboard();
	for (i = 0; i < 10; i++) {
		while (phoneNum[i] < '0' || phoneNum[i] > '9' || strlen(phoneNum) != 10) {
			printf("Enter a 10-digit phone number: ");
			scanf(" %[^\n]s", phoneNum);
			i = 0;
			clearKeyboard();
		}
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]) {
  int result= -1, i = 0;
    for ( i = 0; i < size; i++) {
      if ( strcmp(contacts[i].numbers.cell, cellNum) == 0)
          result = i;
    }
    return result;

}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}


// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int count) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", count);
}

// Display specified test section header
void printSectionHeader(const char *testName)
{
    printf("\n");
    printf("------------------------------------------\n");
    printf("Testing: %s\n", testName);
    printf("------------------------------------------\n");
}

// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact* contact) {
	printf(" %s", contact->name.firstName);

	if (strlen(contact->name.middleInitial) != 0) {
		printf(" %s", contact->name.middleInitial);
	}

	printf(" %s\n", contact->name.lastName);
	printf("    C: %-10s   H: %-10s   B: %-10s\n",contact->numbers.cell,contact->numbers.home,contact->numbers.business);
	printf("       %d %s, ",contact->address.streetNumber,contact->address.street);

	if (contact->address.apartmentNumber > 0) {
		printf("Apt# %d, ", contact->address.apartmentNumber);	
	}

	printf("%s, %s\n",contact->address.city, contact->address.postalCode);
}


// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size) {
	int i;
	int count = 0;
	displayContactHeader();
	 
		for (i = 0; i < size; i++) {
			if (strlen(contacts[i].numbers.cell) != 0){
			displayContact(&contacts[i]);
			count++;
			}
		}
	displayContactFooter(count);

}


// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contacts[], int size) {
	char search[11];
	int indexsearch;
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(search);

	indexsearch = findContactIndex(contacts, size, search);

	if(indexsearch == -1){
		printf("*** Contact NOT FOUND ***\n\n");
	}
	else {	
		printf("\n");
		displayContact(&contacts[indexsearch]);
		printf("\n");
	}
	
}


// addContact:
// Put empty function definition below:
void addContact(struct Contact contacts[], int size) {
	int i;
	int empty = -1;
	for (i = 0; i < size; i++) {
		if (strlen(contacts[i].numbers.cell) == 0) {
			getContact(&contacts[i]);
			empty = i;
		}
	}
	if (empty == -1) {
		printf("*** ERROR: The contact list is full! ***\n\n");
	}
	else {
		printf("--- New contact added! ---\n\n");
	}
}


// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contacts[], int size) {
	char search[11];
	int indexsearch;
	int choice;
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(search);

	indexsearch = findContactIndex(contacts, size, search);
	
	if (indexsearch == -1) {
		printf("*** Contact NOT FOUND ***\n\n");
	}else {
		printf("\nContact found:\n");

		displayContact(&contacts[indexsearch]);
		printf("\nDo you want to update the name? (y or n): ");
		choice = yes();
		if (choice == 1) {
			getName(&contacts[indexsearch].name);
		}

		printf("Do you want to update the address? (y or n): ");
		choice = yes();
		if (choice == 1) {
			getAddress(&contacts[indexsearch].address);
		}
		
		printf("Do you want to update the numbers? (y or n): ");
		choice = yes();
		if (choice == 1) {
			getNumbers(&contacts[indexsearch].numbers);
		}
		printf("--- Contact Updated! ---\n\n");
	}
}


// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contacts[], int size) {
	char search[11];
	int indexsearch;
	int choice;
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(search);

	indexsearch = findContactIndex(contacts, size, search);

	if (indexsearch == -1) {
		printf("*** Contact NOT FOUND ***\n\n");
	}
	else {
		printf("\nContact found:\n");

		displayContact(&contacts[indexsearch]);
		printf("\nCONFIRM: Delete this contact? (y or n): ");
		choice = yes();
		if (choice == 1) {

			contacts[indexsearch].numbers.cell[0] = '\0';
			printf("--- Contact deleted! ---\n");
		}
		printf("\n");
	}
}
// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact uContact[], int size) {
	
}

    int getStreetnumber(void) {
  int range;
  do{
    range = getInt();
      if(range < 0) 
        printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
  } while (range < 0);
  return range;
}

int getApartmentnumber(void) {
  int range;
  do{
    range = getInt();
      if(range < 0) 
        printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
  } while (range < 0);
  return range;
}
