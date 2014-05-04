// micro_14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


void addEqual(int a[],int n,int x)
{
	int i,j;
	i=0;
	j=n-1;
	while(i<j)
	{
		if(a[i]+a[j]==x)
		{
			printf("%d + %d = %d\n",a[i],a[j],x);
			i++;
			j--;
		}
		else
		{
			if(a[i]+a[j]<x)
			{
				i++;
			}
			else
			{
				j--;
			}
		}
	}

}

void addEqual_1(int a[],int n,int x)
{
	int i,j;
	i=0;
	j=n-1;
	while(i<j)
	{
		int sum=a[i]+a[j];
		if(sum==x)
		{
			printf("%d + %d = %d\n",a[i],a[j],x);
			i++;
			j--;
		}
		else
		{
			if(sum<x)
			{
				i++;
			}
			else
			{
				j--;
			}
		}
	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[]={1,2,4,7,11,13};
	addEqual(a,6,15);
	getchar();
}

