// 19.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdlib.h>



long  fibinacciN_1(long n)
{
	long  *a=(long  *)malloc(sizeof(long )*n);
	*a=0;
	*(a+1)=1;

	if(n==0) return 0;
	if(n==1) return 1;

	long i;
	for(i=2;i<=n;i++)
	{
		*(a+i)=*(a+i-1)+*(a+i-2);
	}
	return *(a+i-1);
}

long fibinacciN_2(unsigned n)
{
	int result[2]={0,1};
	if(n<2) return result[n];

	long long fibOne=0;
	long long fibTwo=1;
	long long fib=0;

	for(int i=2;i<=n;i++)
	{
		fib=fibOne+fibTwo;
		fibOne=fibTwo;
		fibTwo=fib;
	}
	return fib;

}

int _tmain(int argc, _TCHAR* argv[])
{
	int n=10;
	printf("%d fibinicci is %ld",n,fibinacciN_2(n));
	getchar();
}

