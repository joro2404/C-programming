#include <stdio.h>
#include <string.h>

int main(){
	//explanation of string
	//int arr1[] = {1, 2, 3};
	//char arr2[] = {'a','b','c'};
	//int arr3[] = {'a','b','c'};

	//printf("%d %c\n", arr2[0], arr2[0]);
	
	//char arr6[] = {'a','b','c','\0','d','e'};
	
	//printf("%d\n",strlen(arr6));

	//----------------------------------


	//strcat
	//char str1[]="abc";
	//char str2[] = "def";

	
	//ne raboti
	//char str3[] = strcat(str1, str2);

	//printf("%s\n", str3);

	//----------------------------------

	//strcmp + strcpy
	char str1[] = "abc";
	char str2[] = "abc";
	char str3[] = "bcd";
	char str4[] = "1ab";

	printf("%d\n", strcmp(str1, str4));
	strcpy(str1, str4);
	printf("%d\n",strcmp(str1, str4));

	//----------------------------------
	
	

	
	return 0;

}
