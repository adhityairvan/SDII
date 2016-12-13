# include <stdio.h>
# include <conio.h>
# include <stdlib.h>

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

void *search(node *root, char key[], FILE *output) {
   node *temp;
   temp = root;
	while (temp != NULL) {
    	if (strcmp(temp->nama,key)==0) {
        	fprintf(output,"\nThe Element with Name %s is Present\n", temp->nama);
        	if(temp->id[0]=='5')fprintf(output,"Mahasiswa\nNama : %s\nNo ID : %s\n\n",temp->nama,temp->id);
      		else fprintf(output,"Dosen\nNama : %s\nNo ID : %s\n\n",temp->nama,temp->id);
      	}
      	if (strcmp(temp->nama,key)>0)
        	temp = temp->left;
      	else
        	temp = temp->right;
   }
   return NULL;
}

void postorder(node *temp,FILE *output) {
   if (temp != NULL) {
      postorder(temp->left,output);
      postorder(temp->right,output);
      if(temp->id[0]=='0')fprintf(output,"Output data selesai\n");
      else if(temp->id[0]=='5')fprintf(output,"Mahasiswa\nNama : %s\nNo ID : %s\n\n",temp->nama,temp->id);
      else fprintf(output,"Dosen\nNama : %s\nNo ID : %s\n\n",temp->nama,temp->id);
   }
}

int main() {
	int pilih;
	char ans = 'N';
	int key;
	node *new_node, *root, *tmp, *parent;
	node *init_node();
	root = NULL;
	char nama[30];
	char kode[30]="0000000000";
	FILE *out;
	out = fopen("output.txt","w");
	FILE *inp;
	inp = fopen("input.txt","r");

	root = (node *)malloc(sizeof(node));
	if(root==NULL)printf("Failed to initiate root nodes");
	root->left=NULL;
	root->right=NULL;
	strcpy(root->id,kode);
	
	
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
	printf("%s %s\n",root->left->nama,root->left->id);
	printf("%s %s\n",root->left->left->nama,root->left->left->id);
	printf("%s %s\n",root->right->nama,root->right->id);
	printf("%s %s\n",root->right->right->nama,root->right->right->id);
	search(root,"irvam",out);
	fclose(inp);fclose(out);
}
