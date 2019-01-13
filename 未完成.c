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
		printf("无法打开文件或创建文件！\n按任何键继续！\n");
		getchar();
		exit(0);
	}
	printf("请输入学生数量：");
	scanf_s("%d", &n);
	getchar();
	printf("学号\t姓名\t性别\t班级\t语文\t数学\t英语\n");
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
		printf("已输入%d个学生。", i + 1);
		pS++;
	}
	printf("输入完毕！\n共计%d个学生！\n", (*pS).sNumber - 1);
	pS = students;
	fclose(fp);


}


void Show_Info() 
{
	int i;
	struct Student *pS;
	pS = students;
	printf("现在打开文件...\n");
	if ((fopen("data", "r")) == NULL) 
	{
		printf("无法打开文件！\n按任意键继续！\n");
		getchar();
		exit(0);
	}
	printf("打开成功！\n");
	printf("学号\t姓名\t性别\t班级\t语文\t数学\t英语\n");
	for (i = 0; i < n; i++) 
	{
		fread(pS, sizeof(struct Student), 1, fp);
		printf("NO%d\t", (*pS).sNumber);
		printf("%s\t%c\t%d\t%d\t%d\t%d\n", (*pS).sName, (*pS).sSex, (*pS).sClass, (*pS).Chinese, (*pS).Math, (*pS).English);
		pS++;
	}
	printf("输出完成！\n");
	pS = students;
	fclose(fp);
}

main()
{
	int c;
	while (1) 
	{
		printf("-----MENU-----");
		printf("\n|1.录入成绩\t|");
		printf("\n|2.输出成绩\t|");
		printf("\n|输入其他数来退出程序.\t|");
		printf("\n--------------\n");
		printf("你的选择：");
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