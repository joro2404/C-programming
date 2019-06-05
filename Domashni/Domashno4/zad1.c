//Georg Lyubenov 10b klass nomer 10
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {

	char str[200];
	fgets(str, 200, stdin);
	int curr = 0;
	int res = 1;
	int best_len = -1;
	int check = 0;
	
	for(int i=0;i<strlen(str);i++){
		
		if((str[i] >= 'a' && str[i] <= 'z')||(str[i] >= 'A' && str[i] <= 'Z') || str[i] == '-' || str[i] == '\''){
			
			if(check == 0){
				curr++;
			}
			//printf("%c - %d\n", str[i], curr);
		}
		
		else if(str[i] == ' '){
			check = 0;
			
			if(curr == best_len){
				//printf("%d\n", curr);
				curr = 0;
				res++;
				//printf("%d\n", res);
				
			}
			
			else if(curr > best_len){
				best_len = curr;
				curr = 0;
				res = 1;
			}
			
			else{
				curr = 0;
			}
		}
		
		else {
		
			curr = 0;
			check = 1;
		}
	}
	
	
	printf("Number of longest words: %d\n", res);
	
	return 0;
}
