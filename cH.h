//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#ifndef CONTACTHELPERS_H
#define CONTACTHELPERS_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"

// clearKeyboard:
void clearKeyboard(void);

// pause:
void pause(void);

// getInt:
int getInt(void);

// getIntInRange:
int getIntInRange(int min, int max);

// yes:
int yes(void);

// menu:
int menu(void);

// contactManagerSystem:
void contactManagerSystem(void);

// Generic function to get a ten-digit phone number:
// getTenDigitPhone:
void getTenDigitPhone(char phoneNum[]);

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]);

// displayContactHeader:
void displayContactHeader(void);

// displayContactFooter:
void displayContactFooter(int count);

// displayContact:
void displayContact(const struct Contact* contact);

// displayContacts:
void displayContacts(const struct Contact contacts[], int size);

// searchContacts:
void searchContacts(const struct Contact contacts[], int size);

// addContact:
void addContact(struct Contact contacts[], int size);

// updateContact:
void updateContact(struct Contact contacts[], int size);

// deleteContact:
void deleteContact(struct Contact contacts[], int size);

// sortContacts:
void sortContacts(struct Contact contacts[], int size);

//Additional functions
int getStreetnumber(void);
int getApartmentnumber(void);

#endif
