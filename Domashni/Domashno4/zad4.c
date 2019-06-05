//Georg Lyubenov 10b klass nomer 10
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct product_t {
	
	char name[256];
	float quality;
	int quantity;
};

struct factory_t {

	char name[256];
	struct product_t product;
};

struct storage_t {

	int sections;
	int max_products;
	struct product_t *products;
};

// struct asd_t* function(struct asd_t *s)

struct product_t *purva(int k, struct factory_t factories[k]){

	struct product_t *n = malloc(sizeof(struct product_t)*k);
	
	for(int i=0;i<k;i++){
		
		n[i] = factories[i].product;
	}
	return n;
}

void vtora(int k, struct product_t *products, struct storage_t *storage){
	
	for(int i=0;i<k;i++){
		for(int j=0;j<storage->sections;j++){
			//printf("_|_\n");
			if(strcmp(storage->products[j].name, products[i].name) != 0){
			
				for(int z=0;z<storage->sections && products[i].quantity > 0;z++){
					//printf("%d\n", products[i].quantity - storage->max_products);
					if(!(strcmp(storage->products[z].name, "<empty>")) && products[i].quantity <= storage->max_products && products[i].quantity > 0){
					
						storage->products[z] = products[i];
						products[i].quantity = 0;
						//printf("%d", products[i].quantity);
					}
					
					else if(!(strcmp(storage->products[z].name, "<empty>")) && products[i].quantity > storage->max_products){
						//printf("%d %d", products[i].quantity, storage->max_products);
						products[i].quantity -= storage->max_products;
						storage->products[z].quantity = storage->max_products;
						strcpy(storage->products[z].name, products[i].name);
						storage->products[z].quality = products[i].quality;
						//printf("%s -> %d\n",products[i].name, products[i].quantity);
					}
					
				}
			}
			
			else if(strcmp(storage->products[j].name, products[i].name) == 0 && products[i].quality == storage->products[j].quality){
			
				//printf("asds\n");
				if(products[i].quantity <= storage->max_products - storage->products[j].quantity){
				
					storage->products[j].quantity += products[i].quantity;
					products[i].quantity = 0;
					//printf("%s -> %d\n",products[i].name, products[i].quantity);
				}
				
				else {
				
					products[i].quantity -= storage->max_products - storage->products[j].quantity;
					storage->products[j].quantity = storage->max_products;
					//printf("%s -> %d\n",products[i].name, products[i].quantity);
					
					for(int z=0;z<storage->sections && products[i].quantity > 0;z++){
					
						if(!(strcmp(storage->products[z].name, "<empty>")) && products[i].quantity <= storage->max_products && products[i].quantity > 0){
					
							storage->products[z] = products[i];
							products[i].quantity = 0;
						}
					
						else if(!(strcmp(storage->products[z].name, "<empty>")) && products[i].quantity > storage->max_products){
						
							products[i].quantity -= storage->max_products;
							storage->products[z].quantity = storage->max_products;
							strcpy(storage->products[z].name, products[i].name);
							storage->products[z].quality = products[i].quality;
						}
					}
				}
				
			}
			
			else printf("_|_\n");
			//printf("%d - %d %s\n",j+1, storage->products[j].quantity, storage->products[j].name);
		}
		
		
		
		/*if(products[i].quantity > 0){
			
			printf("There isn't any room for the remeining %d %s\n", products[i].quantity, products[i].name);
			//printf("i -> %d\n", i);
		}*/
	}
	
	for(int i=0;i<storage->sections;i++){
		
		printf("%d - %d %s\n",i+1, storage->products[i].quantity, storage->products[i].name);
	}
	
	for(int i=0;i<storage->sections;i++){
		
		if(products[i].quantity > 0){
			
			printf("There isn't any room for the remeining %d %s\n", products[i].quantity, products[i].name);
			//printf("i -> %d\n", i);
		}
	}
}

int main(int argc, char** argv){
	
	struct storage_t storage;
	
	

	int br_factories = atoi(argv[1]);
	storage.sections = atoi(argv[2]);
	storage.max_products = atoi(argv[3]);
	int iterations = atoi(argv[4]);
	char help1[256];
	char help2[256];

	storage.products = malloc(sizeof(struct storage_t)*storage.sections);
	for(int i=0;i<storage.sections;i++){
	
		strcpy(storage.products[i].name, "<empty>");
	}
	
	
	struct factory_t *factories = malloc(sizeof(struct factory_t)*br_factories);
	
	for(int i=0;i<br_factories;i++){
	
		printf("Enter factory %d:", i+1);
		scanf(" %[^,\n], %[^,\n], %[^,\n],%s", factories[i].name, factories[i].product.name, help2, help1);
		factories[i].product.quantity = atoi(help1);
		factories[i].product.quality = atof(help2);
	}
	
	
	for(int i=0;i<br_factories;i++){
	
		printf("%s produced %d %s\n", factories[i].name, factories[i].product.quantity, factories[i].product.name);
	}
	
	for(int i=0;i<iterations;i++){
	
		printf("--Iteration %d--\n", i+1);
		vtora(br_factories, purva(br_factories, factories), &storage);
		
		for(int j=0;j<storage.sections;j++){
	
			//printf("%d - %d %s\n",j+1, storage.products[j].quantity, storage.products[j].name);
		}
	}
	
	
	return 0;
}




















