#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct data{
	char nama[100];
	float noktp;
	char kota[20];
}ktp;
void input(ktp input[],int *top){
	int i,a;
	printf("Masukkan banyak data yang ingin di input.. ");scanf("%d",&a);
	for(i=0;i<a;i++){
		printf("Masukkan Nama         : ");scanf("%s",input[*top].nama);
		printf("Masukkan nomor KTP    : ");scanf("%f",&input[*top].noktp);
		printf("Masukkan Kota tinggal : ");scanf("%s",input[*top].kota);
		
		*top+=1;
	}
}
void output(ktp output[],int top){
	int i;
	for(i=0;i<top;i++){
		if(output[i].noktp!=-1){
			printf("Nama      : %s\n",output[i].nama);
			printf("Nomor KTP : %.0f\n",output[i].noktp);
			printf("Kota      : %s\n",output[i].kota);
		}
	}
	printf("-------End of data------\n");
	system("pause");
}

int carinomor(ktp cari[],int top,int nomor){
	int i;
	for(i=0;i<top;i++){
		if(cari[i].noktp==nomor){
			printf("Nama      : %s\n",cari[i].nama);
			printf("Nomor KTP : %.0f\n",cari[i].noktp);
			printf("Kota      : %s\n",cari[i].kota);
			return i;
		}
	}
	printf("Data yang anda cari tidak ada\n");
	return -1;
}

int carinama(ktp cari[],int top,char nama[]){
	int i;
	for(i=0;i<top;i++){
		if(strcmp(nama,cari[i].nama)==0){
			printf("Nama      : %s\n",cari[i].nama);
			printf("Nomor KTP : %.0f\n",cari[i].noktp);
			printf("Kota      : %s\n",cari[i].kota);
			return i;
		}
	}
	printf("Data yang anda cari tidak ada\n");
	return -1;
}

void hapus(ktp hapus[],int top){
	int pilih,hasil;
	char nama[100];
	float nomor;
	printf("Ketik 1 untuk menghapus berdasarkan nama.\n Ketik 2 untuk menghapus berdasarkan nomor KTP\n");
	scanf("%d",&pilih);
	if(pilih==1){
		printf("Masukkan nama yang ingin dihapus ");scanf("%s",nama);
		hasil=carinama(hapus,top,nama);
		if(hasil!=-1){
			hapus[hasil].noktp=-1;
			printf("Data berhasil dihapus\n");
		}
	}
	else{
		printf("Masukkan nomor KTP yang ingin di hapus ");scanf("%f",&nomor);
		hasil=carinomor(hapus,top,nomor);
		if(hasil!=-1){
			hapus[hasil].noktp=-1;
			printf("Data berhasil dihapus\n");
		}
	}
}
void print(){
	printf("Program pendataan masyarakat\n");
	printf("Pilih opsi yang anda inginkan\n");
	printf("1.Input Data\n2.Hapus Data\n3.Tampilkan Data\n4.Cari berdasarkan nama\n5.Cari berdasarkan nomor KTP\n0.Keluar\n");
	printf("Silahkan Ketik disini");
}
int main(){
	ktp data_program[1000];
	int jumlahdata=0,pilihan;
	int i,a;
	char b[100];
	print();
	while(scanf("%d",&pilihan)){
		if(pilihan==1){
			system("cls");
			input(data_program,&jumlahdata);
			printf("%d\n",jumlahdata);
			print();
		}
		else if(pilihan==2){
			system("cls");
			hapus(data_program,jumlahdata);
			print();
		}
		else if(pilihan==3){
			system("cls");
			output(data_program,jumlahdata);
			print();
		}
		else if(pilihan==4){
			system("cls");
			printf("Masukkan Nama yang dicari : ");scanf("%s",b);
			carinama(data_program,jumlahdata,b);
			print();
		}
		else if(pilihan==5){
			system("cls");
			printf("Masukkan nomor KTP yang dicari : ");scanf("%d",&a);
			carinomor(data_program,jumlahdata,a);
			print();
		}
		else break;
	}
	printf("Program selesai.Terimakasih\n");
	return 0;
}
