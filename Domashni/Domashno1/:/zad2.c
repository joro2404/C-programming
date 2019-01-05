#include<stdio.h>
#define max_size 33

int main(){
	char str1[max_size];
	char str2[max_size];
	char res[max_size*2+1];
	int i,j;

	printf("Vuvedi str1 -> ");
	fgets(str1, max_size, stdin);

	printf("Vuvedi str2 -> ");
	fgets(str2, max_size, stdin);

	for(i=0;str1[i]!='\n';i++){
		res[i]=str1[i];
	}

	for(j=0;str2[j]!='\n';j++){
		res[i+j] = str2[j];
	}

	res[i+j] = '\0';
	printf("%s\n",res);
}
