// micro_17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void appearOnce(char a[])
{
	int letter[26]={0};

	while(*a!='\0')
	{
		if(*a<'z'&&*a>'a')
		{
			letter[*a-'a']+=1;
		}
		a++;
	}

	int i=0;
	for(;i<26;i++)
	{
		if(letter[i]==1)
		{
			printf("%c",(char)('a'+letter[i]));
			break;
		}
	}
	if(i==26) printf("No one appears once");
}

int _tmain(int argc, _TCHAR* argv[])
{
	char a[]={"abaccdeff"};
	appearOnce(a);
	getchar();
}

