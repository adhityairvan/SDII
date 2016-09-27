#include<stdlib.h>
#include<stdio.h>
#define SIZE 10
int tukar(int a[],int b[]){
	int t;
	t=*a;
	*a=*b;
	*b=t;
}

int urut(int data[]){
	int i,j;
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE-i;j++){
			if(data[j]>data[j+1])tukar(&data[j],&data[j+1]);
		}
	}
}
void cetak(int data[]){
	int i;
	for(i=0;i<SIZE;i++){
		printf("%d\n",data[i]);
	}
}

int main(){
	int i;
	int array[SIZE];
	printf("Masukkan Data 1-10\n");
	for(i=0;i<SIZE;i++){
		scanf("%d",&array[i]);
	}
	char pilihan;
	printf("Urutkan?y/n\n");
	scanf(" %c",&pilihan);
	if(pilihan=='y'){
		urut(array);
		cetak(array);
	}
	else{
		cetak(array);
	}
}
