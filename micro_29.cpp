// micro_29.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdlib.h>
#define LENGTH 20

typedef struct stack{
	int data[LENGTH];
	int top;
}stack;

void push(stack *s,int i)
{
	if(s->top==LENGTH-1)
	{
		printf(" FULL!");
		return;
	}
	s->data[++s->top]=i;
}

int pop(stack *s)
{
	if(s->top==-1)
	{
		printf("EMPTY");
		return 0;
	}
	return s->data[s->top--];
}

bool empty(stack *s)
{
	if(s->top==-1) return true;
	return false;
}

bool match(int a[],int b[],int n)
{
	stack* s=(stack *)malloc(sizeof(stack));
	s->top=-1;

	int i,j;
	i=j=0;
	while(i<n&&j<n)
	{
		if(a[i]==b[j])
		{
			i++;
			j++;
		}
		else
		{
			push(s,a[i]);
			i++;
		}
	}

	while(!empty(s))
	{
		int next=pop(s);
		if(next==b[j]) j++;
		else return false;
	}
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[]={1,2,3,4,5};
	int b[]={4,5,2,3,1};

	bool c=match(a,b,5);
	if(c) printf("It matches.");
	else printf("NO");
	getchar();
}

