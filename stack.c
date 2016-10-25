#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct struktur{
    int umur[100];
    char nama[100][30];
    int size;
}stack;
int top=-2;

int init(stack *list){

        top=-1;
        return 1;
}
int push(stack *list,char *nama,int age){
    if(list->size==100||top==-2)return 0;
    else{
        list->umur[++top]=age;printf("\n%d\n",top);
        strcpy(list->nama[top],nama);
        list->size++;
        return 1;
    }
}
int pop(stack *list){
    if(list->size==0||top==-1)return 0;
    else{
        printf("Nama : %s\nUmur : %d\n",list->nama[top],list->umur[top]);
        list->size--;
        top--;
        return 1;
    }
}

int print(stack *list){
    if(list->size==0||top==-1)return 0;
    else{
        for(int i=0;i<=top;i++){
            printf("Nama : %s\n Umur : %d\n",list->nama[i],list->umur[i]);
        }
        return 1;
    }
}

int showtop(stack *list){
    if(top==-1||top==-2)return 0;
    else {
        printf("TOP OF THE STACK : %s %d\n",list->nama[top-1],list->umur[top-1]);
        return 1;
    }
}

int main(){
    int i,j,k,input1;
    char input2[30];
    stack s;
    while(1){
        printf("\nMasukan pilihan \n1.Input data ke stack\n2.Pop data stack\n3.Print seluruh data\n4.Intip data teratas\n5.Inisialisasi stack.\n0.Exit program\n");
        scanf("%d",&j);
        if(j==0)break;
        switch(j){
            case 1 :
            printf("Masukan nama : ");scanf("%30s",input2);
            printf("Masukan umur : ");scanf("%d",&input1);
            if(push(&s,input2,input1)!=1)printf("Data gagal dimasukkan.stack penuh atau belum di inisiasi\n");
            else printf("Input sukses\n");
            break;
            case 2 :
            if(pop(&s)!=1)printf("Pop gagal dilakukan.Stack kosong atau belum disinisiasi\n");
            else printf("Pop berhasil\n");
            break;
            case 3 : 
            if(print(&s)!=1)printf("Stack kosong\n");
            else printf("End of Stack\n");
            break;
            case 4 :
            if(showtop(&s)!=1)printf("Data kosong\n");
            else printf("Data teratas berhasil di print\n");
            break;
            case 5 :
            if(init(&s)==1)printf("Stack Di inisiasi\n");
            else printf("Inisiasi stack gagal\n");
            break;
            default : printf("Masukkan pilihan yang tepat\n");
        }
    }
}