//Georg Lyubenov 10b klass nomer 10
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int Time = 0;

int kachvane(int vagoni[4], int n){
	int putnici,res=0;

	for(int i=0;i<4;i++){
		
		scanf("%d", &putnici);
		Time += putnici;
		if(vagoni[i] + putnici > n){
			res += vagoni[i] + putnici - n;
			vagoni[i] = n;
		}
		else {
			vagoni[i] += putnici;
		}
	}
	
	if(res > 0)printf("There wasn't room for %d passengers\n", res);

	return res;
}

void slizane(int vagoni[4]){
	int putnici;
	
	for(int i=0;i<4;i++){
		
		scanf("%d", &putnici);
		Time += putnici;
		vagoni[i] -= putnici;
	}

}

int main(int argc, char** argv){
	
	int n = atoi(argv[1]);
	int all_left = 0;
	int vagoni[4];
	
	for(int i=0;i<4;i++){
		vagoni[i] = 0;
	}
	
	for(int i=0;i<4;i++){
	
		all_left += kachvane(vagoni, n);
		//printf("// %d %d %d %d\n", vagoni[0], vagoni[1], vagoni[2], vagoni[3]);
		slizane(vagoni);
		//printf("// %d %d %d %d\n", vagoni[0], vagoni[1], vagoni[2], vagoni[3]);
	}
	all_left += kachvane(vagoni, n);
	//printf("// %d %d %d %d\n", vagoni[0], vagoni[1], vagoni[2], vagoni[3]);
	
	//printf("%d - %d\n", Time, all_left);
	
	printf("Total wait time: %d\n", Time - all_left);
	
	return 0;
}








