#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1

typedef struct{
  char name[50];
  char address[50];
  char schoolName[50];
}data;
void menu(){
	printf("\nAplikasi Simulasi Menu\n");
	printf("1. create data\n");
	printf("2. list data\n");
	printf("3. find data\n");
	printf("4. delete data\n");
        printf("5. editing data\n");
	printf("========================\n");
	printf("Pilih Menu: ");
	printf("\n");
}
void findingdata(data[], int);
void displaydata(data[], int);
void deletedata(data[], int);
int createData(data[], int, int);
void editingdata(data[], int);


int main (int argc, char *argv[]){
  int p = 0;
  data Person[20]; int menuinput; /* int p = 0; */
  do {
    menu();
    // system("clear");
    scanf("%d", &menuinput);
    system("clear");
    getchar();
    printf("\n");
    // system("clear");
    switch (menuinput) {
      case 1:
        p += createData(Person, p, 5);
       break;
      case 2:
        displaydata(Person, p);
        break;
      case 3:
        findingdata(Person, p);
        break;
      case 4:
        deletedata(Person, p);        
        break;
      case 5:
        editingdata(Person, p);
        break;
    }
  } while(menuinput != 6);
  // menu();
  
  return 0;
}

int createData(data storePerson[], int mindata, int maxdata){
  static int i; data person; 
  if(mindata < maxdata){  
    printf("put name :");
    scanf(" %50[^\n]s", person.name);
    printf("put address : ");
    scanf(" %50[^\n]s", person.address);
    printf("put school name :"); 
    scanf(" %50[^\n]s", person.schoolName); 
    storePerson[mindata] = person;
    // free/* (person); */
    return 1;
  }else {
    printf("data full !\n");
    // free(person);
    return 0;
  }
}

void displaydata(data storePerson[], int data){
  FILE *file = fopen("data.txt", "w+");
  for (int i = 0; i < data; i++) {
    printf("[%d] name : %s \t\t\t address : %s \t\t\t school Name :%s\n",
        i + 1, storePerson[i].name,
        storePerson[i].address,
        storePerson[i].schoolName); 
    // me);
    fprintf(file, "nama : %s\n", storePerson[i].name);
    fprintf(file, "alamat : %s\n", storePerson[i].address);
    fprintf(file, "kampus : %s\n", storePerson[i].schoolName);
  }
  fclose(file);
}

void findingdata(data datastorage[], int data){
  int found = 0;
  char *str_tofind;
  printf("enter the name do you want :");
  scanf(" %50[^\n]s", str_tofind);
  for (int i = 0; i < data; i++) {
    if (strcmp(datastorage[i].name, str_tofind) == 0){
      found = 1;
      printf("string %s find in row %d\n", datastorage[i].name, i + 1);
      // found = 1;
    }
  }
}

void deletedata(data storedata[], int data){
  int id = 0;
  char *deletename; //find name to delete all data was it
  printf("enter the name you have to delete it :");
  scanf(" %50[^\n]s", deletename);

  for (int i = 0; i < data; i++) {
    if (strcmp(storedata[i].name, deletename) == 0) {
      strcpy(storedata[i].name, "\0");
      strcpy(storedata[i].address, "\0");
      strcpy(storedata[i].schoolName, "\0");
      i--;
      break;
    }else printf("cannot find the name\n");
    // storedata[i] = storedata[i + 1];
  }
  return;
}

void editingdata(data storagename[], int data){
  char *sourcename, *destname; int d =0;
  printf("enter name to editing :");
  scanf(" %50[^\n]s", sourcename);
  for (int i = d; i < data; i++) {
    if (strcmp(storagename[i].name, sourcename) == 0){
      printf("put your name for edit: "); 
      scanf(" %50[^\n]s", destname);
      strcpy(storagename[i].name, destname); 
      break;
    }else {
      puts("name invalid name not exist");
    }
  }
}

