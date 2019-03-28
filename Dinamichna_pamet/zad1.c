#include<stdio.h>
#include<stdlib.h>

int main() {

	int *int_arr = (int*)malloc(sizeof(int)*10);

	for(int i=0;i<10;i++){
		int_arr[i] = i+1;
	}

	for(int i=0;i<10;i++){
		printf("%d\n", int_arr[i]);
	}

	free(int_arr);

	return 0;
}
