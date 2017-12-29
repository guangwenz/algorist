#include <stdio.h>

/**
Best: O(n), AVG: theta(n^2), Worst: O(n^2)
*/

void print_array(int arr[], int size) {
	for(int i=0; i<size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void sort(int arr[], int size) {
	for(int i=1; i<size; i++){
		int item = arr[i];
		int j=i-1;
		while(j>=0 && arr[j] > item) {
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1] = item;
	}
}

int main(int argc, char const *argv[])
{
	int size;
	scanf("%d", &size);
	int arr[size];
	for(int i=0;i<size;i++){
		scanf("%d", &arr[i]);
	}
	printf("before sort\n");
	print_array(arr, size);
	sort(arr, size);
	printf("after sort\n");
	print_array(arr, size);
	return 0;
}