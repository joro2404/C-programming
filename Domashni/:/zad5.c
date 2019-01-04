#include<stdio.h>
#include<string.h>

int string_compare(char *str1, char *str2){
	for(int i=0;i<strlen(str1);i++){
		if(str1[i] != str2[i]){
			if(str1[i] > str2[i]){
				return 1;
			}
			if(str1[i] < str2[i]){
				return -1;
			}
		}
	}
	return 0;
}

int main(){
	printf("Compearing two equal strings -> %d\n", string_compare("asd","asd"));
	printf("Compearing two strings with different letters -> %d\n", string_compare("asq","asd"));
	printf("Compearing two strings with different letters -> %d\n", string_compare("asd","asq"));
	return 0;
}
