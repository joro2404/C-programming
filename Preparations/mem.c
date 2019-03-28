#include<stdio.h>
#include<stdlib.h>

int main() {
	int n;
	
	printf("enter lenght of an array -> ");
	scanf("%d", &n);
	
	int *a = (int*) calloc(n, sizeof(int));
	
	/*
	for(int i=0;i<n;i++){
		
		a[i] = i+1;
	}
	*/
	
	free(a);

	for(int i=0;i<n;i++){
		
		printf("%d ", a[i]);
	}
	
	printf("\n");
	
	return 0;
}	
