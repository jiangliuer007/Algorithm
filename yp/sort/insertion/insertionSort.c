#include <stdio.h>

void insert_sort(int *array, unsigned int n)
{
	int i,j;
	int temp;
	for(i=1; i<n;i++)
	{
		temp = *(array+i);
		for(j=i;j>0 && *(array+j-1)>temp;j--)
		{
		 	*(array+j) = *(array+j-1);
		}
		*(array+j)=temp;
	}
}


int main()
{
	int m[]={223,53,232,43,343435,231,13,56,2,7343,3,64426,23,53462,23,2,6544,3,4};
	int len = sizeof(m)/sizeof(int);
	insert_sort(m, len);
	for(int i = 0;i<len;i++)
	{
		printf("%d ", m[i]);
	}
	printf("\n ok\n");
	return 0;
}
