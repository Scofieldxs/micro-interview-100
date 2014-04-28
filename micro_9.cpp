// micro_9.cpp : Defines the entry point for the console application.
//思路：最后一个数为根节点，通过比较把左树，右树分开，看右树是否都大于根节点，迭代判断。可能有问题。

#include "stdafx.h"


bool isTree(int a[],int start,int end)//
{
	if(start==end-1) return true;
	int root=a[end-1];
	int midIndex;
	
	int i=start;
	for(;i<end-1;i++)
	{
		if(a[i]>root) break;
	}

	int j;
	for(j=i;j<end-1;j++)
	{
		if(a[j]<root) return false;
	}

	bool result=isTree(a,start,i);
	if(!result) return false;
	result=isTree(a,i,end-1);
	if(!result) return false;
	return true;
}

bool isTree_1(int a[],int n)
{
	if(a==NULL)return false;
	if(n<=1) return true;
	 
	int root=a[n-1];
	int i;
	for(i=0;i<n-1;i++)
	{
		if(a[i]>root) break;
	}
	int j;
	for(j=i;j<n-1;j++)
	{
		if(a[j]<root) return false;
	}
	bool result=isTree_1(a,i);
	if(!result) return false;
	result=isTree_1(a+i,n-1-i);
	if(!result) return false;
	return true;
	
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[]={5,7,6,9,11,10,8};
	
	//printf("%d",isTree(a,0,7));
	printf("%d",isTree_1(a,7));
	getchar();
}

