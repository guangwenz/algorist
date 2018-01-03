#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
struct ListNode_ {
	void *data;
	struct ListNode_ *next;
};

void list_push(ListNode ** head, void *value, size_t data_size) {
	ListNode *ret = malloc(sizeof(ListNode));
	ret -> data = malloc(data_size);
	ret -> next = *head;

	memcpy(ret -> data, value, data_size);
	*head = ret;
}

/**
insert data into list before selected node
*/
void list_insert(ListNode *head, void *value, size_t data_size, bool (*compfunc)(void *)) {
	ListNode *node = head;
	while(node != NULL){
		if(compfunc(node -> data)) {
			ListNode *newnode = malloc(sizeof(ListNode));
			newnode -> data = malloc(sizeof(data_size));
			memcpy(newnode -> data, value, data_size);

			newnode -> next = node -> next;
			node -> next = newnode;
			break;
		}
		node = node -> next;
	}
}

void list_print(ListNode * head, void (*printfunc)(void *)) {
	ListNode *node = head;
	while(node!=NULL){
		printfunc(node -> data);
		node = node -> next;
	}
}