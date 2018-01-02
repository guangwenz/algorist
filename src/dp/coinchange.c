#include <stdio.h>

/**
Input:
The first line contains an integer 'T' denoting the total number of test cases. 
In each test cases, the first line contains an integer 'M' denoting the size of array. 
The second line contains M space-separated integers A1, A2, ..., 
AN denoting the elements of the array. The third line contains an integer 'N' denoting the cents.

Output:
Print number of possible ways to make change for N cents.
*/

void print_array(int arr[], int n){
	for(int i=0;i<n;i++){
		printf("%d\n", arr[i]);
	}
}

int count(int arr[], int coins, int cents) {
	if(cents == 0) return 1;

	if(cents < 0) return 0;

	if(coins <=0 && cents > 0) return 0;

	return count(arr, coins - 1, cents) + count(arr, coins, cents - arr[coins - 1]);
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--) {
		int m,cents;
		int sum=0;
		scanf("%d", &m);
		int arr[m];
		for(int i=0;i<m;i++){
			scanf("%d", &arr[i]);
		}
		scanf("%d", &cents);
		sum = count(arr, m, cents);
		printf("%d\n", sum);
	}
	return 0;
}