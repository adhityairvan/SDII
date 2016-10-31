#include<stdio.h>
#include<string.h>

void urutarray(char input[],int panjang);
void tukar(char *elemen1,char *elemen2);


int main()
{
	char input[100];
	char string[100];
	char temp[100],temp2[100];//agar fungsi urut array tidak merubah string asli nya
	scanf("%100s",input);//%100s limit agar inputan tidak overflow
	strupr(input);strcpy(temp,input);urutarray(temp,strlen(temp));//merubah input menjadi huruf besar semua,agar mudah di compare.mengurut huruf dari yang terkecil
	scanf("%100s",string);//%100s limit agar inputan tidak overflow
	strupr(string);strcpy(temp2,input);urutarray(temp2,strlen(temp2));//merubah input menjadi huruf besar semua,agar mudah di compare.mengurut huruf dari yang terkecil
	if(strcmp(temp,temp2)==0) printf("String \"%s\" dan \"%s\" adalah sebuah anagram\n",input,string);
	else printf("String \"%s\" dan \"%s\" bukan sebuah anagram\n",input,string);
}
void tukar(char *elemen1,char *elemen2)//fungsi menukar elemen array
{
	char hold;
	hold=*elemen1;
	*elemen1=*elemen2;
	*elemen2=hold;
}
void urutarray(char *input,int panjang)//sort array menggunakan bubble sort
{
	int pass,j;
	for(pass=0;pass<panjang-1;pass++)
	{
		for(j=0;j<panjang-1;j++)
		{
			if(input[j]>input[j+1])
			{
				tukar(&input[j],&input[j+1]);
			}
		}
	}	
}
