#include<stdlib.h>
#include<stdio.h>

int tukar(int a[],int b[]){
	int t;
	t=*a;
	*a=*b;
	*b=t;
}

int urut(int data[],int top){
	int i,j;
	for(i=0;i<top-1;i++){
		for(j=0;j<top-1;j++){
			if(data[j]>data[j+1])tukar(&data[j],&data[j+1]);
		}
	}
}
void cetak(int data[],int top){
	int i;
	for(i=0;i<top;i++){
		printf("%d\n",data[i]);
	}
}

int main(){
	int i=0;
	int array[1000];
	printf("Masukkan Data..\n");
	while(scanf("%d",&array[i])!=EOF)i++;
	char pilihan;
	printf("Urutkan?y/n\n");
	scanf(" %c",&pilihan);
	if(pilihan=='y'){
		urut(array,i);
		cetak(array,i);
	}
	else{
		cetak(array,i);
	}
}
