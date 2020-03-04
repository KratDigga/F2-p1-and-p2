//==============================================
// Assignment:     2
// Milestone:      2
//==============================================
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"

/*This function will gather all the information that will be stored in struct Name and used by struct name of the Contact struct. It will do so by prompting the user 
to input their first name, middle intial and lastname using character strings and additional functions.*/

void getName(struct Name *name){
	printf("Please enter the contact's first name: ");
	  scanf(" %30[^\n]s", name->firstName);
      clearKeyboard();
		    printf("Do you want to enter a middle initial(s)? (y or n): ");
		      int input = yes();
		        if (input == 0) {
			        name->middleInitial[0] = '\0';
		        } 
              			else {
			      printf("Please enter the contact's middle initial(s): ");
			    scanf(" %10[^\n]s", name->middleInitial);
                                }
			clearKeyboard();
		printf("Please enter the contact's last name: ");
		  scanf(" %35[^\n]s", name->lastName);
}

/*This function will gather all the information that will be stored in struct Address and used by struct address of the Contact struct. It will do so by prompting the
user to input their street #, street name and/or apartment number using character strings & additional functioins.*/

void getAddress(struct Address *address) {
  printf("Please enter the contact's street number: ");
	address->streetNumber = getStreetnumber();
	    printf("Please enter the contact's street name: ");
	      scanf(" %40[^\n]s", address->street);
          clearKeyboard();
            printf("Do you want to enter an apartment number? (y or n): ");
		          int input = yes();
		          if (input == 0) {
			      address->street[0] = 0;
		          }
			   else {
			printf("Please enter the contact's apartment number: ");
	    address->apartmentNumber = getApartmentnumber();
	    	    	   }
	  printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]s", address->postalCode);
    clearKeyboard();
printf("Please enter the contact's city: ");
scanf(" %40[^\n]s", address->city);
}

/*This function will gather all the information that will be stored in struct Number and used by struct number of the Contact struct. It will do so by prompting the
user to choose if they want to input their cellphone #, home phone # and/or business phone # using character strings & additional functioins.*/

void getNumbers(struct Numbers *numbers) {
  printf("Please enter the contact's cell phone number: ");
    scanf("%10s", numbers->cell);
      printf("Do you want to enter a home phone number? (y or n): ");
        int input = yes();
          if (input == 0) {
            numbers->home[0] = '\0';
          }
            else {
              printf("Please enter the contact's home phone number: ");
              scanf("%10s", numbers->home);
            }
            printf("Do you want to enter a business phone number? (y or n): ");
          input = yes();
        if (input == 0) {
      numbers->business[0] = '\0';
        }
    else {
  printf("Please enter the contact's business phone number: ");
scanf("%10s", numbers->business);
    }
}

void getContact(struct Contact *contact) {
  struct Contact contactVer2 = { { {'\0','\0','\0'}, {0, 0, '\0', '\0', '\0'}, {'\0','\0','\0'} } };
    getName(&contactVer2.name);
      getAddress(&contactVer2.address);
        getNumbers(&contactVer2.numbers);
          *contact = contactVer2;
}
