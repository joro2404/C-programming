#include <stdio.h>
#include <string.h>

struct tube_t {
	int diameter;
	int flow;	
};

struct tube_out_t {
	int diameter;
	int flow_out;
};

struct pool_t {
	int volume;
	int tube_count;
	int tube_count_out;
	struct tube_t tubes[5];
	struct tube_out_t tubes_out[5];
};

double fill_time(struct pool_t pool){
	int overall_flow;
	int overall_flow_out;

	for(int i=0;i<pool.tube_count;i++){
		overall_flow += pool.tubes[i].flow;
	}

	for(int i=0;i<pool.tube_count_out;i++){
		overall_flow_out += pool.tubes_out[i].flow_out;
	}

	if(overall_flow <= overall_flow_out){
		return -1;
	}

	return (double)pool.volume/(overall_flow - overall_flow_out);
}

int main() {

	struct pool_t pool;
	printf("Add a volume to the pool ->");
	scanf("%d", &pool.volume);
	printf("Set a number of tubes in ->");
	scanf("%d", &pool.tube_count);
	
	for(int i=0;i<pool.tube_count;i++){
		printf("For tube number %d give flow in ->",i);
		scanf("%d", &pool.tubes[i].flow);
	}
	
	printf("Set a number of tubes out ->");
	scanf("%d", &pool.tube_count_out);

	for(int i=0;i<pool.tube_count_out;i++){
		printf("For tube number %d give flow out ->",i);
		scanf("%d", &pool.tubes_out[i].flow_out);
	}

	printf("The points of time needed is %lf\n", fill_time(pool));

	return 0;
	
}
