#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int noid;
	char nama[100];
	struct node *next;
}*head;//membuat struct node dan mendeklarasi variable global bertipe struct node dengan nama head

int init(){
	head=NULL;//mengosongkan head
}

int hapus_depan()
{
	struct node *bantu;//membuat variable bantuan
	bantu=head;
	head=head->next;//menggeser head nya
	free(bantu);//dan membersihkan memori dari elemen yang dihapus
}
int add(char name[],int id){
	struct node *baru;
	baru = malloc(sizeof(struct node));//mendeklarasi kan variable baru dan mengalokasi kan memorinya
	baru->next=NULL;
	baru->noid=id;
	strcpy(baru->nama,name);
	//mengisi struct node baru dengan data yang diinginkan
	if(head==NULL){//jika head kosong,variable baru menjadi head.
		head=baru;
		return 1;
	}
	else {//jika head sudah ada isinya,sambungkan variable baru ke head,dan tunjuk baru sebagai head yang baru
		baru->next=head;
		head=baru;
		return 1;
	}
	return 0;	
}
int print(){//print seluruh isi linked list
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
	int id;char data[100];//variable input data
	while(1){
		system("cls");//membersihkan layar command prompt
		printf("1.Inisiasi Linked head\n2.Tambah data\n3.cetak semua data\n4.Hapus data\n0.Exit\n");
		int pilihan;scanf("%d",&pilihan);
		switch(pilihan){//switch case untuk setiap pilihan
			case 1 :
				init();
				printf("Linked head terinisialisasi\n");system("pause");
			break;
			case 2 :
				printf("Ketik nama yang diinput ");
				scanf("%100s",data);//%100s agar memberi batasan 100 character input agar tidak terjadi overflow
				scanf("%d",&id);
				int hasil=add(data,id);
				if(hasil==1)printf("Data berhasil ditambahkan\n");else printf("Data gagal diinput\n");system("pause");//check apakah input berhasil atau tidak
			break;
			case 3 :
				print();
				system("pause");
			break;
			case 4 : 
				hapus_depan();
				printf("Data berhasil dihapus\n");system("pause");
			break;
			case 0 ://0 untuk exit
				return 0;
			break;
			default : printf("Salah pilihan,ulangi lagi\n");
		}
	}
}

