#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#pragma warning(disable : 6031)


void readDb();
void sortDb(); // sort dB
void saveDb(int i); // save dB
void addEntry(); // add entry to dB
void editEntry(); // edit entry from dB
void deleteEntry(); // delete entry from dB
void listEntries(); // list entries of dB
void searchEntry();
void sortedList(); //
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
	printf("Rehberinizdeki kisi sayisi: %d\n",timer);
	menuFunc();
};

void menuFunc() {
	/*printf("id: %d\n",entriesArray[0].id);
	printf("name: %s\n",entriesArray[0].name);
	printf("mail: %s\n",entriesArray[0].mail);
	printf("phone: %s\n",entriesArray[0].phone);
	printf("time: %d\n",entriesArray[0].time);*/
	
	/*printf("id: %d\n",entriesArray[0].id);
	printf("id: %d\n",entriesArray[1].id);
	printf("id: %d\n",entriesArray[2].id);
	printf("id: %d\n",entriesArray[3].id);
	printf("id: %d\n",entriesArray[4].id);*/
	

	
	
	int choice = 0;
	printf("\n1- Add Entry\n");
	printf("2- Delete Entry\n");
	printf("3- Edit Entry\n");
	printf("4- List Entries\n");
	printf("5- Sorted List Entries\n\n");

	//choice = getchar()-'0';
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
		addEntry();
		break;
	case 2:
		//deleteEntry();
	case 3:
		//editEntry();
	case 4:
		listEntries();
		break;
	case 5:
		sortedList();
		break;
		//searchEntry();
	default:
		menuFunc();
		break;
	}
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

void readDb()
{
		FILE *f = fopen("database.txt", "r");
		if (f == NULL) 
		{
			printf("Database yok. Olusturulmasi icin rehbere kisi ekleyin.\n");
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
				/*entriesArray[a].name = entry1.name;
				entriesArray[a].mail = entry1.mail;
				entriesArray[a].phone = entry1.phone;*/
			
				sortedArray[a].id = entry1.id;
				strcpy(sortedArray[a].name,entry1.name);
				strcpy(sortedArray[a].mail,entry1.mail);
				strcpy(sortedArray[a].phone,entry1.phone);
				sortedArray[a].time = entry1.time;
			
				a++;
				timer++;
			}
			fclose(f);
		}
		
		
		
}

void addEntry() 
{
	printf("Kisi kaydetme  menusu\n");
	unsigned int id;
	char name[50];
	char mail[50];
	char phone[20];
	time_t mytime;
	
	printf("isminizi giriniz: ");
	getchar();
	gets(name);
	if(islower(name[0]))
		name[0] = toupper(name[0]);
	//scanf("%s",name);
	
	printf("mail adresi giriniz: ");
	gets(mail);
	//scanf("%s",mail);
	
	printf("telefon giriniz: ");
	gets(phone);
	//scanf("%s",phone);
	
	
	
	//&& (mail != NULL || phone != NULL) && mytime != NULL
	
	if(strlen(name) != 0 && (strlen(mail) != 0 || strlen(phone) !=0)){
		mytime = time(NULL);
		id = mytime;
		
		//printf("%d",id);
		//printf("%s",name);
		//printf("%s",mail);
		//printf("%s",phone);
		//printf("%d",mytime);
		
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
			//entriesArray[kayitYeri].name = name;
			//entriesArray[kayitYeri].mail = mail;
			//entriesArray[kayitYeri].phone = phone;
			entriesArray[kayitYeri].time = mytime;
		
		/*for(i = 0; i<= kayitYeri; i++){
			printf("id: %d\n",entriesArray[i].id);
			printf("name: %s\n",entriesArray[i].name);
			printf("mail: %s\n",entriesArray[i].mail);
			printf("phone: %s\n",entriesArray[i].phone);
			printf("time: %d\n",entriesArray[i].time);
		}*/
		
		saveDb(kayitYeri);
		printf("islem tamam kayit yeri: %d\n", kayitYeri);
	}
	else{
		printf("hata var");
	}
	readDb();
	menuFunc();
	
	/*
	
	printf("id: %d\n",entriesArray[1].id);
	printf("name: %s\n",entriesArray[1].name);
	printf("mail: %s\n",entriesArray[1].mail);
	printf("phone: %s\n",entriesArray[1].phone);
	printf("time: %d\n",entriesArray[1].time);*/
}

void sortedList(){
	int i,j,count;
   	char str[25][25],temp[25],temp2[50],temp3[20],temp5[50]; 
   	count = timer;
	
   	for(i=0;i<=count;i++)
      strcpy(str[i],entriesArray[i].name);
   	for(i=0;i<=count;i++)
      for(j=i+1;j<=count;j++){
         if(strcmp(str[i],str[j])>0){
         	
         	struct entry tempk = sortedArray[i];
         	sortedArray[i] = sortedArray[j];
         	sortedArray[j] = tempk;
         	
         	/*int temp1 = sortedArray[i].id;
         	sortedArray[i].id = sortedArray[j].id;
         	sortedArray[j].id = temp1;
			
			strcpy(temp2,sortedArray[i].mail);
            strcpy(sortedArray[i].mail,sortedArray[j].mail);
            strcpy(sortedArray[j].mail,temp2);
			
			strcpy(temp3,sortedArray[i].phone);
            strcpy(sortedArray[i].phone,sortedArray[j].phone);
            strcpy(sortedArray[j].phone,temp3);
            
         	time_t temp4 = sortedArray[i].time;
         	sortedArray[i].time = sortedArray[j].time;
         	sortedArray[j].time = temp4;
         	
         	strcpy(temp5,sortedArray[i].name);
            strcpy(sortedArray[i].name,sortedArray[j].name);
            strcpy(sortedArray[j].name,temp5);*/
         	
            strcpy(temp,str[i]);
            strcpy(str[i],str[j]);
            strcpy(str[j],temp);
         }
      }
      
      int k;
		for(k=-1; k<count; k++){
		    
			sortedArray[k] = sortedArray[k + 1];
		    
		}
		
   	for(i=0;i<count;i++){
   		
		printf ("id = %d | name = %s | mail = %s | phone = %s | time = %s\n", sortedArray[i].id, 
        sortedArray[i].name, sortedArray[i].mail,sortedArray[i].phone,asctime(localtime(&sortedArray[i].time)));
		   
		//puts(str[i]);
   		/*printf("%d\n",sortedArray[i].id);
   		printf("%s\n",sortedArray[i].mail);*/
	   }
	menuFunc();
      
}

void listEntries(){
	FILE *f = fopen("database.txt", "rb");
	if (f == NULL) 
	{
		printf("Error");
	}
	
	
	
	
	while(fread(&entry1, sizeof(struct entry), 1, f)){
        printf ("id = %d | name = %s | mail = %s | phone = %s | time = %s\n", entry1.id, 
        entry1.name, entry1.mail,entry1.phone,asctime(localtime(&entry1.time)));
	}
	fclose(f);
	menuFunc();
		
}



// ------------------------------------Zaman hakkýnda kod parçacýðý--------------------------
//time_t time_1970;
//struct tm* time_detay;
//
//time_1970 = time(NULL);
//
//
//
//time_detay = localtime(&time_1970);
//printf("Yerel zaman: %s", asctime(time_detay));
//
//printf("1 Ocak 1970'den bugüne geçen zaman: %ld saniye\n", time_1970);
//--------------------------------------------------------------------------------------------




