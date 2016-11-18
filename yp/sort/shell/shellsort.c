#include <stdio.h>
#include<iostream>  
using namespace std; 

void ShellSort(int* data,unsigned int len)
{
	if(len<=1||data==NULL)
		return;

	for(int div=len/2;div>=1;div/=2)
	{
		for(int i=div;i<len;i++)
		{
 			for(int j=i;(j-div>=0)&&(j>=0)&&(data[j]<data[j-div]);j-=div)
 			{				
 				swap( *(data+j),*(data+j-div));
 			}
		}
	}
}

int main()
{  
	int a[]={345,24,54,2,43,3,12,6};  
	ShellSort(a,8);  
	for(int i=0;i<8 ;i++)  
		cout<<a[i]<<" ";  
	cout<<endl;  
	return 0;
}
