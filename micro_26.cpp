// micro_26.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void reverse(char *a,int start,int end)
{
	int i,j;
	for(i=start,j=end-1;i<j;i++,j--)
	{
		char tmp=a[i];
		a[i]=a[j];
		a[j]=tmp;
	}
}

void leftReverse(char *a,int len,int num)
{
	
	reverse(a,0,num);
	reverse(a,num,len);
	reverse(a,0,len);
}


int _tmain(int argc, _TCHAR* argv[])
{
	char a[]={"abcdef"};
	leftReverse(a,6,2);

	printf("%s",a);
	getchar();
}

