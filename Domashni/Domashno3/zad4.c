#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct process_t{
	
	int id;
	int period;
};

struct processor_t {
	
	int total_time;
	int total_processes;
	int id;
	struct process_t *processes;
};

int smallest(struct processor_t *arr, int n){
	
	int s = arr[0].total_time;
	int index = 0;
	
	for(int i=0;i<n;i++){
		
		if(arr[i].total_time < s){
			
			s = arr[i].total_time;
			index = i;
		}
	}
	
	return index;
}

int main (){
	
	int n = 4;
	
	struct processor_t arr[n] ;
	
	for(int i=0;i<n;i++){
		
		arr[i].total_time = 0;
		arr[i].total_processes = 0;
		arr[i].id = i;
		arr[i].processes = malloc(sizeof(struct process_t));
	}
	
	char input[100];
	int count = 0;
	
	do{
		
		for(int i=0;i<5;i++){
			
			fgets(input, 100, stdin);
			
			if(strcmp(input, "exit") <= 0){
				
				int h = atoi(input);
				int index = smallest(arr, n);
				count ++;
				
				arr[index].total_time += h;
				arr[index].total_processes ++;
				
				arr[index].processes[arr[index].id].id = count;
				arr[index].processes[arr[index].id].period = h;
			}
			
			else{
				break;
			}
		}
			
		if(strcmp(input, "exit") <= 0){
				
			for(int i=0;i<n;i++){
					
				printf("Queue for processor %d: %d. Total time: %d\n", i+1, arr[i].total_processes, arr[i].total_time);
				
			}
		}
		
		
	}while(strcmp(input, "exit") <= 0);
	
	for(int i=0;i<n;i++){
	
		free(arr[i].processes);
	}
	
	return 0;
}
