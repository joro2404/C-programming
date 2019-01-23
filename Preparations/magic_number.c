#include <stdio.h>

int if_num_is_magic(int n){
	int num = n;
	while(n>0){
		if(n%10 == 0)return 0;
		if(num % (n%10) != 0)return 0;
		n = n/10;	
	}
	
	return 1;
}

int main(){
	int num;
	scanf("%d", &num);
	printf("%d\n", if_num_is_magic(num));
	return 0;
}
