#include <stdio.h>

void selectsort(int *a,int len)
{
	int tmp =0;
	int index = 0;
	for(int i =0; i<len; i++)
	{
		tmp = a[i];
		index = i;
		for(int j = i+1;j<len;j++)
		{
			if(tmp > a[j])
			{
				tmp = a[j];
				index= j;
			}			
		}
		a[index]=a[i];
		a[i]=tmp;
	}  


}



int main()
{
	int a[]={342,367,1,989,3,9,235,8,0,432,2};
	int number = sizeof(a)/sizeof(int);
	selectsort(a,number);
	for(int i =0;i<number;i++)
	{
		printf(" %d",a[i]);
	}
	return 0;
}
