#include <stdio.h>
/**
Best: O(nlgn), AVG: theta(nlgn), Worst: O(n^2)
*/

void print_array(int arr[], int l, int r){
	for(int i=l; i<r; i++){
		printf("%d \n", arr[i]);
	}
}

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int l, int r) {
	int pivot = arr[r];
	int i = l - 1;
	for (int j = l; j <= r - 1; j++)
	{
		if(arr[j] <= pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[r]);
	return i+1;
}

void sort(int arr[], int l, int r) {
	if(l < r){
		int m = partition(arr, l, r);
		sort(arr, l, m - 1);
		sort(arr, m+1, r);
	}
}

int main(int argc, const char * argv[]) {
	int size;
	scanf("%d", &size);
	int arr[size];
	for(int i=0;i<size;i++){
		scanf("%d", &arr[i]);
	}	
	sort(arr, 0, size - 1);
	print_array(arr, 0, size);
	return 0;
}