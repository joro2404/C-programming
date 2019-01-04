#include<stdio.h>

int is_even(int n){
	return n%2==0;
}

int is_odd(int n){
	return n%2 != 0;
}

int sumi(int n, int m){
	return n+m;
}

int multi(int n, int m){
	int res =0;
	for(int i=0;i<m;i++){
		res +=sumi(0,n);
	}
	return res;
}


int step(int n, int m){
	int res =1;
	for(int i=0;i<m;i++){
		res	*= multi(1,n);
	}
	return res;
}

int kvadrat(int n){
	return step(n,2);
}

int prime(int n){
	for(int i=0;i<n;i++){
		if(n%i == 0)return 0;	
	}
	return 1;
}

int fib(int n){
	if(n<=2)return 1;
return fib(n-1)+fib(n-2);	

}




int main() {
	int n;
	//printf("Insert number to check if it is even->");
	//scanf("%d",&n);
	//printf("%d\n",is_even(n));
	//printf("%d\n",is_odd(n));
	printf("%d\n", fib(7));

	return 0;
}
