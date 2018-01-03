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
#define NIL -1
#define M 100
#define N 100

void print_array(int arr[], int n){
	for(int i=0;i<n;i++){
		printf("%d\n", arr[i]);
	}
}

void print_lookup(int lookup[M][N]){
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			printf("%d ", lookup[i][j]);
		}
		printf("\n");
	}
}

int count(int arr[], int coins, int cents) {
	if(cents == 0) return 1;

	if(cents < 0) return 0;

	if(coins <=0 && cents > 0) return 0; //impossible to make changes out of coins numbers

	return count(arr, coins - 1, cents) + count(arr, coins, cents - arr[coins - 1]);
}

int count_memo(int arr[], int coins, int cents, int lookup[M][N]) {
	if(lookup[coins][cents] != NIL) {
		return lookup[coins][cents];
	}
	int result;
	if(cents == 0) result = 1;
	else if(cents < 0) result = 0;
	else if(coins <=0 && cents > 0) result = 0;
	else result = count_memo(arr, coins - 1, cents, lookup) + count_memo(arr, coins, cents - arr[coins - 1], lookup);
	if(coins>=0 && cents>=0) {
		lookup[coins][cents] = result;
	}
	return result;
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

		int lookup[M][N];
		for(int i=0;i<M;i++){
			for(int j=0;j<N;j++){
				lookup[i][j] = NIL;
			}
		}
		sum = count_memo(arr, m, cents, lookup);
		// print_lookup(lookup);
		printf("%d\n", sum);
	}
	return 0;
}