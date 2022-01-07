#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	int data;
	struct node *next;
};
typedef struct node node_t;

// create node
node_t *create_node(int data){
	node_t *new_node = malloc(sizeof(node_t));	
	new_node->data = data; 
	new_node->next = NULL;
	return new_node;
}

node_t *insert_at_head(node_t **head, node_t *new_node){
	new_node->next = *head;
	*head = new_node;
	return new_node;
}

node_t *insert_at_tail(node_t **head, node_t *new_node){
	node_t *tail = *head;
	while(tail->next != NULL){
		tail = tail->next;
	}
	new_node->next = NULL;
	tail->next = new_node;
	return new_node;
}

node_t *find_node(node_t *head, int value){
	node_t *temp = head;
	while(temp != NULL){
		if(temp->data == value){
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}

void printlist(node_t *head){
	node_t *temp = head;

	while(temp != NULL){
		printf("%d - ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	node_t *head = NULL;
	node_t *temp;

	temp = create_node(32);
	insert_at_head(&head, temp);
	temp = create_node(15);
	insert_at_head(&head, temp);
	temp = create_node(40);
	insert_at_tail(&head, temp);
	temp = create_node(35);
	insert_at_tail(&head, temp);
	printlist(head);

	temp = find_node(head, 40);
	printf("found value %d\n", temp->data);
	return 0;
}
