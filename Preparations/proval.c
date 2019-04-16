#include<stdio.h>
#include<string.h>

int main1 () {
	
	char str[20];
	
	fgets(str, 250, stdin);
	
	int counter = 0, longest = 0;
	
	for(int i=0; i < strlen(str); i++){
		if(str[i] >= 'A' && str[i] <= 'Z'){
			counter = 0;
			int j = i;
			for(int j =0; (str[j] <= 'a' && str[j] <= 'z') || (str[j] >= 'A' && str[j] <= 'Z'); j++){
				counter ++;
			}
			i=j;
			if(longest < counter) longest = counter;
		}
	}
	
	printf("Longest is %d\n", longest);
	
	return 0;
}

int main () {

	char str[20];
	
	fgets(str, 250, stdin);
	
	int counter = 0, longest = 0;
	int is_in_word = 0;
	
	for(int i=0; str[i] != '\0';i++){
		if(str[i] >= 'A' && str[i] <= 'Z'){
			is_in_word = 1;
		}
		
		if(is_in_word && is_letter(str[i])) {
			counter++
		} else {
			is_in_word
		}
	}
	
	
	return 0;
}
