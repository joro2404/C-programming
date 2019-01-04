#include <stdio.h>

int main(){
	char c;
	char str[15];

	//c = getchar();
	//printf("%c %d\n", c, c);

	if(fgets (str, 15, stdin)== NULL ){
		return 1;
	}
	printf("%s\n", str);

}
