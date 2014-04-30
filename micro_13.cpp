// micro_13.cpp : Defines the entry point for the console application.
//思路：两个指针p1,p2。p1先便利k个元素，然后p1,p2同时向后便利到末尾，p2指向的就是倒数第k个。

#include "stdafx.h"
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node,*pnode;

int findLastK(pnode L,int k)
{
	if(L==NULL)
	{
		return NULL;
	}

	pnode phead,pbehind;
	phead=pbehind=L->next;

	int i=0;
	while(phead&&i<k) 
	{
		phead=phead->next;
		i++;
	}

	if(i<k) return NULL;

	while(phead!=NULL)
	{
		phead=phead->next;
		pbehind=pbehind->next;
	}

	return pbehind->data;
}

void insert(pnode L,int num)
{
	
	pnode p=(pnode)malloc(sizeof(pnode));
	p->data=num;
	p->next=L->next;
	L->next=p;
}

int _tmain(int argc, _TCHAR* argv[])
{
	pnode L=(pnode)malloc(sizeof(pnode));
	L->next=NULL;

	for(int i=0;i<10;i++)
	{
		insert(L,i*7+3);
	}

	printf("%d",findLastK(L,5));
	getchar();

}

