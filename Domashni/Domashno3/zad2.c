#include<stdio.h>
#include<stdlib.h>

int X_horizontal, Y_horizontal;
int X_vertical, Y_vertical;
int X_right, Y_right;
int X_left, Y_left;


void create_matrix(int n, int m[n][n]){

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			//printf("Enter number for (%d, %d) in the matrix -> ", i, j);
			scanf("%d", &m[i][j]);
		}
	}
	printf("\n");
}

void print_matrix(int n, int m[n][n]){

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ", m[i][j]);
			//scanf("%d", &m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int max_multi_horizontaly(int n, int m[n][n]){

	int max = 0;
	//int x,y;
	
	for(int i=0;i<n;i++){
		
		int current = 0;
	
		for(int j=0;j<n;j++){
			if(j < n-3)current = m[i][j] * m[i][j+1] * m[i][j+2] * m[i][j+3];
			if(current > max){
				max = current;
				X_horizontal  = j;
				Y_horizontal = i;
			}
		}
		
	}
	
	return max;
}

int max_multi_verticaly(int n, int m[n][n]){

	int max = 0;
	//int x,y;

	for(int i=0;i<n;i++){
		
		int current = 0;
		
		for(int j=0;j<n;j++){
			if(i < n-3)current = m[i][j] * m[i+1][j] * m[i+2][j] * m[i+3][j];
			if(current > max){
				max = current;
				X_vertical = j;
				Y_vertical = i;
			}
		}
	}
	
	return max;
}

int max_multi_diagonaly_right(int n, int m[n][n]){

	int max = 0;
	//int x,y;
	
	for(int i=0;i<n;i++){
	
		int current = 0;
		
		for(int j=0;j<n;j++){
			if(i < n-3 && j < n-3 )current = m[i][j] * m[i+1][j+1] * m[i+2][j+2] * m[i+3][j+3];
			if(current > max){
				max = current;
				X_right = i;
				Y_right = j;
			}
		}
	}
	
	return max;
}

int max_multi_diagonaly_left(int n, int m[n][n]){

	int max = 0 ;
	//int x,y;
	
	for(int i=0;i<n;i++){
	
		int current = 0;
	
		for(int j=0;j<n;j++){
			if(i > 2  && j < n-3)current = m[i][j] * m[i-1][j+1] * m[i-2][j+2] * m[i-3][j+3];
			if(current > max){
				max = current;
				X_left = i;
				Y_left = j;
			}
		}
	}
	
	return max;
}

int main(int argc ,char** argv) {

	int n = atoi(argv[1]);
	int m[n][n];
	
	create_matrix(n, m);
	print_matrix(n, m);
	
	int horizontal = max_multi_horizontaly(n, m);
	int vertical = max_multi_verticaly(n, m);
	int right = max_multi_diagonaly_right(n, m);
	int left = max_multi_diagonaly_left(n, m);
	
	
	if(horizontal >= vertical && horizontal >= right && horizontal >= left)printf("max is %d and has coordiantes (%d, %d) horizontal \n", horizontal, X_horizontal, Y_horizontal);
	
	if(vertical >= horizontal && vertical >= right && vertical >= left)printf("max is %d and has coordinates (%d, %d) vertical \n", vertical, X_vertical, Y_vertical);
	
	if(right >= vertical && right >= horizontal && right >= left)printf("max is %d and ahs coordinates (%d, %d) right diagonal \n", right, X_right, Y_right);
	
	if(left >= vertical && left >= horizontal && left >= right)printf("max is %d and has coordinates (%d, %d) right diagonal \n", right, X_right, Y_right);
		
	return 0;
}



















