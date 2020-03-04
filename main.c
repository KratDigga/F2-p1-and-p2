#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"

void printSectionHeader(const char*);

int main(void)
{
    struct Contact contact = { { { '\0' } } };
    int tstInteger;
    //--------------------------------------------------------
    printSectionHeader("getContact(struct Contact *)");
    getContact(&contact);
    printf("\nValues Entered:\n");
    printf("Name: %s %s %s\n", contact.name.firstName, contact.name.middleInitial, contact.name.lastName);
    printf("Address: %d|%s|%d|%s|%s\n", contact.address.streetNumber, contact.address.street, 
        contact.address.apartmentNumber, contact.address.postalCode, contact.address.city);
    printf("Numbers: %s|%s|%s\n", contact.numbers.cell, contact.numbers.home, contact.numbers.business);

    //--------------------------------------------------------
    printSectionHeader("contactManagerSystem()");
    contactManagerSystem();

    //--------------------------------------------------------
    printSectionHeader("Assign#2 - MS #2 test completed");

    return 0;
}

// Display specified test section header
void printSectionHeader(const char* testName)
{
    printf("\n");
    printf("------------------------------------------\n");
    printf("Testing: %s\n", testName);
    printf("------------------------------------------\n");
}
