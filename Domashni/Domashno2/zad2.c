#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct tree_t {
	float height;
	int age;
};

struct forest_t {
	int tree_count;
	struct tree_t trees[10];
};

struct forest_t age_trees(struct forest_t forest){

	srand(time(NULL));
	for(int i = 0; i < forest.tree_count; i++){
		forest.trees[i].age++;
		float random = rand() / (float)RAND_MAX;
		forest.trees[i].height += 0.1 + random*(2.0 - 0.1);
	}
	return forest;
}

void print_tree(struct tree_t tree){
	printf("The Tree is %d old and %f height\n", tree.age, tree.height);
}

void print_forest(struct forest_t forest){
	for(int i = 0; i < forest.tree_count; i++){
		print_tree(forest.trees[i]);
	}
}

struct forest_t cut_old_trees(struct forest_t forest, int age_treshold){
	for(int i = 0; i < forest.tree_count; i++){
		if(forest.trees[i].age > age_treshold){
			forest.trees[i].height = 0.5;
			forest.trees[i].age = 1;
			printf("A tree has been cut down!\n");
		}
	}
	return forest;
}

struct forest_t cut_tall_trees(struct forest_t forest, float height_treshold){
	for(int i = 0; i < forest.tree_count; i++){
		if(forest.trees[i].height > height_treshold){
			forest.trees[i].height = 0.5;
			forest.trees[i].age = 1;
			printf("A tree has been cut down!\n");
		}
	}
	return forest;
}


int main(int argc ,char** argv){

	struct forest_t gora;
	struct forest_t nova_gora;

	int numbers_of_repeat = atoi(argv[1]);
	int max_age = atoi(argv[2]);
	float max_height = atof(argv[3]);
	printf("Number of trees ->");
	scanf("%d",&gora.tree_count);

	//testvane na funkciite
	for(int i = 0; i < gora.tree_count; i++){
		printf("Enter an age for the tree ->");
		scanf("%d", &gora.trees[i].age);
		printf("Enter a height for the tree ->");
		scanf("%f", &gora.trees[i].height);
	}
	print_forest(gora);
	gora = age_trees(gora);
	gora = cut_old_trees(gora, max_age);
	gora = cut_tall_trees(gora, max_height);
	print_forest(gora);

	//zalesqvane na nova gora
	nova_gora.tree_count = 10;
	for(int i=0;i<nova_gora.tree_count;i++){
		nova_gora.trees[i].age = 1;
		nova_gora.trees[i].height = 0.5;
	}

	print_forest(nova_gora);
	for(int i=0;i<numbers_of_repeat;i++){
		nova_gora = age_trees(nova_gora);
		nova_gora = cut_old_trees(nova_gora, max_age);
		nova_gora = cut_tall_trees(nova_gora, max_height);
	}
	print_forest(nova_gora);

	return 0;
}
