#include<stdio.h>
#include<string.h>

int is_fingerprint_row_valid(char fingerprint[20]){
	char *symbols = "-/~\\|_";	
	if(strlen(fingerprint)!=16){
		return 0;
	}
	for(int i=0;i<strlen(fingerprint);i++){
		for(int j=0;j<strlen(symbols);j++){
			if(fingerprint[i] == symbols[j]){
				break;
			}
			if(fingerprint[i] != symbols[j]){
				if(j==5)return 0;
			}
		}
	}
	return 1;
}

int main(int argc , char **argv){
	for(int i=1;i<argc;i++){
		printf("for fingerprint %d -> %d\n",i,is_fingerprint_row_valid(argv[i]));
	}
	return 0;
}
