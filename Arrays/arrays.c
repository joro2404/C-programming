#include <stdio.h>

int element(int arr[10], int n){
	
	return arr[n];

}

void put(int arr[10], int n, int index){
	arr[index] = n;

}

int count_vowels(char arr[10]){
	int count =0;
	int vowels[5] = {'a','e','i','o','u'};
	for(int i=0;i<10;i++){
		for(int j=0;j<5;j++){
			if(vowels[j] == arr[i]){
				count++;
			}		
		}
	}
	return count;
}

int delitel(int n, int m){
	if(n % m == 0){
		return 1;
	}
	else {
		return 0;
	}
}

int div_arr(int arr[], int n){
	int arr[k];
	for(int i =0;i<k;i++){
		if(delitel(arr[i],n)!= 1){
			return 0;
		}
	}
	return 1;
}


int main(){
	//input for first 3 problems 

	int n,k;
	scanf("%d\n", &n);
	scanf("%d\n",&k);
	int arr[k];
	for(int i=0;i<k;i++){
		scanf("%d",&arr[i]);	
	}
	printf("%d\n",div_arr(arr,n));
	
	//input for 4th problem

	/*int n = 20 , m=5 ;
	printf("%d\n",delitel(n,m));*/
	
	

}
