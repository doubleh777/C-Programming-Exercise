#include<stdio.h>

struct member{
	int ID;
	char Name[100];
	char Adress[100];
	char Phone[30];
}typedef Member;

void printPersonalInformation(Member*);
void initID(Member*);
void addMember(Member*);
void dataInput(Member*);
void mainPage(Member *);
void printPersonalInformation(Member *);
void searchMember(Member *);
void errorPhoneNumber(Member *, int);
void editMember(Member*);
void editIDNumber(Member*, int, char*);
void editName(Member*, int, char*);
void editAdress(Member*, int, char*);
void editPhoneNumber(Member*, int, char*);
void editIDNumber_errorCase(Member*, int , char*);
void editPhoneNubmer_errorCase(Member*, int, char*, char*);
void deleteMmeber(Member*);
void searchWithID(Member*);
void searchWithName(Member*);
void saveMember(Member*);
void _Exit(Member*, Member*);
void realloction(Member*);
