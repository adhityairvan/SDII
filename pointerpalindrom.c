#include<stdio.h>
#include<string.h>

int main(){
	char input[10];
	scanf("%s",input);
	printf("%s",input);
	int len=strlen(input);
	int i,j;int status=1;
	strlwr(input);
	char *p;p=input;
	p=&input[len-1];
	for(j=0;j<len/2;j++){
		if(input[j]!=*p){
			status=0;
			break;
		}
		p--;
	}
	if(status==1)printf("Palindrom\n");
	else printf("bukan Palindrom\n");
}
