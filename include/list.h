#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>

struct ListNode_;
typedef struct ListNode_ ListNode;
void list_push(ListNode **head, void *value, size_t data_size);
void list_insert(ListNode *head, void *value, size_t data_size, bool (*compfunc)(void *));
void list_print(ListNode *head, void (*printfunc)(void *));
#endif