#include <stdio.h>
#include <algorithm>
using namespace std;

template<typename T>
void MinHeapify(T *arry,int size, int element)
{
	int lchild= element*2+1,rchild=lchild+1;//左右子树
	while(rchild<size)
	{
		if(arry[element]<=arry[lchild]&&arry[element]<=arry[rchild])
			return;
		if(arry[lchild]<=arry[rchild])//如果左边最小
		{
			swap(arry[element],arry[lchild]);//把左边提到上面
			element=lchild;//循环时整理子树
		}
		else //否则右面最小
		{
			swap(arry[element],arry[rchild]);
			element=rchild;
		}
		lchild=element*2+1;
		rchild=lchild+1;//重新计算子树位置
	}
	if(lchild<size && arry[lchild]<arry[element])//只有左子树且子树小于自己
	{
		swap(arry[lchild],arry[element]);
	}
	return;
}
//堆排序time:O(nlgn)
template<typename T>
void HeapSort(T*arry,int size)
{
	int i;
	for(i=size-1;i>=0;i--)//从子树开始整理树
	{
		MinHeapify(arry,size,i);
	}
	while(size>0)//拆除树
	{
		swap(arry[size-1],arry[0]);//将根（最小）与数组最末交换
		size--;//树大小减小
		MinHeapify(arry,size,0);//整理树
	}
	return;
}


int main()
{
	int i;
	int num[]={9,8,7,6,5,4,3,2,1,0};
	HeapSort(num,sizeof(num)/sizeof(int));
	for(i=0;i<sizeof(num)/sizeof(int);i++)
	{
		printf("%d ",num[i]);
	}
	printf("\n c++ ok\n");
	return 0;
}
