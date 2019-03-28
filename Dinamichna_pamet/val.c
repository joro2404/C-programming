#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {

	/*int *p = (int*)malloc(sizeof (int));
	memset(p, 0, sizeof (int));	

	printf("%d\n", *p);
	
	free (p);*/

	char name[6] = "Georgi";

	char *arr_name = (char*)malloc(sizeof(char)*6);
	
	strcpy(name, arr_name);

	for(int i=0;i<strlen(name);i++){
		printf("%c",arr_name[i]);
	}

	free(arr_name);
	return 0;
}
