#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sortDb(); // sort dB
void saveDb(); // save dB
void addEntry(); // add entry to dB
void deleteEntry(); // delete entry from dB
void listEntries(); // list entries of dB

struct entry // struct of dB
{
	unsigned int id;
	char name[50];
	char mail[50];
	char phone[20];
};

struct entry entriesArray[999];
char choice[2] = "0";

int main(void) {
    printf("\n 1- > Insert new Entry\n");
    printf("\n 2 -> Delete Entry\n");
    printf("\n 3 -> Display all Entry\n");
    printf("\n 4 -> Search Entry\n");
    printf("\n Q -> Exit the program\n");
    printf("\n Enter your choice <1->: ");
    scanf("%s", choice);
    
    if (choice == "1") {

    } 
    else if (choice == "2") {

    } 
    else if (choice == "3") {

    }
    else if (choice == "4") {

    }
    else if (choice == "Q") {
        return 0;
    }
    else {
        main();
    }
};
