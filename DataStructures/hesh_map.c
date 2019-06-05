#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node_t {

	int valu;
	char* key;
};

void fun(struct node_t *node) {

	node->key = str;
}

void boo(struct node_t *node) {

	cahr str[100] = "asdf";
	fun(node, str);
}

int main() {

	struct node_t node;
	node.valu = 10;
	//strcpy(node.key, "asf");
	node.key = "asdf";
	
	printf("%d %s\n", node.valu, node.key);
	return 0;
}
