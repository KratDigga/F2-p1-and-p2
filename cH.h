#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contactHelpers.h"

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
	  clearKeyboard(); //clear STDin buffer
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

// menu function displays the programs menu and returns the values 0 to 6 which are used to move through the program
int menu(void)
{
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");

	return getIntInRange(0, 6);
}

// contactManagerSystem function is the program
void contactManagerSystem(void)
{
	int option;
	int input;

	do {
		option = menu();
		switch (option)
		{

		case 1:
			printf("\n<<< Feature 1 is unavailable >>>\n\n\n");
			pause();
			break;

		case 2:
			printf("\n<<< Feature 2 is unavailable >>>\n\n\n");
			pause();
			break;

		case 3:
			printf("\n<<< Feature 3 is unavailable >>>\n\n\n");
			pause();
			break;

		case 4:
			printf("\n<<< Feature 4 is unavailable >>>\n\n\n");
			pause();
			break;

		case 5:
			printf("\n<<< Feature 5 is unavailable >>>\n\n\n");
			pause();
			break;

		case 6:
			printf("\n<<< Feature 6 is unavailable >>>\n\n\n");
			pause();
			break;

		case 0:
			printf("\nExit the program? (Y)esmor (N)o: ");
			input = yes();
			if (input == 1)
			{
				printf("\nContact Management System: terminated\n");
				return;
			}

		default:
			printf("*** OUT OF RANGE *** <Enter a number between 0 and 6> ");
			break;
		}

	} while ((input >= 0) || (input <= 6));

}
// Aditional Functions to keep street and apartment # from going into negative


    int getStreetnumber(void) {
  int range;
  do{
    range = getInt();
      if(range < 0) 
        printf("*** INVALID STREET NUMBER *** <must be a postive number>: ");
  } while (range < 0);
  return range;
}

int getApartmentnumber(void) {
  int range;
  do{
    range = getInt();
      if(range < 0) 
        printf("*** INVALID APARTMENT NUMBER *** <must be a postive number>: ");
  } while (range < 0);
  return range;
}
