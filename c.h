//==============================================
// Assignment:     2
// Milestone:      2
//==============================================

struct Name {
	char firstName[31];
	char middleInitial[7];
	char lastName[36];
 }; // Declearing Struct for Name and the members within

struct Address {
	unsigned int streetNumber;
	unsigned int apartmentNumber;
	char street[41];
	char postalCode[8];
	char city[41];
}; // Declaring Struct for Address and the members within

struct Numbers {
	char cell[11];
	char home[11];
	char business[11];
}; //Declaring Struct for Phone Numbers and the members within

struct Contact {
  struct Name name;
  struct Address address;
  struct Numbers numbers;
};

void getName(struct Name *name);
void getAddress(struct Address *address);
void getNumbers(struct Numbers *numbers);
void getContact(struct Contact *contact);
