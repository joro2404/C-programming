#include<stdio.h>
#include<string.h>

int count;
char words[10][10];

void input_words(){

	printf("broi dumi\n");
	scanf("%d", &count);
	for(int i=0;i<count;i++){
		scanf("%s", &words[i]);
	}
}

int get_letter_score(char letter){

	if(letter >='a' && letter <='z'){
		return letter-('a' -1) ;
	}else if(letter >='A' && letter <='Z'){
		return letter -'A' -1 ;
	}
	return 0;

}

int get_word_score(char word[10]){
	int score =0;
	for(int i=0;i<strlen(word);i++){
		//if(word[i] =="\0")break;
		score += get_letter_score(word[i]);
	}
	return score;
}

void find_best_word(){
	int best_word_index = 0;
	int best_word_score = 0;

	for(int i=0;i<count;i++){
		int score = get_word_score(words[i]);

		if(score > best_word_score){
			best_word_index = i;
			best_word_score = score;
		}
	}
	printf("nai-dobra duma: %s (%d)\n", words[best_word_index], best_word_score);
}

int main(){
	input_words();

	printf("broi: %d\n", count);
	for(int i=0;i<count;i++){
		printf("%s - %d\n",words[i], get_word_score(words[i]));
	}

	find_best_word();
	return 0;
}
