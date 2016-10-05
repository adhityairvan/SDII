#include<stdio.h>

void insertion(int *array,int top){
    int i,j;
    int key;
    for(i=1;i<top;i++){
        key=array[i];
        j=i-1;
        while(j>=0 && array[j]>key){
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=key;
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
		insertion(array,i);
		cetak(array,i);
	}
	else{
		cetak(array,i);
	}
}
