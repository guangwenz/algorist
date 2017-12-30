#ifndef LIST_H_
#define LIST_H_

struct ListNode_;
typedef struct ListNode_ ListNode;
void list_push(ListNode ** head, void *value, size_t data_size);
void list_print(ListNode * list, void (*printfunc)(void *));
#endif