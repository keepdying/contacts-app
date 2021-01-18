#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#pragma warning(disable : 6031)


void sortedListMenu();
void listEntriesMenu();
void readDb();
void updateDb(int i);
void sortDb(); // sort dB
void saveDb(int i); // save dB
void addEntry(); // add entry to dB
void editEntry(); // edit entry from dB
void deleteEntry(); // delete entry from dB
void listEntries(); // list entries of dB
void searchEntry();
void sortedList(); //
void allDbUpdate();
void menuFunc(); // menu func


struct entry // struct of dB
{
	unsigned int id;
	char name[50];
	char mail[50];
	char phone[20];
	time_t time;
};
struct entry entry1;
struct entry entriesArray[999];
struct entry sortedArray[999];

int timer;

int main(void) {
	readDb();
	printf("the number of people in your contacts: %d\n",timer);
	menuFunc();
};

void menuFunc() {

	int choice = 0;
	printf("\n1- Add Entry\n");
	printf("2- Delete Entry\n");
	printf("3- Edit Entry\n");
	printf("4- Time Sorted List Entries\n");
	printf("5- Alphabetic Sorted List Entries\n");
	printf("6- Search Entry\n\n");

	//choice = getchar()-'0';
	printf("Your choice: ");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
		addEntry();
		break;
	case 2:
		deleteEntry();
		break;
	case 3:
		editEntry();
		break;
	case 4:
		listEntriesMenu();
		break;
	case 5:
		sortedListMenu();
		break;
	case 6:
		searchEntry();
		break;
	default:
		menuFunc();
		break;
	}
}

void editEntry()
{
	int editChoice;
	int editId;
	listEntries();
	printf("Enter the ID of the person you want to edit: ");
	scanf("%d",&editId);

	
	printf("1- Name\n");
	printf("2- Mail\n");
	printf("3- Phone\n");
	
	printf("what do you want to edit: ");
	scanf("%d",&editChoice);
	if(editChoice == 1)
	{
	char name[50];
	//char name2[50] = "No name";
	printf(" New Name: ");
	getchar();
	gets(name);
	if(islower(name[0]))
		name[0] = toupper(name[0]);
	int i;
	for(i = 0;i<timer;i++){
		if(editId == entriesArray[i].id){
				if(strlen(name) == 0)
					printf("missing name\n");
				else{
					strcpy(entriesArray[i].name,name);
					printf("Changed name\n");
				}
					
		}
	}
	
		
	}
	else if(editChoice == 2){
	char mail[50];
	printf(" New Mail: ");
	getchar();
	gets(mail);
	int i;
	for(i = 0;i<timer;i++){
		if(editId == entriesArray[i].id){
			strcpy(entriesArray[i].mail,mail);
		}
	}
	printf("Changed mail\n");
	}
	else if(editChoice == 3){
	char phone[20];
	printf("New Phone: ");
	getchar();
	gets(phone);
	int i;
	for(i = 0;i<timer;i++){
		if(editId == entriesArray[i].id){
			strcpy(entriesArray[i].phone,phone);
		}
	}
	printf("changed phone\n");
	}
	
	allDbUpdate();
	readDb();
	menuFunc();
}

void deleteEntry(){
	int silinecekId;
	listEntries();
	printf("Enter the ID of the person you want to delete: ");
	scanf("%d",&silinecekId);
	int i,j,k,l;
	j = 0;
	l = 0;
	int silinecekPos;
	for(k = 0;l<timer;l++){
		if(silinecekId == entriesArray[l].id){
			silinecekPos = l;
		}
	}

	for(i = silinecekPos; i<timer;i++){
			entriesArray[i] = entriesArray[i+1];
	}
	timer--;

	for(k = 0;k<=timer;k++){
		updateDb(k);
	}
	allDbUpdate();
	readDb();
	menuFunc();
}

void saveDb(int i){
		FILE *f = fopen("database.txt", "a+");
		if (f == NULL) 
		{
			FILE *f = fopen("database.txt", "w+");
		}
		
		fwrite(&entriesArray[i], sizeof(struct entry), 1, f); 
		fclose(f);
}

void updateDb(int i){
	FILE *f = fopen("database.txt", "w+");
	fwrite(&entriesArray[i], sizeof(struct entry), 1, f);
	fclose(f);
}

void searchEntry() {
	char to_search[50];
	printf("name? (write n to skip):\n");
	getchar();
	gets(to_search);
	printf("\n");
	for (int i = 0; i < 999; i++) {
		if (strcmp(entriesArray[i].name, to_search) == 0) {
			printf("%d\n" ,entriesArray[i].id);
			printf("%s\n", entriesArray[i].name);
			printf("%s\n", entriesArray[i].phone);
			printf("%s\n", entriesArray[i].mail);
			}
		}
	menuFunc();
	}

void allDbUpdate(){
	FILE *f = fopen("database.txt", "w+");
	int i = 0;
	while(i<999){
		if(entriesArray[i].id != 0)
			fwrite(&entriesArray[i], sizeof(struct entry), 1, f);
		i++;
	}
	fclose(f);
}

void readDb()
{
		FILE *f = fopen("database.txt", "r");
		if (f == NULL) 
		{
			printf("There is no database. Add people to the directory for creation\n");
		}
		else
		{
			int a = 0;
			timer= 0;
		
			while(fread(&entry1, sizeof(struct entry), 1, f))
			{
		
				entriesArray[a].id = entry1.id;
				strcpy(entriesArray[a].name,entry1.name);
				strcpy(entriesArray[a].mail,entry1.mail);
				strcpy(entriesArray[a].phone,entry1.phone);
				entriesArray[a].time = entry1.time;

			
				sortedArray[a].id = entry1.id;
				strcpy(sortedArray[a].name,entry1.name);
				strcpy(sortedArray[a].mail,entry1.mail);
				strcpy(sortedArray[a].phone,entry1.phone);
				sortedArray[a].time = entry1.time;
			
				a++;
				if(entry1.id != 0){
					timer++;
				}
				
			}
			fclose(f);
		}
	
}

void addEntry() 
{
	printf("-----------Add New People---------------\n");
	unsigned int id;
	char name[50];
	char mail[50];
	char phone[20];
	time_t mytime;
	
	printf(" Name: ");
	getchar();
	gets(name);
	if(islower(name[0]))
		name[0] = toupper(name[0]);

	
	printf(" Mail: ");
	gets(mail);

	
	printf(" Phone: ");
	gets(phone);

	
	if(strlen(name) != 0 && (strlen(mail) != 0 || strlen(phone) !=0)){
		mytime = time(NULL);
		id = mytime;
		
		
		int kayitYeri;
		int i;
		for(i = 0; i < 999; i++){
			if(entriesArray[i].id == 0){
				kayitYeri = i;
				break;
			}
		}
			
			entriesArray[kayitYeri].id = id;
			strcpy(entriesArray[kayitYeri].name,name);
			strcpy(entriesArray[kayitYeri].mail,mail);
			strcpy(entriesArray[kayitYeri].phone,phone);
			entriesArray[kayitYeri].time = mytime;
		
		saveDb(kayitYeri);
		printf("Saved new people\n");
	}
	else{
		printf("Missing information entry\n");
	}
	readDb();
	menuFunc();
}

void sortedListMenu(){
	sortedList();
	if(timer == 0)
		printf("   No people   \n");
	
	menuFunc();
}

void sortedList(){
	int i,j,count;
   	char str[25][25],temp[25]; 
   	count = timer;
	
   	for(i=0;i<=count;i++)
      strcpy(str[i],entriesArray[i].name);
    int m;
    for(m = 0;m < timer;m++){
    	sortedArray[m] = entriesArray[m];
	}
   	for(i=0;i<=count;i++)
      for(j=i+1;j<=count;j++){
         if(strcmp(str[i],str[j])>0){
         	
         	struct entry temp2 = sortedArray[i];
         	sortedArray[i] = sortedArray[j];
         	sortedArray[j] = temp2;
         	
         }
      }
      
    int k;
	for(k=-1; k<count; k++){    
		sortedArray[k] = sortedArray[k + 1];
	}
		
   	for(i=0;i<count;i++){
		printf ("\n %d)  id = %d | name = %s | mail = %s | phone = %s | time = %s\n", i+1,sortedArray[i].id, 
        sortedArray[i].name, sortedArray[i].mail,sortedArray[i].phone,asctime(localtime(&sortedArray[i].time)));
		   
	}
}

void listEntriesMenu(){
	listEntries();
	if(timer == 0)
		printf("   No people   \n");
	menuFunc();
}

void listEntries(){
	FILE *f = fopen("database.txt", "rb");
	if (f == NULL) 
	{
		printf("Error, no database, add people for database\n");
	}
	int i = 1;
	while(fread(&entry1, sizeof(struct entry), 1, f)){
        printf ("\n %d)   id = %d | name = %s | mail = %s | phone = %s | time = %s\n", i,entry1.id, 
        entry1.name, entry1.mail,entry1.phone,asctime(localtime(&entry1.time)));
        i++;
	}
	fclose(f);
	
}






