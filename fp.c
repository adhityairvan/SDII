#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct tree {
   char nama[30];
   char id[30];
   struct tree *left, *right;
} node;

node *init_node() {
   node *temp;
   temp = (node *) malloc(sizeof(node));
   temp->left = NULL;
   temp->right = NULL;
   return temp;
}

void insert(node *root, node *new_node) {
   if (strcmp(root->nama,new_node->nama)>0) {
      if (root->left == NULL){
         root->left = new_node;
	 }
      else{
        insert(root->left, new_node);
	   }
   }

	if (strcmp(root->nama,new_node->nama)<0) {
    	if (root->right == NULL){
        	root->right = new_node;
	 	}
    	else{
        	 insert(root->right, new_node);	
   		}		
	}
}

node *search(node *root, char key[], FILE *output) {
   node *temp;
   temp = root;
	while (temp != NULL) {
    	if (strcmp(temp->nama,key)==0) {
        	fprintf(output,"\nThe Element with Name %s is Present\n", temp->nama);
        	if(temp->id[0]=='5')fprintf(output,"Mahasiswa\nNama : %s\nNo ID : %s\n\n",temp->nama,temp->id);
      		else {
			fprintf(output,"Dosen\nNama : %s\nNo ID : %s\n\n",temp->nama,temp->id);
			printf("dapet dosen");
			}	
      		return temp;
      	}
      	else if (strcmp(temp->nama,key)<0){      	
        	temp = temp->right;
        }
      	else if(strcmp(temp->nama,key)>0){
			temp = temp->left;
        }
   }
   return NULL;
}

void postorder(node *temp,FILE *output) {
   	if 	(temp != NULL) {
      	postorder(temp->left,output);
      	postorder(temp->right,output);
      	fseek(output,0,SEEK_END);
      	fwrite(temp,sizeof(node),1,output);
   	}
}

void tampil(FILE *output){
	node temp;
	while(1){
		fread(&temp,sizeof(node),1,output);
		if(feof(output))break;
		if(temp.id[0]=='5')
		printf("Mahasiswa \n Nama : %s\n NRP : %s\n",temp.nama,temp.id);
		else printf("Dosen \n Nama : %s\n NRP : %s\n",temp.nama,temp.id);
	}
}

int main() {
	int pilih;
	int key;
	node *new_node, *root, *tmp;
	node *init_node();
	root = NULL;
	char nama[30];
	char kode[30]="0000000000";
	FILE *out;
	out = fopen("output.exe","wb");
	FILE *inp;
	inp = fopen("input.txt","r");
	FILE *bin;
	bin = fopen("output.exe","rb");
	FILE *text;
	text = fopen("output.txt","w");

	root = (node *)malloc(sizeof(node));
	if(root==NULL)printf("Failed to initiate root nodes");
	root->left=NULL;
	root->right=NULL;
	strcpy(root->id,kode);
	fprintf(text,"kontol");
	
	while(!feof(inp)){
		new_node=init_node();
		fscanf(inp,"%s %s",kode,nama);
		strcpy(new_node->nama,nama);strcpy(new_node->id,kode);
		if(new_node->id[0]=='5'){
			if(root->left==NULL){
				root->left=new_node;
			}
			else {
			insert(root->left,new_node);		
			}
		}
		else {
			if(root->right==NULL){
				root->right=new_node;
			}
			else {
			insert(root->right,new_node);		
			}
		}
	}
	postorder(root,out);
	tampil(bin);
	char pilihan;char cari[30];
	while(1){
		printf("You want to search the data?\n");
		scanf("%c",&pilihan);
		switch(pilihan){
			case 'y':{
				printf("Masukan nama yang dicari");
				scanf("%s",cari);
				tmp = search(root,cari,text);
				printf("Output Pencarian akan ada di file output.txt\n");
				if(tmp == NULL)tmp = search(root->right,cari,text);
				if(tmp == NULL)printf("Pencarian gagal,Nama tidak ditemukan\n");
				break;
			}
			case 'n':{
				return 0;
				break;
			}
		}
		fflush(stdin);
	}

	fclose(inp);fclose(out);
}
