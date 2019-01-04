#include<stdio.h>

float find_average__digit(unsigned long number){
	int sum =0;
	//int avg = 0;
	int count = 0;
	while(number >= 10){
		int digit = number %10;
		sum	+= digit;
		count++;
		number /= 10;
	}
	
	return sum / count ;
}

/*
int find_largest_difference(int arr[10]){
	int largest = 0;
	int smallest = 0;
	
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			int dif = arr[i] - arr[j];
			if(diff > largest_diff)largest_diff = diff;
		}
	}
	
	return largest_diff;

}
*/

int main(){
	int n;
	
	scanf("%d",&n);
	printf("%f\n",find_average__digit(n));
	
	
}
