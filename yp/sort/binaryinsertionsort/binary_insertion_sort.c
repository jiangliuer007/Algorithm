#include <iostream>
using namespace std;

void BinaryInsertSort(int *a,int left, int right)
{
	int tmp;
	int i,low,high,middle,k;
	
	for(i = left+1;i<=right; i++)
	{
		tmp = a[i];
		low = left;
		high = i-1;
		while( low<=high)
		{
			middle = (low+high)/2;
			if(tmp < a[middle])
				high = middle -1;
			else
				low = middle +1;
		}
		for(k = i-1;k>low; k--)
			a[k+1] = a[k];
		a[low] = tmp;
	}
}

int main()
{
	int a [] = {43,24,54,3,345,2,654,2};
	BinaryInsertSort(a,0,7);
	for(int i=0; i<8; i++)
		cout<<a[i]<<" ";	
	cout <<endl;
	return 0;
}

