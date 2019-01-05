#include <stdio.h>
#include <string.h>

#define N 2
#define M 16

char S[N][M];

int F(char x){
	return S[0][x >> 6] + S[1][x >> 4];
}

void encrypt(char L, char R, char* out){
	for(int i=0;i<16;i++){
		R ^= F(L);
		L ^= F(R);
	}
	out[0] = R;
	out[1] = L;
}

void decrypt(char L, char R, char *out){
	encrypt(L, R, out);
}

void init_boxes(char *key){
	for(int i=0;i<N*M;i++)
		S[i / M][i % M] = key[i % strlen(key)];
}

void perform_encryption(char* text, char* key, char* encrypted){
	char out[2];
	init_boxes(key);

	/*for(int i=0;i<strlen(S[0]);i++){
		printf("%c",S[0][i]);	
	}
	printf("\n");
	for(int i=0;i<strlen(S[1]);i++){
		printf("%c",S[1][i]);	
	}
	printf("\n");*/

	for(int i=0;i<(strlen(text)+1);i+=2){
		encrypt(text[i], text[i+1], out);
		encrypted[i] = out[0];
		encrypted[i+1] = out[1];
		//printf("%d\n",i);
	}
}

void perform_decryption(char* encrypted, char* decrypted){
	char out[2];

	for(int i=0;i<(strlen(encrypted)+1);i+=2){
		decrypt(encrypted[i], encrypted[i+1], out);
		decrypted[i] = out[0];
		decrypted[i+1] = out[1];
	}
}

int main(int argc ,char** argv) {
	//text = argv[1];
	//key = argv[2];
	char encrypted[64];
	char decrypted[64];
	
	perform_encryption(argv[1], argv[2], encrypted);
	printf("Encrypted string looks like ->");
	for(int i=0;i<strlen(encrypted);i++){
		printf("%c",encrypted[i]);
	}
	printf("\n");

	perform_decryption(encrypted, decrypted);
	printf("Decrypted string looks like ->");
	for(int i=0;i<strlen(decrypted);i++){
		printf("%c",decrypted[i]);		
	}
	printf("\n");

	return 0;

}














