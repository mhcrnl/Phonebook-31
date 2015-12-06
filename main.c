#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Start of global declarations
char input[1000]="No file";
int entry=0,saved=1;

typedef struct
{
   char  *first;
   char  *last;
   char  *ad;
   char *city;
   char *phone;
}db;
 db contact[10000];
char d[2]=",";
//End of global declarations
//Start of function prototypes
void logo ();
void menu ();
void load();
void query();
void add();
void delete_entry();
void modify();
void printer();
void save();
//End of function prototypes
int main(){
    system("cls");
    system ("color f8");
    logo();
    menu();
    return 0;
}
void logo(){
    time_t rawtime;
    struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
    printf("\n\t     _____  _                      ____              _    \n");
    printf(" \t    |  __ \\| |                    |  _ \\            | |   \n");
    printf(" \t    | |__) | |__   ___  _ __   ___| |_) | ___   ___ | | __\n");
    printf(" \t    |  ___/| '_ \\ / _ \\| '_ \\ / _ \\  _ < / _ \\ / _ \\| |/ /\n");
    printf(" \t    | |    | | | | (_) | | | |  __/ |_) | (_) | (_) |   <\n");
    printf(" \t    |_|    |_| |_|\\___/|_| |_|\\___|____/ \\___/ \\___/|_|\\_\\\n\n");
    printf("\t    Status: %s is loaded.\t\t\n",input);
    if(entry>0){
    printf("\t    %d contact(s) loaded",entry);
    }
    if(strcmpi(input,"No file")!=0 && saved==0){
        printf(" - UNSAVED");
    }
    else if (strcmpi(input,"No file")!=0 && saved==1){
        printf("\n\t    Last saved: %s",asctime (timeinfo));
    }
    printf("\n\n\n\n");

}

void menu(){
    char command[100];
    printf(" 1) LOAD \t- load a phone book file. \t\n 2) QUERY \t- search your loaded phone book. \t\n 3) ADD \t- add an entry to your phone book. \t\n 4) DELETE \t- delete an entry from your phone book. \t\n 5) MODIFY \t- modify an existing entry. \t\n 6) PRINT \t- print a sorted version of your phone book. \t\n 7) SAVE \t- save the changes you have done to your phone book.\t\n 8) EXIT \t- exit without saving.\t\n");
    printf("\n COMMAND: ");
    gets(command);
    while(strcmpi(command,"LOAD")!=0 &&strcmpi(command,"QUERY")!=0 &&strcmpi(command,"ADD")!=0 &&strcmpi(command,"DELETE")!=0 && strcmpi(command,"MODIFY")!=0 &&strcmpi(command,"PRINT")!=0 &&strcmpi(command,"SAVE")!=0 &&strcmpi(command,"EXIT")!=0){
        system ("color fc");
        printf("\n You have entered an incorrect command. Please re-enter your command.\n");
        printf("\n COMMAND: ");
        gets(command);
    }
    if(strcmpi(command,"LOAD")==0){
    load();
    }
    else if(strcmpi(command,"QUERY")==0){
    query();
    }
    else if(strcmpi(command,"ADD")==0){
    add();
    }
    else if(strcmpi(command,"DELETE")==0){
    delete_entry();
    }
    else if(strcmpi(command,"MODIFY")==0){
    modify();
    }
    else if(strcmpi(command,"PRINT")==0){
    printer();
    }
    else if(strcmpi(command,"SAVE")==0){
    save();
    }
    else if(strcmpi(command,"EXIT")==0){
    exit(0);
    }

}

void load(){
    system("cls");
    system("color f8");
    logo();
    FILE *fp;
    char back[100];
    printf("\n Load your phone book file:\n\n");
    printf(" Please enter the name of the file: ");
    gets(input);
    fp = fopen(input,"r+");
    while(fp==NULL){
        system ("color fc");
        printf("\n\n Error loading phone book file!\n");
        printf("\n Please enter the name of the file again: ");
        gets(input);
        fp = fopen(input,"r+");
    }
    system("cls");
    system("color f8");
    logo();
    char line [1000];
    const char *token;
    while ( fgets ( line, sizeof line, fp ) != NULL )
      {
    if(strcmpi(line,"\n")!=0){
        token = strtok(line, d);
        int col=1;
    while( token != NULL)
        {
        if(col==1){
            contact[entry].first=strdup(token);
            col++;
        }
        else if(col==2){
            contact[entry].last=strdup(token);
            col++;
        }
        else if(col==3){
            contact[entry].ad=strdup(token);
            col++;
        }
        else if(col==4){
            contact[entry].city=strdup(token);
            col++;
        }
        else if(col==5){
            contact[entry].phone=strdup(token);
            col++;
        }
        token = strtok(NULL, d);
        }
        entry++;
      }
      }
      fclose ( fp );
      system("cls");
      logo();
    printf("\n %d contacts from the file %s has been loaded successfully!\n",entry, input);
    printf("\n Use the command BACK to return to the main menu.\n\n COMMAND: ");
    gets(back);
    while(strcmpi(back,"BACK")!=0){
    printf("\n You have entered an incorrect command. Please re-enter your command.\n\n COMMAND: ");
    gets(back);
    }
    main();
    }
void query(){
system("cls");
system("color f8");
logo();
int i,c=0;
char term[100];
char back[100];
if(strcmpi(input,"No file")==0){
    puts(" Please load a file first.\n");
    printf("\n Use the command BACK to return to the main menu.\n\n COMMAND: ");
    gets(back);
while(strcmpi(back,"BACK")!=0){
    printf("\n You have entered an incorrect command. Please re-enter your command.\n\n COMMAND: ");
    gets(back);
    }
    main();
}
puts(" Please enter the last name to search your contacts:\n ");
printf(" ");
gets(term);
for(i=0;i<entry;i++){
    if(strcmpi(contact[i].last,term)==0){
    printf("\n\n Matching contact #%d:\n\n\n",c+1);
    printf(" First name: %s\n\n",contact[i].first);
    printf(" Last name: %s\n\n",contact[i].last);
    printf(" Address: %s\n\n",contact[i].ad);
    printf(" City: %s\n\n",contact[i].city);
    printf(" Phone number: %s\n\n",contact[i].phone);
    c++;
    }
}
    if(c==0){
        puts("\n No contacts matched your query!");
    }
    else{printf(" %d contact(s) matched your query!\n",c);}

    printf("\n Use the command AGAIN to search again, or BACK to return to the main menu.\n\n COMMAND: ");
    gets(back);
    if(strcmpi(back,"AGAIN")==0) query();
   while(strcmpi(back,"BACK")!=0){
    if(strcmpi(back,"AGAIN")==0) query();
    printf("\n You have entered an incorrect command. Please re-enter your command.\n\n COMMAND: ");
    gets(back);
    }
    main();
}
void add(){
    system("cls");
    logo();
    int n,i,j;
    char back[100],data[100];
if(strcmpi(input,"No file")==0){
    puts(" Please load a file first.\n");
    printf("\n Use the command BACK to return to the main menu.\n\n COMMAND: ");
    gets(back);
while(strcmpi(back,"BACK")!=0){
    printf("\n You have entered an incorrect command. Please re-enter your command.\n\n COMMAND: ");
    gets(back);
    }
    main();
}
    printf(" Please enter the number of contacts you would like to enter: ");
    scanf("%d",&n);
    getchar();
    for(i=1;i<=n;i++){
        for(j=0;j<80;j++){
            if(j==0){
                puts("\n");
            }
        printf("-");
        if(j==79){
                puts("\n");
            }
        }
        printf(" For new contact #%d, please enter:\n\n",i);
        printf(" First Name: ");
        gets(data);
        contact[entry].first=strdup(data);
        printf(" Last Name: ");
        gets(data);
        contact[entry].last=strdup(data);
        printf(" Address: ");
        gets(data);
        contact[entry].ad=strdup(data);
        printf(" City: ");
        gets(data);
        contact[entry].city=strdup(data);
        printf(" Phone: ");
        gets(data);
        contact[entry].phone=strdup(data);
        entry++;

    }
    printf("\n %d contacts have been added successfully!\n",i-1);
    printf("\n Use the command BACK to return to the main menu.\n\n COMMAND: ");
    gets(back);
    while(strcmpi(back,"BACK")!=0){
    printf("\n You have entered an incorrect command. Please re-enter your command.\n\n COMMAND: ");
    gets(back);
    }
    main();
   }
void delete_entry(){}
void modify(){}
void printer(){
    system("cls");
    system("color f8");
    logo();
    int i;
    char back[100];
if(strcmpi(input,"No file")==0){
    puts(" Please load a file first.\n");
    printf("\n Use the command BACK to return to the main menu.\n\n COMMAND: ");
    gets(back);
while(strcmpi(back,"BACK")!=0){
    printf("\n You have entered an incorrect command. Please re-enter your command.\n\n COMMAND: ");
    gets(back);
    }
    main();
}
    for(i=0;i<entry;i++){
    printf("\n\n Contact #%d:\n\n\n",i+1);
    printf(" First name: %s\n\n",contact[i].first);
    printf(" Last name: %s\n\n",contact[i].last);
    printf(" Address: %s\n\n",contact[i].ad);
    printf(" City: %s\n\n",contact[i].city);
    printf(" Phone number: %s\n\n",contact[i].phone);
    }
     printf("\n Use the command BACK to return to the main menu.\n\n COMMAND: ");
    gets(back);
while(strcmpi(back,"BACK")!=0){
    printf("\n You have entered an incorrect command. Please re-enter your command.\n\n COMMAND: ");
    gets(back);
    }
    main();

}
void save(){}
