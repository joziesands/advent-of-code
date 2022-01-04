#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){


FILE * in_file = fopen("input.txt", "r");

	if(! in_file){
		printf("file error");
		exit(-1);
	}
	char * next = NULL;
	int last = 0;
	size_t len = 0;
	int count = 0;
	size_t chars = getline(&next, &len, in_file);
	last = atoi(next);
	while((chars = getline(&next, &len, in_file)) != -1){
		if(atoi(next) > last){
			count += 1;
		}
		last = atoi(next);
	}
	printf("%d", count);
	fclose(in_file);
	free(next);
	return 0;
}
