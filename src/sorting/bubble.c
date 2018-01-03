#include <stdio.h>
#include <stdbool.h>

/**
best O(n), avg: theta(n^2), worst: O(n^2)
*/

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void sort(int arr[], int n) {	
	for (int i=0; i<n; i++) {
		bool swapped = false;		
		for(int j = 1; j < n - i; j++ ) {
			if(arr[j-1] > arr[j]) {
				swap(&arr[j-1], &arr[j]);
				swapped = true;
			}
		}
		if(!swapped) break;
	}
}

void print_array(int arr[], int n) {
	for (int i=0;i<n;i++){
		printf("%d\n", arr[i]);
	}
}

/**
input, first number is the list length.
then the list items.
*/
int main(int argc, const char *argv[]) {
	int size;
	scanf("%d", &size);
	int list[size];
	for(int i=0;i<size;i++){
		scanf("%d", &list[i]);
	}
	sort(list, size);
	print_array(list,size);
	return 0;
}