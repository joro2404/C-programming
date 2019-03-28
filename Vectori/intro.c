#include <stdio.h>
#include <stdlib.h>

struct vector_t {
	int count;
	//int size;
	int *items;
};

void init(struct vector_t *vec){
	printf("Init vector\n");
	vec->count = 0;
	vec->items = (int*)malloc(sizeof(int));

}

void resize(struct vector_t *vec, int new_size) {
	printf("Resize vector to %d\n", new_size);
	vec->items = (int*)realloc(vec->items, new_size * sizeof(int));
}

void push(struct vector_t *vec, int item) {
	printf("Push item %d\n", item);
	resize(vec, vec->count +1);
	vec->items[vec->count] = item;
	vec->count++;
}

int pop(struct vector_t *vec, int *item) {
	if(vec->count <=0){
		return 0;
	}
	*item = vec->items[--vec->count];
	resize(vec, vec->count);
	//vec->count--;
	return 1;
}

int main() {

	struct vector_t my_vec;
	init(&my_vec);

	push(&my_vec, 17);
	push(&my_vec, 69);
	push(&my_vec, 86);
	//push(&my_vec, 172);
	//push(&my_vec, 256);

	int res;
	for(int i=0; i<4; i++){
		if(pop(&my_vec, &res)){
			printf("Popped %d\n", res);
		} else {
			printf("Out of items!\n\n");
		}
	}

	
	//printf("Popped %d\n", pop(&my_vec));
	//printf("Popped %d\n", pop(&my_vec));
	//printf("Popped %d\n", pop(&my_vec));
	//printf("Popped %d\n", pop(&my_vec));
	//printf("Popped %d\n", pop(&my_vec));


	return 0;
}
