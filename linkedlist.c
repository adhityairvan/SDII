#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int noid;
	char nama[100];
	struct node *next;
}*head;

int init(){
	head=NULL;
}

int add(char name[],int id){
	struct node *baru;
	baru = malloc(sizeof(struct node));
	baru->next=NULL;
	baru->noid=id;
	strcpy(baru->nama,name);
	if(head==NULL){
		head=baru;
		return 1;
	}
	else {
		baru->next=head;
		head=baru;
		return 1;
	}
	return 0;	
}
int print(){
	struct node *bantu;
	bantu=head;
	if(bantu==NULL)return 0;
	else{
		while(bantu!=NULL){
			printf("Nama : %s\nNoID : %d\n\n",bantu->nama,bantu->noid);
			bantu=bantu->next;	
		}
	}
	return 1;
}

int main(){
	int id;char data[100];
	while(1){
		system("cls");
		printf("1.Inisiasi Linked head\n2.Tambah data\n3.cetak semua data\n0.Exit\n");
		int pilihan;scanf("%d",&pilihan);
		switch(pilihan){
			case 1 :
				init();
				printf("Linked head terinisialisasi\n");system("pause");
			break;
			case 2 :
				printf("Ketik nama yang diinput ");
				scanf("%100s",data);
				scanf("%d",&id);
				int hasil=add(data,id);
				if(hasil==1)printf("Data berhasil ditambahkan\n");else printf("Data gagal diinput\n");system("pause");
			break;
			case 3 :
				print();
				system("pause");
			break;
			case 0 :
				return 0;
			break;
			default : printf("Salah pilihan,ulangi lagi\n");
		}
	}
}
