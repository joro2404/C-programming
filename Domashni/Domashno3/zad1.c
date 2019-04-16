#include<stdio.h>
#include<math.h>

int is_prime(int n) {
	
	for(int i=2; i<n; i++) {
		float res = (float) n/i;
		//printf("%f\n", res);
		if(res == (int)res)return 0;
	}
	
	return 1;
}

int sum_digit(int n){

	int sum = 0;
	
	while(n > 0){
		sum += n%10;
		
		n = n/10;
	}
	
	return sum;
}

int main(){

	for(int i = 1; i<10001;i++){
	
		if(is_prime(sum_digit(i)) && sum_digit(i) != 1)printf("%d\n", i);
	}
	

	return 0;
}
