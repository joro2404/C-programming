#include<stdio.h>
#include<string.h>

int main(int argc, char **argv){
	
	char morse_code_letters[26][5] = {
		".-", "-...", "-.-.", "-..", ".", "..-.",
        "--.", "....", "..", ".---", "-.-", ".-..",
        "--", "-.", "---", ".--.", "--.-", ".-.", 
        "...", "-", "..-", "...-", ".--", "-..-",
        "-.--", "--..,"
        };
	char morse_code_digits[10][6] = {
		"-----\0",".----\0",
		"..---\0","...--\0", 
		"....-\0",".....\0", 
		"-....\0","--...\0", 
		"---..\0","----.\0", 
		};
	for(int i=1;i<argc;i++){
		printf("duma %d e v morzov kod kato -> ",i);
		
		for(int j=0;j<strlen(argv[i]);j++){
		
			if(argv[i][j] >= '0' && argv[i][j] <= '9'){
				printf("%s ",morse_code_digits[argv[i][j] - '0']);
			}
			else if(argv[i][j] >= 'A' && argv[i][j] <= 'Z'){
				printf("%s ",morse_code_letters[argv[i][j] - 'A']);
			}
			else if(argv[i][j] >='a' && argv[i][j] <= 'z'){
				printf("%s ",morse_code_letters[argv[i][j] - 'a']);
			}		
		}
		
		printf("\n");
	}

}
