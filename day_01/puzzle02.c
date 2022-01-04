#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	FILE * in_file = fopen("input.txt", "r");
	if(!in_file){
		printf("no file");
		exit(-1);
	}
	int measure1 = 0;
	int measure2 = 0;
	int measure3 = 0;
	int measure4 = 0;

	char * next = NULL;

	size_t len = 0;
	size_t chars = getline(&next, &len, in_file);
	int count = 0;	

	int i = 0;
	
	while((chars=getline(&next, &len, in_file)) != EOF && i<3){
		measure3 = measure2;
		measure2 = measure1;
		measure1 = atoi(next);	
		i++;
	}
	
	while((chars=getline(&next, &len, in_file)) != EOF){
		measure4 = measure3;
		measure3 = measure2;
		measure2 = measure1;
		measure1 = atoi(next);
		
		if((measure1 + measure2 + measure3) > (measure2 + measure3 + measure4)){
			count++;
		}
	}
	printf("%d", count);
	return 0;
}
