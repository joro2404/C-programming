#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define RAND_MAX = 100

struct comment_t {

	char text[256];
	char username[256];
	char date[30];
	int upvotes;
};

struct meme_t {

	char url[256];
	char title[256];
	float rating;
	struct comment_t comments[20];
};

int main() {

	struct meme_t memes = (struct meme_t)realloc(memes, sizeof(struct meme_t));
	int number_memes = 10;
	
	for(int i=0;i<number_memes;i++){
		
		fgets(memes[i].url, 256, stdin);
		fgets(memes[i].title, 256, stdin);
		memes[i].rating = rand();
	}
	
	int max = 0;
	int id;
	
	for(int i=0;i<number_memes;i++){
	
		if(memes[i].rating > max){
		
			max = memes[i].rating;
			id = i;
		}
	}
	
	printf("%s\n", mems[id].url);
	printf("%s\n", mems[id].title);
	printf("%d\n", mems[id].rating);
	
}


