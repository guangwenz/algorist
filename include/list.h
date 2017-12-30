#ifndef LIST_H_
#define LIST_H_

struct ListNode_;
typedef struct ListNode_ ListNode;
ListNode * list_init(int size);
void list_push(ListNode * list, void *value);
void list_isempty(ListNode * list);
void list_print(ListNode * list);
#endif