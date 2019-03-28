#include<stdio.h>
#include<stdlib.h>

char S[10][10];

int main (){
	int x, y, l;
	
	printf("\nEnter x -> ");
	scanf("%d", &x);
	printf("Enter y -> ");
	scanf("%d", &y);
	printf("Enter length -> ");
	scanf("%d", &l);
	
	
	for(int i=1; i<11;i++){
		for(int j=1;j<11;j++){
			if(j >= x && j-x+1<=l && i>=y && i-x+1<=l){
				S[i][j] = 'O';
				printf("%c", S[i][j]);
			}
			else{
				S[i][j] = '.';
				printf("%c", S[i][j]);
			}
		}
		printf("\n");
	}
	
	return 0;
}
