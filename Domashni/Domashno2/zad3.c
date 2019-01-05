#include <stdio.h>
#include <string.h>

#define N 2
#define M 16

char S[N][M];

int F(char x){
	return S[0][x >> 6] + S[1][x >> 4];
}

void encrypt(char L, char R, char* out){
	for(int i = 0; i < 16; i++){
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
	for(int i = 0; i < N * M; i++)
		S[i / M][i % M] = key[i % strlen(key)];
}

void perform_encryption(char* text, char* key, char* encrypted){
	char out[2];
	init_boxes(key);

	for(int i = 0; i < (strlen(text) + 1); i += 2){
		encrypt(text[i], text[i+1], encrypted + i);
	}
}

void perform_decryption(char* encrypted, char* decrypted){
	for(int i = 0; i < (strlen(encrypted) + 1); i += 2){
		decrypt(encrypted[i], encrypted[i + 1], decrypted + i);
	}
}

int main(int argc ,char** argv) {
	char encrypted[64];
	char decrypted[64];

	perform_encryption(argv[1], argv[2], encrypted);
	printf("Encrypted string looks like ->");

	for(int i = 0;i < strlen(encrypted); i++){
		printf("%c",encrypted[i]);
	}
	
	printf("\n");

	perform_decryption(encrypted, decrypted);
	printf("Decrypted string looks like ->");

	for(int i = 0; i < strlen(decrypted); i++){
		printf("%c",decrypted[i]);
	}

	printf("\n");

	return 0;

}
