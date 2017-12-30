#include <stdio.h>
#include "list.h"

void print_int(void *data) {
	int value = *(int *) data;
	printf("%d\n", value);
}
void print_long(void *data) {
	long value = *(long *) data;
	printf("%ld\n", value);
}

int main(int argc, char const *argv[])
{
	ListNode * ints = NULL;
	int v1 = 10;
	int v2 = 9;
	int v3 = 7;
	list_push(&ints, &v1, sizeof(int));
	list_push(&ints, &v2, sizeof(int));
	list_push(&ints, &v3, sizeof(int));
	list_print(ints, print_int);

	ListNode * longs = NULL;
	long l1 = 1;
	long l2 = 2;
	long l3 = 3;
	long l4 = 4;
	list_push(&longs, &l1, sizeof(long));
	list_push(&longs, &l2, sizeof(long));
	list_push(&longs, &l3, sizeof(long));
	list_push(&longs, &l4, sizeof(long));
	list_print(longs, print_long);

	return 0;
}