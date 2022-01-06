#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	FILE * in_file = fopen("input.txt", "r");
	if(!in_file){
		printf("file error");
		exit(-1);
	}	
	
	struct node{
		int data;
		struct node *next;
	}

	struct node *head = NULL;
	struct node *current = NULL;

	char * next = NULL;
	size_t len = 0;
	size_t chars;

	int epsilon = 0;
	int gamma = 0;
	int ones[12] = {};
	int zeros[12] = {};
	chars = (getline(&next, &len, in_file));

 	while((chars = getline(&next, &len, in_file)) != EOF){
		// update column tallies
		for(int i = 0; i < 12; i++){
			if((int)(next[i]) == 49){
				ones[i]++;
			}else{
				zeros[i]++;
			}
		}
		// add next to linked list
	}	

	


	return 0;
}
