#include"pch.h"
#include<stdio.h>
#include<process.h>
#pragma warning(disable:4996)
int n;
FILE *fp;
struct Student 
{
	int sNumber;
	char sName[20];
	char sSex;
	int sClass;
	int Chinese;
	int Math;
	int English;
}students[100];
void Input_Info() 
{
	struct Student *pS;
	int index, i;
	pS = students;
	if ((fopen("data", "w") == NULL))
	{
		printf("�޷����ļ��򴴽��ļ���\n���κμ�������\n");
		getchar();
		exit(0);
	}
	printf("������ѧ��������");
	scanf_s("%d", &n);
	getchar();
	printf("ѧ��\t����\t�Ա�\t�༶\t����\t��ѧ\tӢ��\n");
	for (index = 0;index < n;index++) 
	{
		printf("NO%d\t", pS->sNumber);
		scanf("%s", pS[index].sName);
		getchar();
		printf("\t");
		scanf("%c", (char*)pS[index].sSex);
		getchar();
		printf("\t");
		scanf("%d",(int*)pS[index].sClass);
		getchar();
		printf("\t");
		scanf("%d", (int*)pS[index].Chinese);
		getchar();
		printf("\t");
		scanf("%d", (int*)pS[index].Math);
		getchar();
		printf("\t");
		scanf("%d", (int*)pS[index].English);
		getchar();
		printf("\n");
	}
	for (i = 0; i < n; i++)
	{
		fwrite(pS, sizeof(struct Student), 1, fp);
		printf("������%d��ѧ����", i + 1);
		pS++;
	}
	printf("������ϣ�\n����%d��ѧ����\n", (*pS).sNumber - 1);
	pS = students;
	fclose(fp);


}


void Show_Info() 
{
	int i;
	struct Student *pS;
	pS = students;
	printf("���ڴ��ļ�...\n");
	if ((fopen("data", "r")) == NULL) 
	{
		printf("�޷����ļ���\n�������������\n");
		getchar();
		exit(0);
	}
	printf("�򿪳ɹ���\n");
	printf("ѧ��\t����\t�Ա�\t�༶\t����\t��ѧ\tӢ��\n");
	for (i = 0; i < n; i++) 
	{
		fread(pS, sizeof(struct Student), 1, fp);
		printf("NO%d\t", (*pS).sNumber);
		printf("%s\t%c\t%d\t%d\t%d\t%d\n", (*pS).sName, (*pS).sSex, (*pS).sClass, (*pS).Chinese, (*pS).Math, (*pS).English);
		pS++;
	}
	printf("�����ɣ�\n");
	pS = students;
	fclose(fp);
}

main()
{
	int c;
	while (1) 
	{
		printf("-----MENU-----");
		printf("\n|1.¼��ɼ�\t|");
		printf("\n|2.����ɼ�\t|");
		printf("\n|�������������˳�����.\t|");
		printf("\n--------------\n");
		printf("���ѡ��");
		scanf("%d", &c);
		if (c == 1) 
		{
			Input_Info();
		}
		else if (c == 2) 
		{
			Show_Info();
		}
		else
		{
			exit(0);
		}
	}
}