// micro_27.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

long jump(int n)
{
	if(n==1) return 1;
	if(n==2) return 2;
	return jump(n-1)+jump(n-2);
}

int count(int i)//28
{
	int count=0;
	while(i)
	{
		if(i&1) count++;
		i=i>>1;
	}
	return count;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int k=5;
	printf("we have total %ld ways on floor %d",count(k),k);
	getchar();
}

