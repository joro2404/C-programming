#include <stdio.h>
#include <stdlib.h>

int POINT_COUNT = 100;

struct point_t {
	float x;
	float y;
};

int main() {

	struct point_t *my_point = (struct point_t*)malloc(sizeof(struct point_t)*POINT_COUNT);
	
	
	printf("(%.2f,%.2f)\n", my_point->x, my_point->y);

	for(int i=0;i<POINT_COUNT;i++){
		printf("(%.2f,%.2f)\n", my_point[i].x, my_point[i].y);	
	}

	return 0;
}
