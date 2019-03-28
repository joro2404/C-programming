#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stack_t {
	int *items;
	int count;
};

int pop(struct stack_t *the_stack){

	printf("Element has been poped!");
	int popped_item = the_stack->items[--the_stack->count];
	the_stack->items = (int*)realloc(the_stack->items, sizeof(int)*(the_stack->count));
	return popped_item;	
}

void push(struct stack_t *the_stack, int item){

	printf("Element has been pushed!\n");
	the_stack->items = (int*)realloc(the_stack->items, sizeof(int)*(the_stack->count+1));
	the_stack->count++;
	the_stack->items[the_stack->count - 1] = item;
}

void init(struct stack_t *the_stack){

	printf("Init the steck!\n");
 	the_stack->count = 0;
	//the_stack->items = malloc(???);
	the_stack->items = NULL;
}

void destroy_stack(struct stack_t *the_stack){

	printf("The steck has been destroyed!\n");
	free(the_stack->items);
	//free(the_stack);
}


int main() {

	struct stack_t steck;
	init(&steck);
	
	push(&steck, 4);
	push(&steck, 24);
	push(&steck, 42);
	
	int count = steck.count;
	for(int i =0; i<count; i++){
		printf("(Element with value: %d)\n", pop(&steck));
	}
	
	destroy_stack(&steck);
	
	return 0;
}























