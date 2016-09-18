#include<stdio.h>
#include<stdlib.h>
int travel(int matriks[][3],int b,int c);

int main()
{
	int array[3][3]={0};
	int i,a,b,c;
	int counter=0;
	for(i=0;i<3;i++)
	{
		for(a=0;a<3;a++)
		{
			scanf("%d",&array[i][a]);
		}
	}
	
	for(i=0;i<3;i++){
		for(a=0;a<3;a++){
			if( (array[i][a]==1) && ((array[i][a+1]==1) || 
									 (array[i+1][a]==1) || 
									 (array[i-1][a]==1) || 
									 (array[i][a-1]==1) ||
									 (array[i+1][a+1]==1)||
									 (array[i-1][a-1]==1)[]
									 ) )
			counter++;
		}
	}
	printf("%d",counter);

}
