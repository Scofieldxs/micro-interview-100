// micro_25.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int continumax(char *outputstr,char *inputstr)
{
	char max[20],tmp[20];
	int maxlen,tmplen;
	maxlen=0;

	while(*outputstr!='\0')
	{
		tmplen=0;
		while(*outputstr!='\0'&&*outputstr>='0'&&*outputstr<='9')
		{
			tmp[tmplen++]=*outputstr++;
		}
		if(maxlen<tmplen)
		{
			for(int i=0;i<tmplen;i++)
			{
				*(inputstr+i)=tmp[i];
			}
			maxlen=tmplen;
		}
		outputstr++;
	}
	*(inputstr+maxlen)='\0';
	return maxlen;
}


int _tmain(int argc, _TCHAR* argv[])
{
	char a[]={"abcd12345ed125ss123456789"};
	char b[20];

	int len=continumax(a,b);
	printf("The max number is %s,the length is %d",b,len);
	getchar();
}

