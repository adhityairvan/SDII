#include<stdio.h>

void selection(int *array,int lenght){
    int i,j;int key,keyj;
    for(i=0;i<lenght-1;i++){
        key=array[i];
        keyj=i;
        for(j=i+1;j<lenght;j++){
            if(array[j]<key){
                key=array[j];
                keyj=j;
            }
        }
        array[keyj]=array[i];
        array[i]=key;
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
		selection(array,i);
		cetak(array,i);
	}
	else{
		cetak(array,i);
	}
}