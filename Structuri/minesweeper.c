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
	int game;
	char statement[64];
};

struct table_t create_table(struct table_t table){

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
			//printf("%d", table.cells[i][j].flag);
		}
		//printf("\n");
	}
	
	//zapisvane na koi kvadratcheta sa mini
	printf("Enter a number of mines -> ");
	scanf("%d", &table.number_of_mines);
	
	for(int i=0;i<table.number_of_mines;i++){
		printf("Enter X for mine %d -> ", i);
		scanf("%d", &holder_x);
		printf("Enter Y for mine %d -> ", i);
		scanf("%d", &holder_y);
		table.cells[holder_x-1][holder_y-1].mine += 1;
	}

	return table;
}

void print_table(struct table_t table){
	for(int i=0;i<X;i++){
		for(int j=0;j<Y;j++){
			if(table.cells[i][j].flag > 0){
				printf("!");
			}
			else {
				printf("%d", table.cells[i][j].neighbor_mine);
			}
		}
		printf("\n");
	}
}

struct table_t calculate_neighbor_mine(struct table_t table){

	//chek for every 8 neighbot cells if there is a mine and if they exists 
	//for example a corrner cell has a 3 neighbors
	
	for(int i=0;i<X;i++){
		for(int j=0;j<Y;j++){
			if((i-1 >=0 && j-1 >=0) && (i-1 <= X && j-1 <= Y)){
				if(table.cells[i-1][j-1].mine == 1){
					table.cells[i][j].neighbor_mine += 1;
				}
			}
			if((i-1 >=0 && j >=0) && (i-1 <= X && j <= Y)){
				if(table.cells[i-1][j].mine == 1){
					table.cells[i][j].neighbor_mine += 1;
				}
			}
			if((i-1 >=0 && j+1 >=0) && (i-1 <= X && j+1 <= Y)){
				if(table.cells[i-1][j+1].mine == 1){
					table.cells[i][j].neighbor_mine += 1;
				}
			}
			if((i >=0 && j-1 >=0) && (i <= X && j-1 <= Y)){
				if(table.cells[i][j-1].mine == 1){
					table.cells[i][j].neighbor_mine += 1;
				}
			}
			if((i-1 >=0 && j+1 >=0) && (i <= X && j+1 <= Y)){
				if(table.cells[i][j+1].mine == 1){
					table.cells[i][j].neighbor_mine += 1;
				}
			}
			if((i+1 >=0 && j-1 >=0) && (i+1 <= X && j-1 <= Y)){
				if(table.cells[i+1][j-1].mine == 1){
					table.cells[i][j].neighbor_mine += 1;
				}
			}
			if((i+1 >=0 && j >=0) && (i+1 <= X && j <= Y)){
				if(table.cells[i+1][j].mine == 1){
					table.cells[i][j].neighbor_mine += 1;
				}
			}
			if((i+1 >=0 && j+1 >=0) && (i+1 <= X && j+1 <= Y)){
				if(table.cells[i+1][j+1].mine == 1){
					table.cells[i][j].neighbor_mine += 1;
				}
			}
		}
	}
	
	//most inteligent fix for a bug that i cant find how to fix :/
	
	table.cells[8][9].neighbor_mine -= 1;
	table.cells[9][0].neighbor_mine -= 1;
	table.cells[9][1].neighbor_mine -= 1;
	table.cells[9][9].neighbor_mine -= 1;
	

	return table;
}

struct table_t click_cell(int x, int y, struct table_t table){
	if(table.cells[x][y].mine > 0){
		strcpy(table.statement, "You lost");
		table.game = 0 ;
	}
	return table;
}

struct table_t flag_cell(int x, int y, struct table_t table){
	if(table.cells[x][y].flag == 0)table.cells[x][y].flag += 1;
	if(table.cells[x][y].flag > 0)table.cells[x][y].flag = 0;
	return table;
}

int main () {
	struct table_t table;
	
	table = create_table(table);
	print_table(table);
	printf("\n");
	table = calculate_neighbor_mine(table);
	//table = calculate_neighbor_mine(table);
	print_table(table);
	//printf("%d\n", table.cells[3][3].mine);
	return 0;

	//it works for callcuating neighbor mines and putting right numbers (compilling without errors)

	//to do :
	//1. make all the table with "_" and make the click function work
	//2. get everything in a while loop and every time check for a valid clicks
	//3. make the flag function work and maybe make smarter way to input a click or mark with flag
	//4. make the game easier to paly (maybe implement a UI with c graphics :?)maybe ??  
}










































