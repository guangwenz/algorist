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

void list_print(ListNode * list, void (*printfunc)(void *)) {
	while(list!=NULL){
		printfunc(list -> data);
		list = list -> next;
	}
}