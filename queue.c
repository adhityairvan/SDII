#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct struktur{
    int umur[100];
    char nama[100][30];
    int size;
}queue;
int top=-2;
int bot=-1;

int init(queue *list){

        top=-1;
        list->size=0;
        bot=-1;
        return 1;
}
int push(queue *list,char *nama,int age){
    if(list->size==100||top==-2)return 0;
    else{
        list->umur[++top]=age;//printf("\n%d\n",top);
        strcpy(list->nama[top],nama);
        list->size++;
        if(bot==-1)bot=0;
        return 1;
    }
}
int pop(queue *list){
    if(list->size==0||bot==-1)return 0;
    else{
        printf("Nama : %s\nUmur : %d\n",list->nama[bot],list->umur[bot]);
        list->size--;
        int i;
		for(i=0;i<99;i++){
        	strcpy(list->nama[i],list->nama[i+1]);
        	list->umur[i]=list->umur[i+1];
        }
        top--;
        return 1;
    }
}

int print(queue *list){
    if(list->size==0||top==-1)return 0;
    else{
    	int i;
        for(i=0;i<=top;i++){
            printf("Nama : %s\n Umur : %d\n",list->nama[i],list->umur[i]);
        }
        return 1;
    }
}

int showtop(queue *list){
    if(top==-1||top==-2)return 0;
    else {
        printf("TOP OF THE STRUCTURE : %s %d\n",list->nama[top],list->umur[top]);
        printf("Bottom of the structure : %s %d\n",list->nama[bot],list->umur[bot]);
        return 1;
    }
}

int main(){
    int i,j,k,input1;
    char input2[30];
    queue q;
    while(1){
        printf("\nMasukan pilihan \n1.Input data ke Queue\n2.Pop data stack\n3.Print seluruh data\n4.Intip data teratas & terbawah\n5.Inisialisasi Queue.\n0.Exit program\n");
        scanf("%d",&j);
        if(j==0)break;
        switch(j){
            case 1 :
            printf("Masukan nama : ");scanf("%30s",input2);
            printf("Masukan umur : ");scanf("%d",&input1);
            if(push(&q,input2,input1)!=1)printf("Data gagal dimasukkan.stack penuh atau belum di inisiasi\n");
            else printf("Input sukses\n");
            break;
            case 2 :
            if(pop(&q)!=1)printf("Pop gagal dilakukan.Stack kosong atau belum disinisiasi\n");
            else printf("Pop berhasil\n");
            break;
            case 3 : 
            if(print(&q)!=1)printf("Stack kosong\n");
            else printf("End of Queue\n");
            break;
            case 4 :
            if(showtop(&q)!=1)printf("Data kosong\n");
            else printf("Data teratas & terbawah berhasil di print\n");
            break;
            case 5 :
            if(init(&q)==1)printf("Queue Di inisiasi\n");
            else printf("Inisiasi queue gagal\n");
            break;
            default : printf("Masukkan pilihan yang tepat\n");
        }
    }
}
