// micro_16.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdlib.h>

#define MAXSIZE 100


typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}node,*pnode;

typedef struct queue{
	pnode data[MAXSIZE];
	int front,rear;
};

void addNode(pnode &root,int x)
{
	if(root==NULL)
	{
		pnode p=(pnode)malloc(sizeof(pnode));
		p->data=x;
		p->left=NULL;
		p->right=NULL;
		root=p;
	}
	else
	{
		if(root->data<x)
		{
			addNode(root->right,x);
		}
		else
		{
			addNode(root->left,x);
		}
	}
}

/*
void initQueue(queue *q)
{
	q=(queue *)malloc(sizeof(queue));
	q->front=q->rear=0;
}
*/
void enQueue(queue *q,pnode x)
{
	if((q->rear+1)%MAXSIZE==q->front)
	{
		printf("FULL!");
		return;
	}
	q->data[q->rear]=x;
	q->rear=(q->rear+1)%MAXSIZE;
}

pnode deQueue(queue *q)
{
	if(q->rear==q->front)
	{
		printf("EMPTY!");
		return false;
	}

	pnode result=q->data[q->front];
	q->front=(q->front+1)%MAXSIZE;	
	return result;

}

void showTree(pnode tree)
{
	if(tree==NULL) return;

	queue *q=(queue *)malloc(sizeof(queue));
	q->front=q->rear=0;


	enQueue(q,tree);

	while(q->front!=q->rear)
	{
		pnode p=deQueue(q);
		if(p!=NULL)
		{
			printf("%d ",p->data);
			enQueue(q,p->left);
			enQueue(q,p->right);
		}
		
	}

}



int _tmain(int argc, _TCHAR* argv[])
{
	pnode root=NULL;
	
	addNode(root,8);
	addNode(root,6);
	addNode(root,10);
	addNode(root,5);
	addNode(root,7);
	addNode(root,9);
	addNode(root,11);

	showTree(root);
	getchar();

}

