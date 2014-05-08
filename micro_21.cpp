// micro_21.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<list>
#include<iostream>
using namespace std;

list<int> lst;
void find(int sum,int n)
{
	if(n<=0||sum<=0) return;

	if(n==sum)
	{
		lst.reverse();
		for(list<int>::iterator iter=lst.begin();iter!=lst.end();iter++)
		{
			cout<<*iter<<"+";
		}
		cout<<n<<endl;
		lst.reverse();
	}

	lst.push_front(n);
	find(sum-n,n-1);
	lst.pop_front();
	find(sum,n-1);
	

}

int _tmain(int argc, _TCHAR* argv[])
{
	find(14,10);
	getchar();
}

