#include <stdio.h>
#include <string.h>

struct product_t {
	char name[50];
	double price;
	int quantity;
};

struct shop_t {
	char shop_name[20];
	double earnings;
	int product_count;
	struct product_t products[100];
};

void buy_products(struct shop_t shop, char product_name, int product_count){
	double profit;
	
	for(int i=0;i<shop.product_count;i++){
		int check = strcmp(product_name, shop.products[i].name);
		if(check == 0){
			
			if(product_count > shop.products[i].quantity){
				product_count = shop.products[i].quantity;	
			}	
			
			profit = (double)product_count*price;
		}
	}
}

int main() {

}
