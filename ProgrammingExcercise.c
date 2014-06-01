//1.FileInput을 통해서 데이터파일에 있는 회원정보를 읽어와 구조체 배열에 저장한다.
//2.구현사항 : 회원보기, 회원등록, 회원수정, 회원삭제, 회원검색, 저장하기, 종료하기(종료전에 저장여부 물어보기)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
#include "MyFunction.h"

#pragma warning(disable : 4996)

int MAX = 255;
int changeOrNot = 0; // 종료시에 변경 여부를 알기 위함
int start;  // 마지막 사람의 학번 + 1 (회원 등록시 ID 넘버의 시작점) 

void _Exit(Member* list, Member* listBackUp)
{
	FILE* fp;
	int i, j;
	char buf[10];
	char input;
	fp = fopen("data.txt", "wt"); // data.txt가 없으면 실행되지 않으므로 예외처리 할 필요없음.
	system("cls");
	printf("================================================================================");
	printf("                        회원 정보 관리 프로그램 종료 메뉴\n");
	printf("================================================================================\n");
	if (changeOrNot != 0) // 변경된 정보가 있는 경우
	{
		printf("\n\n\n\n\n     변경된 정보가 있습니다. 저장 후 종료하시겠습니까? ( Y / N )");
		while (1)
		{
			input = _getch();
			if (input == 'Y' || input == 'y' || input == 'ㅛ')
			{
				fprintf(fp, "%s\t%s\t%s\t%s\n","회원 아이디", "회원이름", "회원주소", "핸드폰 번호");

				for (i = 1; i < MAX; i++)
				{
					if (list[i].ID == -1)
						break;
					fprintf(fp, "%d\t%s\t%s\t%s\n", list[i].ID, list[i].Name, list[i].Adress, list[i].Phone);
				}
				fclose(fp);
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                       ");
				return;
			}
			else if (input == 'N' || input == 'n' || input == 'ㅜ')
			{
				fprintf(fp, "%s\t%s\t%s\t%s\n", "회원 아이디", "회원이름", "회원주소", "핸드폰 번호");

				for (i = 1; i < MAX; i++)
				{
					if (listBackUp[i].ID == -1)
						break;
					fprintf(fp, "%d\t%s\t%s\t%s\n", listBackUp[i].ID, listBackUp[i].Name, listBackUp[i].Adress, listBackUp[i].Phone);
				}
				fclose(fp);
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                       ");
				return;
			}
			else printf("\a");
		}
	}
	else   // 변경된 정보가 없는 경우
	{
		fprintf(fp, "%s\t%s\t%s\t%s\n", "회원 아이디", "회원이름", "회원주소", "핸드폰 번호");
		for (i = 1; i < MAX; i++)
		{
			if (list[i].ID == -1)
				break;
			fprintf(fp, "%d\t%s\t%s\t%s\n", list[i].ID, list[i].Name, list[i].Adress, list[i].Phone);
		}
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                       ");
		fclose(fp);
		return;
	}
}

void saveMember(Member *list)
{
	FILE *fp;
	int i, j;
	char input;
	char buf[10];
	fp = fopen("data.txt", "wt"); // data.txt가 없으면 실행되지 않으므로 예외처리 할 필요없음.

	system("cls");
	printf("================================================================================");
	printf("                              회원 정보 저장 메뉴\n");
	printf("================================================================================\n");
	printf("\n\n\n\n\n     변경된 정보를 모두 저장하시겠습니까? ( Y / N )");
	while (1)
	{
		input = _getch();
		if (input == 'Y' || input == 'y' || input == 'ㅛ')
			break;
		else if (input == 'N' || input == 'n' || input == 'ㅜ')
		{
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                         회원정보 저장을 취소하셨습니다.");
			getch();
			return;
		}
		else printf("\a");
	}
	fprintf(fp,"%s\t%s\t%s\t%s\n","회원 아이디", "회원이름", "회원주소", "핸드폰 번호");
	
	for (i = 1; i < MAX; i++)
	{
		if (list[i].ID == -1)
			break;
		fprintf(fp,"%d\t%s\t%s\t%s\n",list[i].ID, list[i].Name, list[i].Adress, list[i].Phone);
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                         회원정보 저장을 완료하였습니다.");
	_getch();
	fclose(fp);
	return;
}
void searchWithName(Member * list)
{
	int i, j;
	int count=0;
	char buf[10];
	char input;
	system("cls");
	printf("================================================================================");
	printf("                              회원 정보 검색 메뉴\n");
	printf("================================================================================\n");
	printf("\n\n\n\n\n     검색 방법 선택 :   1. ID Number로 검색     2. 이름으로 검색\n");
	printf("\n     검색할 회원 이름 : ");
	gets(buf);
	printf("\n");
	for (i = 0; i < MAX; i++)
	{
		if (strcmp(list[i].Name, buf) == 0)
		{
			printf("        %d", list[i].ID);
			printf("       %-6s", list[i].Name);
			printf("      %-23s", list[i].Adress);
			printf("    %s\n", list[i].Phone);
			count++; // if문을 몇 번 통과했는지 체크
		}
	}
	if (count == 0)
	{
		printf("\n\n\n\n\n\n\n\n\n\n                           error : 검색된 회원이 없습니다.\n");
		printf("                     메인페이지로 이동 ( H )   다시 검색 ( S )");
		while (1)
		{
			input = _getch();
			if (input == 'H' || input == 'h' || input == 'ㅗ')
				return;
			else if (input == 'S' || input == 's' || input == 'ㄴ')
			{
				searchMember(list);
				break;
			}
			else printf("\a");
		}
	}
	else
	{
		for (j = 0; j < 11 - count; j++)
			printf("\n");

		printf("                    메인페이지로 이동 ( H )   다시 검색 ( S )");
		while (1)
		{
			input = _getch();
			if (input == 'H' || input == 'h' || input == 'ㅗ')
				return;
			else if (input == 'S' || input == 's' || input == 'ㄴ')
			{
				searchMember(list);
				break;
			}
			else printf("\a");
		}
	}
	return;
}

void searchWithID(Member* list)
{
	int i, j;
	int count = 0;
	char buf[10];
	char input;
	system("cls");
	printf("================================================================================");
	printf("                              회원 정보 검색 메뉴\n");
	printf("================================================================================\n");
	printf("\n\n\n\n\n     검색 방법 선택 :   1. ID Number로 검색     2. 이름으로 검색\n");

	printf("\n     검색할 회원 ID Number : ");
	gets(buf);
	printf("\n");
	for (i = 0; i < MAX; i++)
	{
		if (list[i].ID == atoi(buf) && atoi(buf) != 0)
		{
			printf("        %d", list[i].ID);
			printf("       %-6s", list[i].Name);
			printf("      %-23s", list[i].Adress);
			printf("    %s\n", list[i].Phone);
			count++; // if문을 몇 번 통과했는지 체크
		}
	}
	if (count == 0)
	{
		printf("\n\n\n\n\n\n\n\n\n\n                           error : 검색된 회원이 없습니다.\n");
		printf("                     메인페이지로 이동 ( H )   다시 검색 ( S )");
		while (1)
		{
			input = _getch();
			if (input == 'H' || input == 'h' || input == 'ㅗ')
				return;
			else if (input == 'S' || input == 's' || input == 'ㄴ')
			{
				searchMember(list);
				break;
			}
			else printf("\a");
		}
	}
	else
	{
		for (j = 0; j < 11 - count; j++)
			printf("\n");

		printf("                    메인페이지로 이동 ( H )   다시 검색 ( S )");
		while (1)
		{
			input = _getch();
			if (input == 'H' || input == 'h' || input == 'ㅗ')
				return;
			else if (input == 'S' || input == 's' || input == 'ㄴ')
			{
				searchMember(list);
				break;
			}
			else printf("\a");
		}
	}
	return;

}
void searchMember(Member* list)
{
	char buf[30];
	int i;
	char input;
	system("cls");
	printf("================================================================================");
	printf("                              회원 정보 검색 메뉴\n");
	printf("================================================================================\n");
	printf("\n\n\n\n\n     검색 방법 선택 :   1. ID Number로 검색     2. 이름으로 검색\n");
	while (1)
	{
		input = _getch();
		if (input == '1')
		{
			searchWithID(list, input);
			break;
		}
		else if (input == '2')
		{
			searchWithName(list);
			break;
		}
		else printf("\a");
	}
	return;
}
void deleteMember(Member* list)
{
	char buf[10];
	int i, j;
	char input;
	system("cls");
	printf("================================================================================");
	printf("                              회원 정보 삭제 메뉴\n");
	printf("================================================================================\n");
	printf("\n\n\n\n\n     삭제할 회원의 ID Number 입력 : ");
	gets(buf);
	for (i = 0; i < MAX; i++) // 입력한 ID Number를 가진 구조체 찾기
	{
		if (list[i].ID == atoi(buf) && atoi(buf) != 0)// atoi함수에 문자가 들어가면 0을 출력하기 때문
			break;
	}
	if (i == MAX)
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n        메인페이지로 이동 ( H )      error : 일치하는 회원이 없습니다.");
		input = _getch();
		if (input == 'h' || input == 'H' || input == 'ㅗ')
			return;
		else deleteMember(list); return;
	}

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n                       정말로 삭제하시겠습니까? ( Y / N )\n");
	
	
	while (1)
	{
		input = _getch();
		if (input == 'y' || input == 'Y' || input == 'ㅛ')
		{
			for (; i < MAX; i++)
			{
				list[i] = list[i+1];
			}

			printf("                  입력하신 회원정보의 삭제가 완료되었습니다.");
			changeOrNot++;
			_getch();
			return;
		}
		else if (input == 'n' || input == 'N' || input == 'ㅜ')
		{
			printf("                         회원정보 삭제가 취소되었습니다.");
			_getch();
			return;
		}
		else printf("\a");
	}
}

void editPhoneNumber_errorCase(Member* list, int i, char* arr, char*buf)
{
	int j;
	system("cls");
	printf("================================================================================");
	printf("                              회원 정보 수정 메뉴\n");
	printf("================================================================================\n");
	printf("\n\n\n\n\n     수정할 회원의 ID Number 입력 : ");
	printf("%s\n", arr);
	printf("\n");
	printf("     수정 항목 선택 : 1. ID Number, 2. Name, 3. Adress, 4. PhoneNumber\n\n");
	printf("     변경할 Phone Number : ");
	gets(buf);
	for (j = 0; j < MAX; j++)
	{
		if (strcmp(list[j].Phone, buf) == 0)
		{
			printf("\n\n\n\n\n\n\n\n\n\n                       error : 이미 등록된 전화번호입니다.");
			_getch();
			editPhoneNumber_errorCase(list, i, arr, buf);
			return;
		}
	}
	strcpy(list[i].Phone, buf);
	printf("\n\n\n\n\n\n\n\n\n\n                                               수정이 완료되었습니다.");
	changeOrNot++;
	_getch();
	return;
}
void editPhoneNumber(Member* list, int i, char* arr)
{
	int j;
	char buf[30];
	system("cls");
	printf("================================================================================");
	printf("                              회원 정보 수정 메뉴\n");
	printf("================================================================================\n");
	printf("\n\n\n\n\n     수정할 회원의 ID Number 입력 : ");
	printf("%s\n", arr);
	printf("\n");
	printf("     수정 항목 선택 : 1. ID Number, 2. Name, 3. Adress, 4. PhoneNumber\n\n");
	printf("     변경할 Phone Number : ");
	gets(buf);
	for (j = 0; j < MAX; j++)
	{
		if (strcmp(list[j].Phone, buf) == 0)
		{
			printf("\n\n\n\n\n\n\n\n\n\n                       error : 이미 등록된 전화번호입니다.");
			_getch();
			editPhoneNumber_errorCase(list, i, arr, buf);
			return;
		}
	}
	strcpy(list[i].Phone, buf);
	printf("\n\n\n\n\n\n\n\n\n\n                                               수정이 완료되었습니다.");
	changeOrNot++;
	_getch();
	return;
	
}

void editName(Member* list, int i, char* arr)
{
	system("cls");
	printf("================================================================================");
	printf("                              회원 정보 수정 메뉴\n");
	printf("================================================================================\n");
	printf("\n\n\n\n\n     수정할 회원의 ID Number 입력 : ");
	printf("%s\n", arr);
	printf("\n");
	printf("     수정 항목 선택 : 1. ID Number, 2. Name, 3. Adress, 4. PhoneNumber\n\n");
	printf("     변경할 Name : ");
	gets(list[i].Name);
	printf("\n\n\n\n\n\n\n\n\n\n                                               수정이 완료되었습니다.");
	changeOrNot++;
	_getch();
	return;
}

void editAdress(Member* list, int i, char* arr)
{
	system("cls");
	printf("================================================================================");
	printf("                              회원 정보 수정 메뉴\n");
	printf("================================================================================\n");
	printf("\n\n\n\n\n     수정할 회원의 ID Number 입력 : ");
	printf("%s\n", arr);
	printf("\n");
	printf("     수정 항목 선택 : 1. ID Number, 2. Name, 3. Adress, 4. PhoneNumber\n\n");
	printf("     변경할 Aderess : ");
	gets(list[i].Adress);
	printf("\n\n\n\n\n\n\n\n\n\n                                               수정이 완료되었습니다.");
	changeOrNot++;
	_getch();
	return;

}
void editIDNumber_errorCase(Member* list, int i, char* arr) // ID Number가 같아서 재입력 받는 Case
{
	int j;
	char buf[10];
	system("cls");
	printf("================================================================================");
	printf("                              회원 정보 수정 메뉴\n");
	printf("================================================================================\n");
	printf("\n\n\n\n\n     수정할 회원의 ID Number 입력 : ");
	printf("%s\n", arr);
	printf("\n");
	printf("     수정 항목 선택 : 1. ID Number, 2. Name, 3. Adress, 4. PhoneNumber\n\n");
	printf("     변경할 ID Number : ");
	gets(buf);
	for (j = 0; j<MAX; j++)
	{
		if (list[j].ID == atoi(buf) && atoi(buf) != 0)
		{
			printf("\n\n\n\n\n\n\n\n\n\n                    error : 이미 등록된 ID Number입니다.");
			_getch();
			editIDNumber_errorCase(list, i, arr);
			break;
		}
	}
	return;
}
void editIDNumber(Member* list, int i, char* arr)
{
	int j;
	char buf[10];
	system("cls");
	printf("================================================================================");
	printf("                              회원 정보 수정 메뉴\n");
	printf("================================================================================\n");
	printf("\n\n\n\n\n     수정할 회원의 ID Number 입력 : ");
	printf("%s\n", arr);
	printf("\n");
	printf("     수정 항목 선택 : 1. ID Number, 2. Name, 3. Adress, 4. PhoneNumber\n\n");
	printf("     변경할 ID Number : ");
	gets(buf);
	for (j = 0; j<MAX ; j++)
	{
		if (list[j].ID == atoi(buf) && atoi(buf) != 0)
		{
			printf("\n\n\n\n\n\n\n\n\n\n                    error : 이미 등록된 ID Number입니다.");
			_getch();
			editIDNumber_errorCase(list, i, arr);
			break;
		}

	}

	list[i].ID = atoi(buf);
	printf("\n\n\n\n\n\n\n\n\n\n                                               수정이 완료되었습니다.");
	changeOrNot++;
	_getch();
	return;
}

void editMember(Member* list)
{
	char input;
	char buf[10];
	int i;
	system("cls");
	printf("================================================================================");
	printf("                              회원 정보 수정 메뉴\n");
	printf("================================================================================\n");
	printf("\n\n\n\n\n     수정할 회원의 ID Number 입력 : ");
	gets(buf);
	for (i = 0; i < MAX ; i++)
	{
		if (list[i].ID == atoi(buf) && atoi(buf) != 0)// atoi함수에 문자가 들어가면 0을 출력하기 때문
			break;
	}
	if (i == MAX)
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n                        error : 일치하는 회원이 없습니다.");
		_getch();
		return;
	}

	printf("\n");
	
	printf("     수정 항목 선택 : 1. ID Number, 2. Name, 3. Adress, 4. PhoneNumber\n\n");

	while (1)
	{
		input = _getch();
		if (input > '0' && input < '5')
		{
			switch (input)
			{
			case '1': editIDNumber(list, i, buf);
				break;
			case '2': editName(list, i, buf);
				break;
			case '3': editAdress(list, i, buf);
				break;
			case '4': editPhoneNumber(list, i, buf);
				break; 
			}
			break;
		}
		else printf("\a");
	}

	return;
}

void errorPhoneNumber(Member* list, int i)
{
	int j;
	system("cls");
	printf("================================================================================");
	printf("                              신규 회원 등록 메뉴\n");
	printf("================================================================================\n");
	printf("              이미 등록되어있는 전화번호입니다. 다시 입력해 주십시오.\n\n\n\n");
	printf("        ID Number : ");
	printf("%d\n", list[i].ID);
	printf("             Name : ");
	printf("%s\n", list[i].Name);
	printf("           Adress : ");
	printf("%s\n", list[i].Adress);
	printf("     Phone Number : ");

	int boolean = 1;

	while (1)
	{
		gets(list[i].Phone);

		for (int k = 0; k < strlen(list[i].Phone); k++)
		{
			if ((list[i].Phone[k] >= '0' && list[i].Phone[k] <= '9') || list[i].Phone[k] == '-')
			{
				boolean = 1;
				continue;
			}
			else
			{
				system("cls");
				printf("================================================================================");
				printf("                              신규 회원 등록 메뉴\n");
				printf("================================================================================\n\n\n\n\n");
				printf("        ID Number : ");
				printf("%d\n", list[i].ID);
				printf("             Name : ");
				printf("%s\n", list[i].Name);
				printf("           Adress : ");
				printf("%s\n", list[i].Adress);
				printf("     Phone Number : ");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n                  옳바른 전화번호가 아닙니다. 다시 입력해주십시오.");
				_getch();

				system("cls");
				printf("================================================================================");
				printf("                              신규 회원 등록 메뉴\n");
				printf("================================================================================\n\n\n\n\n");
				printf("        ID Number : ");
				printf("%d\n", list[i].ID);
				printf("             Name : ");
				printf("%s\n", list[i].Name);
				printf("           Adress : ");
				printf("%s\n", list[i].Adress);
				printf("     Phone Number : ");

				boolean = 0;
				break;
			}
		}

		if (boolean == 0) continue;
		else break;
	}
	/*
	for (j = 0; j < i; j++)
	{
		if (strcmp(list[j].Phone, list[i].Phone) == 0)  // 휴대폰 번호가 같으면 계속 반복
			errorPhoneNumber(list, i);
	}*/
	for (j = 0; j < i; j++)
	{
		if (strcmp(list[j].Phone, list[i].Phone) == 0){
			errorPhoneNumber(list, i);  // 휴대폰 번호가 같으면 계속 반복
		}
	}
	return;
}

void reallocation(Member * list)
{
	if (list[MAX - 1].ID != -1)
	{
		MAX *= 2;
		list = (Member*)realloc(list, sizeof(Member)*MAX);
	}
	for (int i = MAX / 2; i < 2 * MAX; i++)
	{
		list[i].ID = -1;
	}
}

void addMember(Member* list)
{
	int i, j;
	char buf[10];
	char input;
	
	reallocation(list);

	system("cls");
	printf("================================================================================");
	printf("                              신규 회원 등록 메뉴\n");
	printf("================================================================================\n\n\n\n\n");
	
	for (i = 0; i < MAX; i++) // 회원등록 안되어있는 구조체 찾기
	{
		if (list[i].ID == -1)
			break;  // 이때의 i값은 회원등록이 되어있지 않은 가장 앞선 구조체 인덱스
	}

	printf("        ID Number : ");
	printf("%d\n", start++);
	//gets(buf);
	//
	//	for (j = 0; j < i; j++) //i 이전까지 같은 ID가 있는지 체크
	//	{
	//		if (atoi(buf) == list[j].ID && atoi(buf) != 0)// atoi()함수에 문자가 들어오면 0을 반환하기 때문에 추가한 조건 
	//		{
	//			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	//			printf("      이미 등록된 회원입니다. 회원 검색 항목에서 등록 정보를 확인하세요.\n");
	//			printf("    메인페이지로 이동 ( H )  회원 검색페이지로 이동 ( S )   재입력 ( 아무키 )");
	//			input = _getch();
	//			if (input == 'H' || input == 'h' || input == 'ㅗ')
	//				return;
	//			else if (input == 'S' || input == 's' || input == 'ㄴ')
	//			{
	//				searchMember(list);
	//				return;
	//			}
	//			else
	//			{
	//				addMember(list);
	//				return;
	//			}
	//		}
	//	}
	//	list[i].ID = atoi(buf);  // 문자열로 입력받아 정수형으로 변환하여 저장

		list[i].ID = start;
		printf("             Name : ");
		gets(list[i].Name);
		printf("           Adress : ");
		gets(list[i].Adress);
		printf("     Phone Number : ");

		int boolean = 1;

		while (1)
		{
			gets(list[i].Phone);
			
			for (int k = 0; k < strlen(list[i].Phone); k++)
			{
				if ((list[i].Phone[k] >= '0' && list[i].Phone[k] <= '9') || list[i].Phone[k] == '-')
				{
					boolean = 1;
					continue;
				}
				else
				{
					printf("\n\n\n\n\n\n\n\n\n\n\n\n                옳바른 전화번호가 아닙니다. 다시 입력해주십시오.");
					_getch();

					system("cls");
					printf("================================================================================");
					printf("                              신규 회원 등록 메뉴\n");
					printf("================================================================================\n\n\n\n\n");
					printf("        ID Number : ");
					printf("%d\n", list[i].ID);
					printf("             Name : ");
					printf("%s\n", list[i].Name);
					printf("           Adress : ");
					printf("%s\n", list[i].Adress);
					printf("     Phone Number : ");

					boolean = 0;
					break;
				}		
			}
			if (boolean == 0) continue;
			else break;

		}

		if (strlen(list[i].Phone) != 0){   // 번호가 없는 사람도 있을 수 있으므로 번호 없는 사람들이 중복으로 처리 되지 않도록 예외처리
			for (j = 0; j < i; j++)
			{
				if (strcmp(list[j].Phone, list[i].Phone) == 0)
				{
					errorPhoneNumber(list, i);  // 휴대폰 번호가 같으면 계속 반복
					//errorPhoneNumber(list, i);
					system("cls");
					printf("================================================================================");
					printf("                              신규 회원 등록 메뉴\n");
					printf("================================================================================\n");
					printf("\n\n\n\n");
					printf("        ID Number : ");
					printf("%d\n", list[i].ID);
					printf("             Name : ");
					printf("%s\n", list[i].Name);
					printf("           Adress : ");
					printf("%s\n", list[i].Adress);
					printf("     Phone Number : ");
					printf("%s\n", list[i].Phone);
					break;
				}
			}
		}
		changeOrNot++;
		printf("\n\n\n\n\n\n\n\n\n\n\n\n      정상적으로 등록이 완료되었습니다.");
		printf("      메인페이지로 이동( H )");

		while (1)
		{
			input = _getch();
			if (input == 'H' || input == 'h' || input == 'ㅗ')
				return;
			else printf("\a");
		}
		
}

void dataInput(Member *list)
{
	int i;
	int j = 0, k = 0;
	char buf[100];
	char token[100];
	FILE *fp;
	
	if ((fp = fopen("data.txt", "rt")) == NULL)  //  파일 읽기 스트림 생성과 예외처리
	{
		fprintf(stderr, "No data");
		return -1;

	}
	while (fgets(buf, MAX, fp)) // 한 줄씩 읽어오기
	{	//ID
		for (i = 0;; i++)
		{
			if (buf[i] == '\t')  // '\t'나올때 까지
				break;
			token[i] = buf[i];  // token에 buf복사
		}
		token[i] = '\0'; // token에 ID복사한 후 끝에 NULL문자 삽입
		list[j].ID = atoi(token); // Member형 구조체 배열 list의 list[0] 구조체에 정수로 바꾼 ID값을 저장
		i++;


		start = list[j].ID + 1;  // 회원 등록시 ID넘버 시작점
		//Name
		for (;; i++)
		{
			if (buf[i] == '\t') // '\t'나올때 까지
				break;

			list[j].Name[k] = buf[i]; // 구조체의 Name배열에 복사
			k++;
		}
		list[j].Name[k] = '\0'; //NULL값 삽입
		i++;
		k = 0;
		//Adress
		for (;; i++)
		{
			if (buf[i] == '\t') //'\t'나올때 까지
				break;

			list[j].Adress[k] = buf[i]; // 구조체의 Adress배열에 복사
			k++;
		}
		list[j].Adress[k] = '\0';
		i++;
		k = 0;
		//Phone Number
		for (;; i++)
		{
			if (buf[i] == '\n')
				break;
			list[j].Phone[k] = buf[i];
			k++;
		}
		list[j].Phone[k] = '\0';

		j++; //다음 구조체(다음 사람의 정보)로 넘어감
		k = 0;
	}

	fclose(fp);
	return;
}

void mainPage(Member *list)
{
	char input;

	
	while (1)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("               ================================================\n");
		printf("                                 1.회원보기\n");
		printf("                                 2.회원등록\n");
		printf("                                 3.회원수정\n");
		printf("                                 4.회원삭제\n");
		printf("                                 5.회원검색\n");
		printf("                                 6.변경사항 저장\n");
		printf("                                 7.종료\n");
		printf("               ================================================\n");
		input = _getch();
		if (48 < input && 56 > input) // 문자'1'의 아스키코드는 49
		{
			switch (input)
			{
			case 49:
				printPersonalInformation(list);
				break;
			case 50:
				addMember(list);
				break;
			case 51:
				editMember(list);
				break;
			case 52:
				deleteMember(list);
				break;
			case 53:
				searchMember(list);
				break;
			case 54:;
				saveMember(list);
				break;
			case 55:;
				return;
			}
		}
		else printf("\a"); // 1~7 이외의 값 입력시 beep음 출력
	}
	
	return;
}

void printPersonalInformation(Member *list)
{
	int i, j;
	char input;

	for (j = 0;;)
	{
		system("cls");
		printf("================================================================================");
		printf("      %s       %s               %s             %s\n", "ID Number", "Name", "Adress", "Phone Number");
		printf("================================================================================");

		for (i = 21*(j)+1; i < 21*(j+1)+1; i++)
		{
			if (list[i + 1].ID == -1)
			{
				printf("        %d", list[i].ID);
				printf("       %-6s", list[i].Name);
				printf("      %-23s", list[i].Adress);
				printf("    %s\n", list[i].Phone);
				for (int k = 0; k < 20 - i%21+1; k++) // 빈칸 newline처리
					printf("\n");
				break;
			}
			else
			{
				printf("        %d", list[i].ID);
				printf("       %-6s", list[i].Name);
				printf("      %-23s", list[i].Adress);
				printf("    %s\n", list[i].Phone);
			}
		}

		if (i == 22) // 첫번째 루프에만 적용
		{
			printf("          메인페이지로 이동 ( H )          다음페이지 이동( → )");
			// 입력 가능키 세부 설정(첫번째 페이지)
			input = _getch();
			if (input == -32)  // 방향키 입력(확장아스키고드)을 받기 위함
			{ 
				input = _getch();
			}
			if (input == 'h' || input == 'H' || input == 'ㅗ') // 한글 ㅗ입력시도 고려 해주기 위함
				return;

			else if (input == 77) // 77은 오른쪽 방향키의 확장아스키코드
			{
				j++;
				continue;
			}
			else printf("\a");
		}
		
		else if (i > 22 && list[i+1].ID != -1)
		{
			// 입력 가능키 세부 설정(중간 페이지)
			printf("  메인페이지로 이동 ( H )     이전페이지 이동( ← )     다음페이지 이동( → )");

			input = _getch();
			if (input == -32){
				input = _getch();
			}
			if (input == 'h' || input == 'H' || input == 'ㅗ')
			{
				system("cls");
				return;
			}
			else if (input == 77) 
			{
				j++;
				continue;
			}
			else if (input == 75)
			{
				j--;
				continue;
			}
			else printf("\a");
		}

		else
		{
			// 입력 가능 키 세부설정(마지막 페이지)
			printf("          메인페이지로 이동 ( H )         이전페이지 이동( ← )");
			input = _getch();
			if (input == -32){
				input = _getch();
			}
			if (input == 'h' || input == 'H' || input == 'ㅗ')
				return;
		
			else if (input == 75)
			{
				j--;
				continue;
			}
			else printf("\a");
		}
		
	}
	return;
}

void initID(Member* list)
{
	int i;
	for (i = 0; i < MAX; i++)
		list[i].ID = -1;

	return;
}

int main()
{
	int i;
	Member* list;
	Member* listBackUp;
	char input;

	list = (Member*)malloc(sizeof(Member)*MAX);
	listBackUp = (Member*)malloc(sizeof(Member)*MAX);
	
	for (i = 0; i < MAX; i++)
		listBackUp[i] = list[i];

	initID(list);
	dataInput(list);
	for (i = 0; i < MAX; i++)
		listBackUp[i] = list[i];  // 저장 취소시 출력할 리스트 백업
	
	mainPage(list);
	_Exit(list, listBackUp);

	return 0;
}