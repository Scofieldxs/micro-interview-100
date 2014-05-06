// micro_20.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

long  convert(char a[])
{
	if(a==NULL) return false;
	long  num=0;
	while(*a!='\0')
	{
		if(*a<='9'&&*a>='0')
		{
			num=num*10+*a-'0';
			a++;
		}
		else
		{
			printf("ERROR!\n");
			return false;
		}
	}
	return num;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char a[]={"1991216"};
	//char a[10];
	printf("Her birthday is %ld.",convert(a));
	getchar();
}

