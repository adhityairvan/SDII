#include <stdio.h>
#include <stdlib.h>

void cetak(int max, int x[])
{
	int d;
	for (d=0;d<max;d++)
	printf (" %2d ", x[d]);
	printf ("\n");
}

void swap(int x, int y, int datanya[])
{
	int tmp;
	tmp=datanya[x];
	datanya[x]=datanya[y];
	datanya[y]=tmp;
}

void insertSort(int max, int a[])
{
	int i, k, count=1;
	for (i=1;i<max;i++)
	for (k=i;k>0 && a[k]<a[k-1];k--)
	{
		swap(k,k-1,a);
		printf ("swap ke %2d\t", count++);
		cetak (max,a);
	}
}

int main()
{
	int c, max=0, data[100];
	
	while(scanf("%d", &data[max++])==1 && getchar() !='\n');
		
	printf ("data awal\t");
	cetak(max,data);
	insertSort(max,data);
	
	getchar();
	system("pause");
}
