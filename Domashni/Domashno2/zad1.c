#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct gun_t{
	
	char model[128];
	int accuracy;
	int ammo_capacity;


};

int get_score(int gun_accuracy, int shot_accuracy){
	if(shot_accuracy <= gun_accuracy ){
		return 10;
	}
	
	return 10 - (shot_accuracy - gun_accuracy)/((100-gun_accuracy)/10);
	
}

void test_gun(struct gun_t gun, int shot_count){
	
	float points_count = 0;
	srand(time(NULL));

	for(int i=1;i<shot_count+1;i++){

		int shot_accuracy = 0 + (rand() / (float)RAND_MAX)*100;
		printf("The points of shot %d is -> %d\n",i,get_score(gun.accuracy, shot_accuracy));
		printf("Random accuracy - > %d\n", shot_accuracy);
		points_count += get_score(gun.accuracy, shot_accuracy);
	}
		
	printf("You got %.f points out of %d shots\n",points_count,shot_count);
	float avrg = points_count/shot_count;
	printf("Average points -> %f\n",avrg);
}

int main(){
	
	struct gun_t pistol;
	strcpy(pistol.model,"Glock-18");
	printf("Insert an accuracy for the gun ->");
	scanf("%d",&pistol.accuracy);
	printf("Insert a capacity for the gun ->");
	scanf("%d",&pistol.ammo_capacity);

	test_gun(pistol, pistol.ammo_capacity);
	//printf("%d\n",get_score(40,36));
	
	
	
}
