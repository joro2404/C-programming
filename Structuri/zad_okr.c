#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

struct circle_t{
	int r;
	int center_x;
	int center_y;
};

float perimeter(struct circle_t circle){
	return 2*PI*circle.r;

}

float surface(struct circle_t circle){
	return PI*circle.r*circle.r;
}

int number_of_quadrants(struct circle_t circle){
	
}

int main(){
	
	struct circle_t krug;
	krug.r = 4;
	printf("%f\n",perimeter(krug));
	printf("%f\n",surface(krug));
}
