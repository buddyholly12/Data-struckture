#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;

void sorting(char *input,int dummy1,int dummy2)
{
	int len=strlen(input);
	char dummy[100];
	strcpy(dummy,input);
	if(dummy1<len&&dummy2<len)
	{
		char temp=dummy[dummy1];
		dummy[dummy1]=dummy[dummy2];
		dummy[dummy2]=temp;
		
		cout<<dummy<<",";
		dummy2++;
		if(dummy2==len)
		{
			dummy1++;
			dummy2=0;
			if(dummy1<len-1)
			{
				temp=dummy[dummy1];
				dummy[dummy1]=dummy[dummy1+1];
				dummy[dummy1+1]=temp;
			}
			else
			{
				temp=dummy[dummy1];
				dummy[dummy1]=dummy[0];
				dummy[0]=temp;
			}
		}
		sorting(dummy,dummy1,dummy2);
	}
	else
		cout<<dummy;
	
}

void main()
{
	char data[100];
	cin>>data;
	sorting(data,0,1);
}