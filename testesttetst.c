#include<stdio.h>
#include<stdlib.h>

struct node{
    int nilai;
    struct node *next;
    struct node *prev;
};
struct node *head;

int init(){
    head=NULL;
}

int isempty(){
    if(head==NULL)return 1;
    else return 0;
}

int add(int data){
    struct node *baru;
    baru=malloc(sizeof(struct node));
    baru->nilai=data;
    baru->next=baru;
    baru->prev=baru;
    if(isempty()==1){
        head=baru;
        return 1;
    }
    else{
        baru->prev=head->prev;
        baru->next=head;
		head->prev=baru;
		if(head->next=head)head->next=baru;
        head=baru;
        return 1;
    }
    return 0;
}

int deltop(){
    struct node *bantu;
    if(isempty()==1)return 0;
    else{
        bantu=head;
        head=head->next;
        head->prev=bantu;
        free(bantu);
        return 1;
    }
}

int search(int data){
    struct node *bantu;
    bantu=head;
    if(isempty()==1)return 0;
    else if(bantu->nilai==data)return 1;
    else{
        bantu=bantu->next;
        while(bantu!=head){
            if(bantu->nilai==data)return 1;
            else bantu=bantu->next;
        }
        return 0;
    }
}

void show(){
    struct node *bantu;
    if(head==NULL)return;
    bantu=head;
    do{
        printf("%d ",bantu->nilai);
        bantu=bantu->next;
    }while(bantu!=head);
}

int main(){
	int id;//variable input data
	while(1){
		//system("clear");//membersihkan layar command prompt
		printf("1.Inisiasi Double link list\n2.Tambah data\n3.cetak semua data\n4.Hapus data\n0.Exit\n");
		int pilihan;scanf("%d",&pilihan);
		switch(pilihan){//switch case untuk setiap pilihan
			case 1 :
				init();
				printf("Double linklist terinisialisasi\n");//system("pause");
			break;
			case 2 :
				printf("Ketik angka");
				scanf("%d",&id);
				int hasil=add(id);
				if(hasil==1)printf("Data berhasil ditambahkan\n");else printf("Data gagal diinput\n");//system("pause");//check apakah input berhasil atau tidak
			break;
			case 3 :
				show();
                system("pause");
			break;
			case 4 : 
				deltop();
				printf("Data berhasil dihapus\n");//system("pause");
			break;
			case 0 ://0 untuk exit
				return 0;
			break;
			default : printf("Salah pilihan,ulangi lagi\n");
		}
	}
}
