#include <stdio.h>

void bubblesqort(int *a,int len)
{
	int tmp=0;
	for(int i =0;i<len-1;i++)
	{
		for(int j =0;j<len-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
	}
}

int main()
{
	int a[]={342,367,1,989,3,9,235,8,0,432,2};
	int number = sizeof(a)/sizeof(int);
	bubblesqort(a,number);
	for(int i =0;i<number;i++)
	{
		printf(" %d",a[i]);
	}
	return 0;
}
