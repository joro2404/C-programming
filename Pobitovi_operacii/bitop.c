#include<stdio.h>

int print_bits(int n){
	if(n == 0)return 0;
	return (n%2)+10*print_bits(n/2);

}

int count_ones(int n){
	int count=0;

	n = print_bits(n);

	while(n>0){
		if(n%10 == 1)count++;
		n=n/10;
	}
	return count;
}
int main (){
	
	printf("%d\n",print_bits(16));
	printf("%d\n",count_ones(16));
	return 0;
}
