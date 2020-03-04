#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"

void printSectionHeader(const char *testName);

int main(void)
{
    printSectionHeader("Final A#2-Milestone #4");

    contactManagerSystem();

    return 0;
}
