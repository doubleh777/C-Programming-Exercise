//1.FileInput�� ���ؼ� ���������Ͽ� �ִ� ȸ�������� �о�� ����ü �迭�� �����Ѵ�.
//2.�������� : ȸ������, ȸ�����, ȸ������, ȸ������, ȸ���˻�, �����ϱ�, �����ϱ�(�������� ���忩�� �����)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
#include "MyFunction.h"

#pragma warning(disable : 4996)

int MAX = 255;
int changeOrNot = 0; // ����ÿ� ���� ���θ� �˱� ����
int start;  // ������ ����� �й� + 1 (ȸ�� ��Ͻ� ID �ѹ��� ������) 

void _Exit(Member* list, Member* listBackUp)
{
	FILE* fp;
	int i, j;
	char buf[10];
	char input;
	fp = fopen("data.txt", "wt"); // data.txt�� ������ ������� �����Ƿ� ����ó�� �� �ʿ����.
	system("cls");
	printf("================================================================================");
	printf("                        ȸ�� ���� ���� ���α׷� ���� �޴�\n");
	printf("================================================================================\n");
	if (changeOrNot != 0) // ����� ������ �ִ� ���
	{
		printf("\n\n\n\n\n     ����� ������ �ֽ��ϴ�. ���� �� �����Ͻðڽ��ϱ�? ( Y / N )");
		while (1)
		{
			input = _getch();
			if (input == 'Y' || input == 'y' || input == '��')
			{
				fprintf(fp, "%s\t%s\t%s\t%s\n","ȸ�� ���̵�", "ȸ���̸�", "ȸ���ּ�", "�ڵ��� ��ȣ");

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
			else if (input == 'N' || input == 'n' || input == '��')
			{
				fprintf(fp, "%s\t%s\t%s\t%s\n", "ȸ�� ���̵�", "ȸ���̸�", "ȸ���ּ�", "�ڵ��� ��ȣ");

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
	else   // ����� ������ ���� ���
	{
		fprintf(fp, "%s\t%s\t%s\t%s\n", "ȸ�� ���̵�", "ȸ���̸�", "ȸ���ּ�", "�ڵ��� ��ȣ");
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
	fp = fopen("data.txt", "wt"); // data.txt�� ������ ������� �����Ƿ� ����ó�� �� �ʿ����.

	system("cls");
	printf("================================================================================");
	printf("                              ȸ�� ���� ���� �޴�\n");
	printf("================================================================================\n");
	printf("\n\n\n\n\n     ����� ������ ��� �����Ͻðڽ��ϱ�? ( Y / N )");
	while (1)
	{
		input = _getch();
		if (input == 'Y' || input == 'y' || input == '��')
			break;
		else if (input == 'N' || input == 'n' || input == '��')
		{
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                         ȸ������ ������ ����ϼ̽��ϴ�.");
			getch();
			return;
		}
		else printf("\a");
	}
	fprintf(fp,"%s\t%s\t%s\t%s\n","ȸ�� ���̵�", "ȸ���̸�", "ȸ���ּ�", "�ڵ��� ��ȣ");
	
	for (i = 1; i < MAX; i++)
	{
		if (list[i].ID == -1)
			break;
		fprintf(fp,"%d\t%s\t%s\t%s\n",list[i].ID, list[i].Name, list[i].Adress, list[i].Phone);
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                         ȸ������ ������ �Ϸ��Ͽ����ϴ�.");
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
	printf("                              ȸ�� ���� �˻� �޴�\n");
	printf("================================================================================\n");
	printf("\n\n\n\n\n     �˻� ��� ���� :   1. ID Number�� �˻�     2. �̸����� �˻�\n");
	printf("\n     �˻��� ȸ�� �̸� : ");
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
			count++; // if���� �� �� ����ߴ��� üũ
		}
	}
	if (count == 0)
	{
		printf("\n\n\n\n\n\n\n\n\n\n                           error : �˻��� ȸ���� �����ϴ�.\n");
		printf("                     ������������ �̵� ( H )   �ٽ� �˻� ( S )");
		while (1)
		{
			input = _getch();
			if (input == 'H' || input == 'h' || input == '��')
				return;
			else if (input == 'S' || input == 's' || input == '��')
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

		printf("                    ������������ �̵� ( H )   �ٽ� �˻� ( S )");
		while (1)
		{
			input = _getch();
			if (input == 'H' || input == 'h' || input == '��')
				return;
			else if (input == 'S' || input == 's' || input == '��')
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
	printf("                              ȸ�� ���� �˻� �޴�\n");
	printf("================================================================================\n");
	printf("\n\n\n\n\n     �˻� ��� ���� :   1. ID Number�� �˻�     2. �̸����� �˻�\n");

	printf("\n     �˻��� ȸ�� ID Number : ");
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
			count++; // if���� �� �� ����ߴ��� üũ
		}
	}
	if (count == 0)
	{
		printf("\n\n\n\n\n\n\n\n\n\n                           error : �˻��� ȸ���� �����ϴ�.\n");
		printf("                     ������������ �̵� ( H )   �ٽ� �˻� ( S )");
		while (1)
		{
			input = _getch();
			if (input == 'H' || input == 'h' || input == '��')
				return;
			else if (input == 'S' || input == 's' || input == '��')
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

		printf("                    ������������ �̵� ( H )   �ٽ� �˻� ( S )");
		while (1)
		{
			input = _getch();
			if (input == 'H' || input == 'h' || input == '��')
				return;
			else if (input == 'S' || input == 's' || input == '��')
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
	printf("                              ȸ�� ���� �˻� �޴�\n");
	printf("================================================================================\n");
	printf("\n\n\n\n\n     �˻� ��� ���� :   1. ID Number�� �˻�     2. �̸����� �˻�\n");
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
	printf("                              ȸ�� ���� ���� �޴�\n");
	printf("================================================================================\n");
	printf("\n\n\n\n\n     ������ ȸ���� ID Number �Է� : ");
	gets(buf);
	for (i = 0; i < MAX; i++) // �Է��� ID Number�� ���� ����ü ã��
	{
		if (list[i].ID == atoi(buf) && atoi(buf) != 0)// atoi�Լ��� ���ڰ� ���� 0�� ����ϱ� ����
			break;
	}
	if (i == MAX)
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n        ������������ �̵� ( H )      error : ��ġ�ϴ� ȸ���� �����ϴ�.");
		input = _getch();
		if (input == 'h' || input == 'H' || input == '��')
			return;
		else deleteMember(list); return;
	}

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n                       ������ �����Ͻðڽ��ϱ�? ( Y / N )\n");
	
	
	while (1)
	{
		input = _getch();
		if (input == 'y' || input == 'Y' || input == '��')
		{
			for (; i < MAX; i++)
			{
				list[i] = list[i+1];
			}

			printf("                  �Է��Ͻ� ȸ�������� ������ �Ϸ�Ǿ����ϴ�.");
			changeOrNot++;
			_getch();
			return;
		}
		else if (input == 'n' || input == 'N' || input == '��')
		{
			printf("                         ȸ������ ������ ��ҵǾ����ϴ�.");
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
	printf("                              ȸ�� ���� ���� �޴�\n");
	printf("================================================================================\n");
	printf("\n\n\n\n\n     ������ ȸ���� ID Number �Է� : ");
	printf("%s\n", arr);
	printf("\n");
	printf("     ���� �׸� ���� : 1. ID Number, 2. Name, 3. Adress, 4. PhoneNumber\n\n");
	printf("     ������ Phone Number : ");
	gets(buf);
	for (j = 0; j < MAX; j++)
	{
		if (strcmp(list[j].Phone, buf) == 0)
		{
			printf("\n\n\n\n\n\n\n\n\n\n                       error : �̹� ��ϵ� ��ȭ��ȣ�Դϴ�.");
			_getch();
			editPhoneNumber_errorCase(list, i, arr, buf);
			return;
		}
	}
	strcpy(list[i].Phone, buf);
	printf("\n\n\n\n\n\n\n\n\n\n                                               ������ �Ϸ�Ǿ����ϴ�.");
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
	printf("                              ȸ�� ���� ���� �޴�\n");
	printf("================================================================================\n");
	printf("\n\n\n\n\n     ������ ȸ���� ID Number �Է� : ");
	printf("%s\n", arr);
	printf("\n");
	printf("     ���� �׸� ���� : 1. ID Number, 2. Name, 3. Adress, 4. PhoneNumber\n\n");
	printf("     ������ Phone Number : ");
	gets(buf);
	for (j = 0; j < MAX; j++)
	{
		if (strcmp(list[j].Phone, buf) == 0)
		{
			printf("\n\n\n\n\n\n\n\n\n\n                       error : �̹� ��ϵ� ��ȭ��ȣ�Դϴ�.");
			_getch();
			editPhoneNumber_errorCase(list, i, arr, buf);
			return;
		}
	}
	strcpy(list[i].Phone, buf);
	printf("\n\n\n\n\n\n\n\n\n\n                                               ������ �Ϸ�Ǿ����ϴ�.");
	changeOrNot++;
	_getch();
	return;
	
}

void editName(Member* list, int i, char* arr)
{
	system("cls");
	printf("================================================================================");
	printf("                              ȸ�� ���� ���� �޴�\n");
	printf("================================================================================\n");
	printf("\n\n\n\n\n     ������ ȸ���� ID Number �Է� : ");
	printf("%s\n", arr);
	printf("\n");
	printf("     ���� �׸� ���� : 1. ID Number, 2. Name, 3. Adress, 4. PhoneNumber\n\n");
	printf("     ������ Name : ");
	gets(list[i].Name);
	printf("\n\n\n\n\n\n\n\n\n\n                                               ������ �Ϸ�Ǿ����ϴ�.");
	changeOrNot++;
	_getch();
	return;
}

void editAdress(Member* list, int i, char* arr)
{
	system("cls");
	printf("================================================================================");
	printf("                              ȸ�� ���� ���� �޴�\n");
	printf("================================================================================\n");
	printf("\n\n\n\n\n     ������ ȸ���� ID Number �Է� : ");
	printf("%s\n", arr);
	printf("\n");
	printf("     ���� �׸� ���� : 1. ID Number, 2. Name, 3. Adress, 4. PhoneNumber\n\n");
	printf("     ������ Aderess : ");
	gets(list[i].Adress);
	printf("\n\n\n\n\n\n\n\n\n\n                                               ������ �Ϸ�Ǿ����ϴ�.");
	changeOrNot++;
	_getch();
	return;

}
void editIDNumber_errorCase(Member* list, int i, char* arr) // ID Number�� ���Ƽ� ���Է� �޴� Case
{
	int j;
	char buf[10];
	system("cls");
	printf("================================================================================");
	printf("                              ȸ�� ���� ���� �޴�\n");
	printf("================================================================================\n");
	printf("\n\n\n\n\n     ������ ȸ���� ID Number �Է� : ");
	printf("%s\n", arr);
	printf("\n");
	printf("     ���� �׸� ���� : 1. ID Number, 2. Name, 3. Adress, 4. PhoneNumber\n\n");
	printf("     ������ ID Number : ");
	gets(buf);
	for (j = 0; j<MAX; j++)
	{
		if (list[j].ID == atoi(buf) && atoi(buf) != 0)
		{
			printf("\n\n\n\n\n\n\n\n\n\n                    error : �̹� ��ϵ� ID Number�Դϴ�.");
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
	printf("                              ȸ�� ���� ���� �޴�\n");
	printf("================================================================================\n");
	printf("\n\n\n\n\n     ������ ȸ���� ID Number �Է� : ");
	printf("%s\n", arr);
	printf("\n");
	printf("     ���� �׸� ���� : 1. ID Number, 2. Name, 3. Adress, 4. PhoneNumber\n\n");
	printf("     ������ ID Number : ");
	gets(buf);
	for (j = 0; j<MAX ; j++)
	{
		if (list[j].ID == atoi(buf) && atoi(buf) != 0)
		{
			printf("\n\n\n\n\n\n\n\n\n\n                    error : �̹� ��ϵ� ID Number�Դϴ�.");
			_getch();
			editIDNumber_errorCase(list, i, arr);
			break;
		}

	}

	list[i].ID = atoi(buf);
	printf("\n\n\n\n\n\n\n\n\n\n                                               ������ �Ϸ�Ǿ����ϴ�.");
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
	printf("                              ȸ�� ���� ���� �޴�\n");
	printf("================================================================================\n");
	printf("\n\n\n\n\n     ������ ȸ���� ID Number �Է� : ");
	gets(buf);
	for (i = 0; i < MAX ; i++)
	{
		if (list[i].ID == atoi(buf) && atoi(buf) != 0)// atoi�Լ��� ���ڰ� ���� 0�� ����ϱ� ����
			break;
	}
	if (i == MAX)
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n                        error : ��ġ�ϴ� ȸ���� �����ϴ�.");
		_getch();
		return;
	}

	printf("\n");
	
	printf("     ���� �׸� ���� : 1. ID Number, 2. Name, 3. Adress, 4. PhoneNumber\n\n");

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
	printf("                              �ű� ȸ�� ��� �޴�\n");
	printf("================================================================================\n");
	printf("              �̹� ��ϵǾ��ִ� ��ȭ��ȣ�Դϴ�. �ٽ� �Է��� �ֽʽÿ�.\n\n\n\n");
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
				printf("                              �ű� ȸ�� ��� �޴�\n");
				printf("================================================================================\n\n\n\n\n");
				printf("        ID Number : ");
				printf("%d\n", list[i].ID);
				printf("             Name : ");
				printf("%s\n", list[i].Name);
				printf("           Adress : ");
				printf("%s\n", list[i].Adress);
				printf("     Phone Number : ");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n                  �ǹٸ� ��ȭ��ȣ�� �ƴմϴ�. �ٽ� �Է����ֽʽÿ�.");
				_getch();

				system("cls");
				printf("================================================================================");
				printf("                              �ű� ȸ�� ��� �޴�\n");
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
		if (strcmp(list[j].Phone, list[i].Phone) == 0)  // �޴��� ��ȣ�� ������ ��� �ݺ�
			errorPhoneNumber(list, i);
	}*/
	for (j = 0; j < i; j++)
	{
		if (strcmp(list[j].Phone, list[i].Phone) == 0){
			errorPhoneNumber(list, i);  // �޴��� ��ȣ�� ������ ��� �ݺ�
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
	printf("                              �ű� ȸ�� ��� �޴�\n");
	printf("================================================================================\n\n\n\n\n");
	
	for (i = 0; i < MAX; i++) // ȸ����� �ȵǾ��ִ� ����ü ã��
	{
		if (list[i].ID == -1)
			break;  // �̶��� i���� ȸ������� �Ǿ����� ���� ���� �ռ� ����ü �ε���
	}

	printf("        ID Number : ");
	printf("%d\n", start++);
	//gets(buf);
	//
	//	for (j = 0; j < i; j++) //i �������� ���� ID�� �ִ��� üũ
	//	{
	//		if (atoi(buf) == list[j].ID && atoi(buf) != 0)// atoi()�Լ��� ���ڰ� ������ 0�� ��ȯ�ϱ� ������ �߰��� ���� 
	//		{
	//			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	//			printf("      �̹� ��ϵ� ȸ���Դϴ�. ȸ�� �˻� �׸񿡼� ��� ������ Ȯ���ϼ���.\n");
	//			printf("    ������������ �̵� ( H )  ȸ�� �˻��������� �̵� ( S )   ���Է� ( �ƹ�Ű )");
	//			input = _getch();
	//			if (input == 'H' || input == 'h' || input == '��')
	//				return;
	//			else if (input == 'S' || input == 's' || input == '��')
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
	//	list[i].ID = atoi(buf);  // ���ڿ��� �Է¹޾� ���������� ��ȯ�Ͽ� ����

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
					printf("\n\n\n\n\n\n\n\n\n\n\n\n                �ǹٸ� ��ȭ��ȣ�� �ƴմϴ�. �ٽ� �Է����ֽʽÿ�.");
					_getch();

					system("cls");
					printf("================================================================================");
					printf("                              �ű� ȸ�� ��� �޴�\n");
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

		if (strlen(list[i].Phone) != 0){   // ��ȣ�� ���� ����� ���� �� �����Ƿ� ��ȣ ���� ������� �ߺ����� ó�� ���� �ʵ��� ����ó��
			for (j = 0; j < i; j++)
			{
				if (strcmp(list[j].Phone, list[i].Phone) == 0)
				{
					errorPhoneNumber(list, i);  // �޴��� ��ȣ�� ������ ��� �ݺ�
					//errorPhoneNumber(list, i);
					system("cls");
					printf("================================================================================");
					printf("                              �ű� ȸ�� ��� �޴�\n");
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
		printf("\n\n\n\n\n\n\n\n\n\n\n\n      ���������� ����� �Ϸ�Ǿ����ϴ�.");
		printf("      ������������ �̵�( H )");

		while (1)
		{
			input = _getch();
			if (input == 'H' || input == 'h' || input == '��')
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
	
	if ((fp = fopen("data.txt", "rt")) == NULL)  //  ���� �б� ��Ʈ�� ������ ����ó��
	{
		fprintf(stderr, "No data");
		return -1;

	}
	while (fgets(buf, MAX, fp)) // �� �پ� �о����
	{	//ID
		for (i = 0;; i++)
		{
			if (buf[i] == '\t')  // '\t'���ö� ����
				break;
			token[i] = buf[i];  // token�� buf����
		}
		token[i] = '\0'; // token�� ID������ �� ���� NULL���� ����
		list[j].ID = atoi(token); // Member�� ����ü �迭 list�� list[0] ����ü�� ������ �ٲ� ID���� ����
		i++;


		start = list[j].ID + 1;  // ȸ�� ��Ͻ� ID�ѹ� ������
		//Name
		for (;; i++)
		{
			if (buf[i] == '\t') // '\t'���ö� ����
				break;

			list[j].Name[k] = buf[i]; // ����ü�� Name�迭�� ����
			k++;
		}
		list[j].Name[k] = '\0'; //NULL�� ����
		i++;
		k = 0;
		//Adress
		for (;; i++)
		{
			if (buf[i] == '\t') //'\t'���ö� ����
				break;

			list[j].Adress[k] = buf[i]; // ����ü�� Adress�迭�� ����
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

		j++; //���� ����ü(���� ����� ����)�� �Ѿ
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
		printf("                                 1.ȸ������\n");
		printf("                                 2.ȸ�����\n");
		printf("                                 3.ȸ������\n");
		printf("                                 4.ȸ������\n");
		printf("                                 5.ȸ���˻�\n");
		printf("                                 6.������� ����\n");
		printf("                                 7.����\n");
		printf("               ================================================\n");
		input = _getch();
		if (48 < input && 56 > input) // ����'1'�� �ƽ�Ű�ڵ�� 49
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
		else printf("\a"); // 1~7 �̿��� �� �Է½� beep�� ���
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
				for (int k = 0; k < 20 - i%21+1; k++) // ��ĭ newlineó��
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

		if (i == 22) // ù��° �������� ����
		{
			printf("          ������������ �̵� ( H )          ���������� �̵�( �� )");
			// �Է� ����Ű ���� ����(ù��° ������)
			input = _getch();
			if (input == -32)  // ����Ű �Է�(Ȯ��ƽ�Ű���)�� �ޱ� ����
			{ 
				input = _getch();
			}
			if (input == 'h' || input == 'H' || input == '��') // �ѱ� ���Է½õ� ��� ���ֱ� ����
				return;

			else if (input == 77) // 77�� ������ ����Ű�� Ȯ��ƽ�Ű�ڵ�
			{
				j++;
				continue;
			}
			else printf("\a");
		}
		
		else if (i > 22 && list[i+1].ID != -1)
		{
			// �Է� ����Ű ���� ����(�߰� ������)
			printf("  ������������ �̵� ( H )     ���������� �̵�( �� )     ���������� �̵�( �� )");

			input = _getch();
			if (input == -32){
				input = _getch();
			}
			if (input == 'h' || input == 'H' || input == '��')
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
			// �Է� ���� Ű ���μ���(������ ������)
			printf("          ������������ �̵� ( H )         ���������� �̵�( �� )");
			input = _getch();
			if (input == -32){
				input = _getch();
			}
			if (input == 'h' || input == 'H' || input == '��')
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
		listBackUp[i] = list[i];  // ���� ��ҽ� ����� ����Ʈ ���
	
	mainPage(list);
	_Exit(list, listBackUp);

	return 0;
}