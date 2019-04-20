#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct process_t {
	
	int id;
	int time;
};

struct processor_t {
	
	int total_processes;
	int total_time;
	struct process_t *processes;
};

int smallest(struct processor_t *p, int n){
	
	int s = p[0].total_time;
	int index = 0;
	
	for(int i=0;i<n;i++){
		
		if(p[i].total_time < s){
		
			s = p[i].total_time;
			index = i;
		}
	}
	
	return index;
}

int main(int artc, char** argv){

	int n = atoi(argv[1]);

	struct processor_t arr[n];
	
	for(int i=0;i<n;i++){
		
		arr[i].total_processes = 0;
		arr[i].total_time = 0;
		arr[i].processes = malloc(sizeof(struct process_t));
	}
	
	char *input;
	
	while(strcmp(input, "exit")){
	
		for(int i=0;i<5;i++){
		
			scanf("%s", &input);
			
			if(strcmp(input, "exit")){
				
				int h = atoi(input);
				int k = smallest(arr, n);
				
				arr[k].total_time += h;
				arr[k].total_processes += 1;
				
			}
		}
		
		for(int i=0;i<n;i++){
			
			printf("Queue for processor %d: %d, Total time : %d", i+1, arr[i].total_processes, arr[i].total_time);
		}
	}

	return 0;
}






















