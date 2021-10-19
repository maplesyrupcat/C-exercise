#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//文件操作相关的基础练习
#include<errno.h>
#include<string.h>
int main()
{
	FILE* pf = fopen("test.txt", "r");
	if (!pf)
		printf("%s\n", strerror(errno));
	else
	{
		printf("%c\n", fgetc(pf));
	}
	fclose(pf);
	pf = NULL;
	return 0;
}
int main()
{
	FILE* pf = fopen("test.txt", "w");
	if (!pf)
		printf("%s\n", strerror(errno));
	else
	{
		fputc('b', pf);
		fputc('i', pf);
		fputc('t', pf);
	}
	fclose(pf);
	pf = NULL;
	return 0;
}
int main()
{
	FILE* pf = fopen("test.txt", "r");
	char buf[1024] = { 0 };
	if (!pf)
		printf("%s\n", strerror(errno));
	else
	{
		char* p=fgets(buf,1024,pf);
		printf("%s\n",p);
	}
	fclose(pf);
	 pf = NULL;
	 return 0;
}
int main()
{
	FILE*pf = fopen("test.txt", "w");
	if (!pf)
		printf("%s\n", strerror(errno));
	else
	{
		fputs("hello ", pf);
		fputs("world", pf);
	}
	fclose(pf);
	pf = NULL;
}
int main()
{
	char buf[1024];
	fgets(buf, 1024, stdin);
	fputs(buf, stdout);
	return 0;
}

struct S
{
	char name[10];
	int age;
	double score;
};
int main()
{
	struct S s = { "abc", 20, 72.8 };
	FILE* pf = fopen("test.txt", "w");
	if (!pf)
		return 0;
	else
		fprintf(pf, "%s %d %.2lf", s.name, s.age, s.score);
	fclose(pf);
	pf = NULL;
	return 0;
}
int main()
{
	struct S s = { 0 };
	FILE* pf = fopen("test.txt", "r");
	if (!pf)
		return 0;
	else
	{
		fscanf(pf, "%s %d %lf", &(s.name), &(s.age), &(s.score));
		printf("%s %d %.2lf\n", (s.name), (s.age), (s.score)); 
	}
	fclose(pf);
	pf = NULL;
	return 0;
}
int main()
{
	struct S s = { 0 };
	fscanf(stdin, "%s %d %lf", &(s.name), &(s.age), &(s.score));
	fprintf(stdout, "%s %d %lf\n", (s.name), (s.age), (s.score));
	return 0;
}