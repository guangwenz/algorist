#include <stdio.h>

/**
Best: O(n^2), AVG: O(n^2), Worst: theta(n^2)
*/

void print_array(int arr[], int l, int r){
	for(int i=l; i<r; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void swap(int * a, int * b) {
	int temp = *a;
	* a = * b;
	* b = temp;
}

void sort(int arr[], int n) {
	int i,j;
	for (i = 0; i < n; i++ ){
		int min_idx = i;
		for(j=i+1;j<n;j++){
			if(arr[j] < arr[min_idx]) {
				min_idx = j;
			}
		}
		if(min_idx != i) {
			swap(&arr[min_idx], &arr[i]);
		}
	}
}

int main(int argc, const char * argv[]) {
	int size;
	scanf("%d", &size);
	int arr[size];
	for(int i=0;i<size;i++) {
		scanf("%d", &arr[i]);
	}
	printf("%s\n", "before sort");
	print_array(arr, 0, size);
	printf("%s\n", "after sort");
	sort(arr, size);
	print_array(arr, 0, size);
	return 0;
}