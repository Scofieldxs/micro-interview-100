// micro_24.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}node,*pnode;

void reverse(pnode root)
{
	if(root==NULL) return ;
	pnode p,q,r;
	p=root->next;
	q=p->next;
	p->next=NULL;

	while(q->next!=NULL)
	{
		r=q->next;

		q->next=p;
		p=q;
		q=r;
	}
	q->next=p;

	root->next=q;
}

int _tmain(int argc, _TCHAR* argv[])
{
	pnode root=(pnode)malloc(sizeof(pnode));
	root->next=NULL;

	for(int i=0;i<10;i++)
	{
		pnode tmp=(pnode)malloc(sizeof(pnode));
		tmp->data=i;

		tmp->next=root->next;
		root->next=tmp;
	}

	reverse(root);

	pnode p=root->next;
	while(p!=NULL)
	{
		printf("%d->",p->data);
		p=p->next;
	}
	getchar();
}

