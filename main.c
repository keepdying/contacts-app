#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#pragma warning(disable : 6031)

void sortDb(); // sort dB
void saveDb(); // save dB
void addEntry(); // add entry to dB
void editEntry(); // edit entry from dB
void deleteEntry(); // delete entry from dB
void listEntries(); // list entries of dB
void searchEntry(); //
void menuFunc(); // menu func

void menuFunc() {
	int choice = 0;
	printf("\n1- Add Entry\n");
	printf("2- Delete Entry\n");
	printf("3- Edit Entry\n");
	printf("4- List Entries\n");
	printf("5- Search Entry\n\n");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
		//addEntry();
	case 2:
		//deleteEntry();
	case 3:
		//editEntry();
	case 4:
		//listEntries();
	case 5:
		//searchEntry();
	default:
		menuFunc();
	}
}
void addEntry(unsigned int count) {
	entriesArray[count].id = count;
	printf("\nName: \n");
	scanf("%s", entriesArray[count].name);
	printf("\nMail: \n");
	scanf("%s", entriesArray[count].mail);
	printf("\nPhone: \n");
	scanf("%s", entriesArray[count].phone);
}
void listEntries(unsigned int count) {
	for (i = 1; i < count; i++) {

	}
}
struct entry // struct of dB
{
	unsigned int id;
	char name[50];
	char mail[50];
	char phone[20];
	time_t time;

};
struct entry entriesArray[999]; // max allowed entry
unsigned int id_count; // this equals to entriesArray[0].id


int main(int argc, char* argv[]) {
	FILE* f = fopen("database.db", "r+b");
	if (f == NULL) {
		FILE* f = fopen("database.db", "w+b");
	}
	fread(entriesArray, sizeof(struct entry), sizeof(entriesArray), f);
	id_count = entriesArray[0].id; // read user count

	if (id_count == NULL) {
		id_count = 0; // in case first run of program set id count to 0
	}

	menuFunc();
};
