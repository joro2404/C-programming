#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct gun_t{
	
	char model[128];
	int accuracy;
	int ammo_capacity;


};

int get_score(int gun_accuracy, int shot_accuracy){
	if(shot_accuracy <= gun_accuracy ){
		return 10;
	}
	
	return 10 - (shot_accuracy - gun_accuracy)/((100-gun_accuracy)/10.0);
	
}

/*int gaussian_get_score(int gun_accuracy, int shot_accuracy){
	if(shot_accuracy <= gun_accuracy ){
		return 10;
	}
	float help_var = shot_accuracy - (gun_accuracy +100)/2.0;

	return 9*pow(M_E, - (help_var * help_var) / (2*(100-gun_accuracy)*(100-gun_accuracy)));
	
	opitah po gausovata formula do posledno ne mi se compilirashe zaradi problem s math.h i po tochno pow funkciqta matematicheski mislq che e pravilno. Prashtam go zadocumentirano za da moje da se compilira zadachata :)
}*/



void test_gun(struct gun_t gun, int shot_count){
	
	int points_count = 0;
	srand(time(NULL));

	for(int i=1;i<shot_count+1;i++){

		int shot_accuracy = 0 + rand()%100;
		printf("The points of shot %d is -> %d\n",i,get_score(gun.accuracy, shot_accuracy));
		//printf("The points from gaussian -> %d\n",gaussian_get_score(gun.accuracy, shot_accuracy));
		printf("Random accuracy - > %d\n", shot_accuracy);
		points_count += get_score(gun.accuracy, shot_accuracy);
	}
		
	printf("You got %d points out of %d shots\n",points_count,shot_count);
	float avrg = (float)points_count/shot_count;
	printf("Average points -> %f\n",avrg);
}

int main(){
	//int shot_accuracy;
	struct gun_t pistol;
	strcpy(pistol.model,"Glock-18");

	printf("Insert an accuracy for the gun ->");
	scanf("%d",&pistol.accuracy);

	printf("Insert a capacity for the gun ->");
	scanf("%d",&pistol.ammo_capacity);

	//printf("Insert a shot_accuracy ->");
	//scanf("%d",&shot_accuracy);

	//printf("%d\n", get_score(pistol.accuracy, shot_accuracy));
	test_gun(pistol, pistol.ammo_capacity);
	//printf("%d\n",get_score(40,36));
	
	return 0;	
	
}
