#include <stdio.h>
#include <string.h>

int is_valid_mac(char mac[20]){

	char *mac_contains = "0123456789abcdef";

	if(strlen(mac) != 17){
		return 0;
	}
	for(int i=0;i<strlen(mac);i++){
		if(i%3 == 2){
			if(mac[i] != ':')return 0;
		}
		if(i%3 == 1 || i%3 == 0){
			for(int j=0;j<strlen(mac_contains);j++){
				if(mac[i] == mac_contains[j]){
					break;
				}
				if(mac[i] != mac_contains[j]){
					if(j == 15)return 0;
				}
			}
		}
	}
	
	return 1;
}

int main(int argc, char **argv) {

	if(is_valid_mac(argv[1]) > 0 ){
		printf("Valid Mac address\n");
	}
	
	else {
		printf("Not valid Mac address\n");
	}
	return 0;	
}
