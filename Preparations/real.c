#include<stdio.h>
#include<stdlib.h>

int main() {

	int *a;
	int n;
	int h = 0;

	a = (int*) malloc(sizeof(int));

	while(1) {
		printf("Enter new number -> ");
		scanf("%d", &n);
		
		if(n == -33)break;
		
		else{
		
			a[h] = n;
			h++;
			a = (int*) realloc(a, h*sizeof(int));
		}
		
	}
	
	for(int i=0;i<h;i++){
		
		printf("%d ", a[i]);	
	}
	printf("\n");
	
	free(a);

	return 0;
}
