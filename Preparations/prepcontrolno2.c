#include <stdio.h>
#include <string.h>

struct gun_t {
	char model[128];
	int ammo_capacity;
	float accuracy;
	char material[128];

};

struct funct(struct gun_t gun){
	gun.accuracy =5;
	return gun;
}
//pistol = funct(pistol)


//void funct(struct gun_t* gun);
//funct(&pistol);

struct one_t {
	int v;
}

struct two_t {
	int v;
	struct one_t one;
}

struct three_t {
	int v;
	struct two_t two;
}




int main() {

	struct gun_t pistol;
	strcpy(pistol.model, "colt");
	pistol.ammo_capacity = 7;
	pistol.accuracy = 0.5;
	strcpy(pistol.material, "carbon");

	struct other_gun;
	other_gun.accuracy = pistol.accuracy;
	strcpy(other_hun.model, pistol.model);

	struct one_t one;
	struct two_t two;
	struct three_t three;

	int i = 5;
	printf("%d\n", i++);
	printf("%d\n", ++i);
	return 0;
}
