#include <stdio.h>
#include <stdlib.h>
#include "list.h"
struct ListNode_ {
	int value;
	struct ListNode_ * next;
};
ListNode * list_init(int value){
	ListNode *ret = malloc(sizeof(ListNode));
	ret -> value = value;
	ret -> next = NULL;
	return ret;
}
void list_push(ListNode * list, void *value){}
void list_isempty(ListNode * list){}
void list_print(ListNode * list){

}