#include <stdio.h>

#define NIL -1

void print_array(int arr[], int n) {
	for(int i=0;i<n;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
/**
version 1 with recursion
*/
long fib(long n){
	if(n == 0) return 0;
	if (n == 1) return 1;
	else return fib(n-1) + fib(n-2);
}

long _fib(long n, long lookup[]){

	if(n == 0) return 0;
	if (n == 1) return 1;

	if(lookup[n] == NIL){
		long ret = _fib(n-1, lookup) + _fib(n-2, lookup);
		lookup[n] = ret;
	}
	return lookup[n];
}
/**
version 2, top down with memoization.
*/
long fib_topdown(long n){

	if(n == 0) return 0;
	if (n == 1) return 1;

	long lookup[n];
	for(int i=0;i<=n;i++) {lookup[i]=NIL;}
	long ret = _fib(n, lookup);
	return ret;
}

/**
version 3 bottom up implementation.
*/
long fib_bottomup(long n) {
	if(n==0) return 0;
	if(n==1) return 1;
	else {
		long n1=0,n2=1;
		long t=n1+n2;
		for(int i=2;i<n+1;i++) {
			t = n1 + n2;
			n1 = n2;
			n2 = t;
		}
		return t;
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	int n=0;
	printf("enter the number to calucate fibnacci:\n");
	scanf("%d", &n);
	printf("calucating fibnacci number for %d\n", n);
	// printf("fibnacci number is %d\n", fib(n));
	printf("fibnacci number is %ld\n", fib_topdown(n));
	printf("fibnacci number is %ld\n", fib_bottomup(n));
	return 0;
}