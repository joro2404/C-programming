#include<stdio.h>

int print_bits(int n){
	if(n == 0)return 0;
	return (n%2)+10*print_bits(n>>1);

}

int count_ones(int n){
	int count=0;

	n = print_bits(n);

	while(n>0){
		if(n%10 == 1)count++;
		n=(n>>1)/5;
	}
	return count;
}
int main (){
	int var = 64;
	printf("%d\n",print_bits(var));
	printf("%d\n",count_ones(var));

	printf("%d\n", var>>3);
	return 0;
}
