#include <stdio.h>

int is_digit(char digit){
    if(digit >= '0' && digit <= '9'){
        return 1;
    }
    else{
        return 0;
    }
}

int to_digit(char digit){

	int check = digit -'0';
	if(is_digit(digit)){
		return check;
	}
	else{
		return -1;	
	}
	
}

int contains(unsigned long number, char digit){
	if(is_digit(digit)){
		while(number > 0){
			if(number%10 == to_digit(digit)){
				return 1;
			}
			number = number/10;		
		}
	}
	
	return 0;
	
}

int main(){

    char digit;
	unsigned long number;
    printf("Vuvedi char -> ");
    scanf("%c",&digit);

	printf("Vuvedi number -> ");
    scanf("%lu",&number);

    printf("%d\n",is_digit(digit));
	printf("%d\n",to_digit(digit));
	printf("%d\n",contains(number, digit));
}
