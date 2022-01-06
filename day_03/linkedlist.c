#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	int data;
	struct node *next;
};
typedef struct node node_t;

void printlist(node_t *head){
	node_t *temp = head;

	while(temp != NULL){
		printf("%d - ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	node_t n1, n2, n3;
	node_t *head;

	n1.data = 9;
	n2.data = 83;
	n3.data = 29;

	head = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = NULL;

	printlist(head);
	return 0;
}
