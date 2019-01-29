#include <stdio.h>
#include <string.h>
#include <math.h>

#define X 10
#define Y 10 

struct cell_t {
	int x;
	int y;
	int neighbor_mine;
	int mine;
	int flag;
};

struct table_t {
	//int number_of_cells;
	int number_of_mines;
	struct cell_t cells[X][Y];
};

void create_table(struct table_t table){

	//pomoshtni promenlive za zapisvaneto na minite
	int holder_x, holder_y;

	//zapisvane na vsichki kvadratcheta
	for(int i=0;i<X;i++){
		for(int j=0;j<Y;j++){
			table.cells[i][j].x = i;
			table.cells[i][j].y = j;
			table.cells[i][j].mine = 0;
			table.cells[i][j].flag = 0;
			table.cells[i][j].neighbor_mine = 0;
			printf("%d", table.cells[i][j].flag);
		}
		printf("\n");
	}
	
	//zapisvane na koi kvadratcheta sa mini
	printf("Enter a number of mines -> ");
	scanf("%d", &table.number_of_mines);
	
	for(int i=0;i<table.number_of_mines;i++){
		printf("Enter X for mine %d -> ", i);
		scanf("%d", &holder_x);
		printf("Enter Y for mine %d -> ", i);
		scanf("%d", &holder_y);
		table.cells[holder_x][holder_y].mine += 1;
	}
}

void print_table(struct table_t table){
	for(int i=0;i<X;i++){
		for(int j=0;j<Y;j++){
			if(table.cells[i][j].flag > 0){
				printf("!");
			}
			else {
				printf("_");
			}
		}
		printf("\n");
	}
}

int main () {
	struct table_t table;
	
	create_table(table);
	print_table(table);

	return 0;
}










































