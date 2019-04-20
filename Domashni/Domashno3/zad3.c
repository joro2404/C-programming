#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct process_t{

	char source[32];
	char destination[32];
	char content[255];
};


struct buffer_t{

	struct process_t processes[10];
};



void bubbleSort(struct buffer_t *buffer, int n) 
{ 
   int i, j; 
   char temp[255];
   for (i = 0; i < n-1; i++)       
    
       for (j = 0; j < n-i-1; j++)  
           if(strlen(buffer->processes[j].content) > strlen(buffer->processes[j+1].content)){
           		strcpy(temp, buffer->processes[j].content);
           		strcpy(buffer->processes[j].content, buffer->processes[j+1].content); 
           		strcpy(buffer->processes[j+1].content, temp);
           		strcpy(temp, buffer->processes[j].source);
           		strcpy(buffer->processes[j].source, buffer->processes[j+1].source); 
           		strcpy(buffer->processes[j+1].source, temp);
           		strcpy(temp, buffer->processes[j].destination);
           		strcpy(buffer->processes[j].destination, buffer->processes[j+1].destination); 
           		strcpy(buffer->processes[j+1].destination, temp);
           }
} 


int main() {

	struct buffer_t buffer;

	while(1){
	
		for(int i=0;i<10;i++){
			
			scanf("%s", buffer.processes[i].source);
			scanf("%s", buffer.processes[i].destination);
			getchar();
			fgets(buffer.processes[i].content, 255, stdin);
		}
		
		bubbleSort(&buffer, 10);
		
		printf("\n");
		
		for(int i=0;i<10;i++){
			
			printf("From : %s ", buffer.processes[i].source);
			printf("To : %s ", buffer.processes[i].destination);
			printf("Content : %s", buffer.processes[i].content);
		}
		
		printf("\nPress Ctrl+C for exit :)\n");
	}

	return 0;
}

