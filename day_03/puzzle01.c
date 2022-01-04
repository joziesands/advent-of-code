#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	FILE * in_file = fopen("input.txt", "r");

	if(!in_file){
		printf("file error");
		exit(-1);
	}
	
	char * next = NULL;
	size_t len = 0;
	size_t chars;

	int epsilon = 0;
	int gamma = 0;
	int ones[12] = {};
	int zeros[12] = {};
	chars = getline(&next, &len, in_file);
	
	while((chars = getline(&next, &len, in_file)) != EOF){
		for(int i = 0; i < 12; i++){
			if((int)(next[i]) == 49){
				ones[i]++;
			}else{
				zeros[i]++;
			}				
		}
	}

	for(int i = 0; i<12; i++){
		gamma = gamma<<1;
		epsilon = epsilon<<1;
		if(ones[i] > zeros[i]){
			gamma += 1;
		}else{
			epsilon += 1;
		}

	}
	printf("%d\n%d\n%d", gamma, epsilon, gamma*epsilon);
	return 0;
}
