#include <stdio.h>
void qsort(int *a,int nleft, int nright)
{
	if(nleft>=nright)
		return;
	int i =nleft;
	int j =nright;
	int key =a[i];
	while(i<j)
	{
		while(i<j && a[j]>=key)
			j--;
		a[i]=a[j];
		while(i<j && a[i]<=key)
			i++;
		a[j]=a[i];
	}
	a[i]=key;

	qsort(a,nleft,i-1);
	qsort(a,i+1,nright);	

}

int main()
{
	int a[]={4321,3,54,57,96567,23,78634,67565,23,78,0,4,56,234,321,1,5546,62634};
	int len = sizeof(a)/sizeof(int);
	qsort(a, 0, len-1);
	for(int i =0;i<len;i++)
	{
		printf(" %d",a[i]);
	}
	return 0;
}
