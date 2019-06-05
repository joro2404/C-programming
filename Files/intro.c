#include<stdio.h>

int main() {

	FILE *fp = fopen("./out2.txt", "r");
	int f;
	
	fscanf(fp, "%d", &f);
	printf("%d\n", f);
	
	return 0;
}
