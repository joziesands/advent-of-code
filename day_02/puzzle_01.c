#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	FILE * in_file = fopen("input.txt", "r");
	size_t len = 0;
	char * next = NULL;
	if(!in_file){
		printf("no input file") ;	
		exit(-1);
	}	
	
	size_t chars;
	int vert_pos = 0;
	int hori_pos = 0;
	while((chars = getline(&next, &len, in_file)) != EOF){
		if(strpbrk(next, "f")){
			hori_pos += atoi(&next[8]);
		} else if(strpbrk(next, "u")){
			vert_pos -= atoi(&next[3]);
		} else if(strpbrk(next, "d")){
			vert_pos += atoi(&next[5]);
		}
	}
	
	printf("%d\n", vert_pos * hori_pos);
	return 0;
}

