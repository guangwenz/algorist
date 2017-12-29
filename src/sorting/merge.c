#include <stdio.h>

/**
Best: O(nlgn), AVG: theta(nlgn), Worst: O(nlgn)
*/

void print_array(int arr[], int n) {
	for (int i=0;i<n;i++){
		printf("%d\n", arr[i]);
	}
}

void merge(int arr[], int l, int m, int r) {
	int i,j,k=0;
	int n1 = m - l + 1;
	int n2 = r - m;
	int left[n1];
	int right[n2];
	for(i=0;i<n1;i++){
		left[i] = arr[l + i];
	}
	for(j=0;j<n2;j++){
		right[j]=arr[m + j + 1];
	}
	i=0;
	j=0;
	k=l;
	while(i < n1 && j < n2) {
		if(left[i] < right[j]) {
			arr[k++] = left[i++];
		} else {
			arr[k++] = right[j++];
		}
	}
	while(i < n1) {
		arr[k++] = left[i++];
	}
	while(j < n2) {
		arr[k++] = right[j++];
	}
}

void sort(int arr[], int l, int r) {
	if(l < r) {
		int m = l + (r-l)/2;
		sort(arr, l, m);
		sort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

int main(int argc, char const *argv[]) {
	int size;
	scanf("%d", &size);
	int arr[size];
	for(int i=0;i<size;i++){
		scanf("%d", &arr[i]);
	}
	sort(arr, 0, size);
	print_array(arr, size);
}
