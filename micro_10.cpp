// micro_10.cpp : Defines the entry point for the console application.
//思路：先整个翻转，再将各个词翻转，可读性比较差，
//将翻转写成函数roll

#include "stdafx.h"


void reverse(char str[])
{
	int n=0;
	char *tmp=str;
	while(*tmp!='\0')
	{
		n++;
		tmp++;
	}

	for(int i=0;i<n/2;i++)
	{
		char mid=*(str+i);
		*(str+i)=*(str+n-1-i);
		*(str+n-1-i)=mid;
	}
	//printf("%s\n",str);

	int j=0;
	int i=0;
	while(i<n)
	{
		j=i;
		while(*(str+i)!=' ') i++;
		if(i<n)
		{
			int len=i-j;
			for(int k=0;k<len/2;k++)
			{
				char mid=*(str+j+k);
				*(str+j+k)=*(str+i-k-1);
				*(str+i-k-1)=mid;
			}
		}
		i++;
	}

	printf("%s",str);
}

void roll(char str[],int start,int end)
{
	int len=end-start;
	for(int i=0;i<len/2;i++)
	{
		char tmp=str[start+i];
		str[start+i]=str[end-i-1];
		str[end-i-1]=tmp;
	}
}

void reverse_1(char str[])
{
	int n=0;
	char *tmp=str;
	while(*tmp!='\0')
	{
		n++;
		tmp++;
	}

	roll(str,0,n);
	printf("%s\n",str);

	int j=0;
	int i=0;
	while(i<n)
	{
		j=i;
		while(*(str+i)!=' ') i++;
		if(i<n)
		{			
			roll(str,j,i);
		}
		i++;
	}

	printf("%s",str);
}

int _tmain(int argc, _TCHAR* argv[])
{
	char str[]={"I was once a student"};

	//reverse(str);
	reverse_1(str);
	getchar();
}

