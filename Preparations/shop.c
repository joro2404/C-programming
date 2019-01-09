#include <stdio.h>
#include <string.h>

struct product_t {
	char name[20];
	double price;
	int quantity;
};

struct shop_t {
	char shop_name[20];
	double earnings;
	int product_count;
	struct product_t products[100];
};

void buy_products(struct shop_t shop, char* product_name, int product_count){

	for(int i=0;i<shop.product_count;i++){
		//printf("\n%d\n", strcmp(product_name, shop.products[i].name));
		//for(int j=0;j<strlen(shop.products[i].name);j++){
			//printf("%c", shop.products[i].name[j]);
		//}

		if(strcmp(product_name, shop.products[i].name) == 0){
			//printf("1\n");
			if(product_count > shop.products[i].quantity){
				product_count = shop.products[i].quantity;	
			}	
			
			shop.earnings += (double)product_count*shop.products[i].price;
			shop.products[i].quantity -= product_count;

		}
	}
}

int main(){
    struct shop_t shop;
    strcpy(shop.shop_name,"Lidl");
    shop.earnings = 1250.50;
    shop.product_count = 3;

    strcpy(shop.products[1].name,"Cookies");
    shop.products[1].price = 1.5;
    shop.products[1].quantity = 20;

    strcpy(shop.products[2].name,"Bread");
    shop.products[2].price = 1;
    shop.products[2].quantity = 50;

    strcpy(shop.products[3].name,"Apple");
    shop.products[3].price = 0.5;
    shop.products[3].quantity = 100;
    
	buy_products(shop, "Bread", 4);
	printf("%lf\n", shop.earnings);
    return 0;
}
