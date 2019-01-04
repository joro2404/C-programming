#include<stdio.h>
#include<string.h>

int to_integer(char *str){
	int help = 0;
	for(int i=0;i<strlen(str);i++){
		help = help*10 + (str[i] - '0');
	}
	return help;
}

int main(int argc, char **argv){
	int sum = 0;
	
	for(int i=1;i<argc;i++){
		sum += to_integer(argv[i]);
	}
	
	printf("The sum is -> %d\n",sum);
}
