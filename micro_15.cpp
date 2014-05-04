// micro_15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}node,*pnode;

void mirror(pnode root)
{
	if(root==NULL) return;
	pnode tmp=root->left;
	root->left=root->right;
	root->right=tmp;

	mirror(root->left);
	mirror(root->right);
}

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

void showTree(pnode root)
{
	if(root==NULL) return;
	printf("%d ",root->data);
	showTree(root->left);
	showTree(root->right);
}

int _tmain(int argc, _TCHAR* argv[])
{
	pnode root=NULL;
	
	addNode(root,4);
	addNode(root,2);
	addNode(root,1);
	addNode(root,3);
	addNode(root,6);
	addNode(root,7);
	addNode(root,5);

	showTree(root);

	mirror(root);

	printf("\n");
	showTree(root);

	getchar();

}

