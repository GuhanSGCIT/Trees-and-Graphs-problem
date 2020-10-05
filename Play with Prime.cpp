/*
Ritesh loves playing with numbers. One day his friend Ramakant asked him a problem to find descending order of a given unsorted array of natural number after finding the sum of all prime factors for each element. Ritesh is good in mathematics, but his programming skill is weak. Let's help Ritesh.

time:3sec
level:6

Input:
First line will contain T, number of testcases. Then the testcases follow.
The first line of each testcase will contain an integer N the size of array.
The second line of each testcase will contain N elements A1,A2,...,AN

Output:
For each testcase, print the required array.

Constraints
1≤T≤50
1≤N≤1064
1≤A[i]≤10^6

Sample Input:
2
5
10 15 45 63 26
5
39 49 51 91 46

Sample Output:
15 13 11 8 7
25 20 20 16 14

EXPLANATION:
Test case 1: Sum of prime factors for 10,15,45,63,26 are 2+5=7,3+5=8,3+3+5=11,3+3+7=13,2+13=15 respectively.

input:
3
7
1 55 14 23 65 47 87
5
1 5 6 4 2
4
55 88 66 22

output:
47 32 23 18 16 9 0 
5 5 4 2 0 
17 16 16 13

input:
2
9
44 45 47 48 49 41 42 43 40
3
1 2 3

output:
47 43 41 15 14 12 11 11 11 
3 2 0

input:
1
8
321 355 615 114 281 758 165 148

output:
381 281 110 76 49 41 24 19

input:
3
2
12 24
5
5 4 3 2 1
3
123 321 456

output:
9 7 
5 4 3 2 0 
110 44 28

hint:
First find the sum of prime factors for each element and store in an array. Sort the array in descending order using any sorting algorithm.

*/
#include <stdio.h>
#include <math.h>

//Sum of all prime factors
long primeFactorsSum(int num) {
    
    int i;
    long sum = 0;
    
    while (num % 2 == 0) { 
        sum += 2;
        num /= 2; 
    } 
  
    for (i = 3; i <= sqrt(num); i += 2) { 
        while (num % i == 0) { 
            sum += i;
            num /= i; 
        } 
    } 
  
    if (num > 2) 
        sum += num;
        
    return sum;
}


// Insertion sort
void insertionSort(long arr[], int n) {
    
    int i, j, key;
    
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 

        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j -= 1; 
        } 
        arr[j + 1] = key; 
    } 
} 


int main(void) {
    
	int test;
	scanf("%d", &test);
	
	while(test--) {
	    int size, i;
	    scanf("%d", &size);
	    
	    int arr[size];
	    long prime_sum[size];
	    
	    for(i = 0; i < size; i++) {
	        scanf("%d", &arr[i]);
	        prime_sum[i] = primeFactorsSum(arr[i]);   //Store elements as sum of all prime factors
	    }
	    
	    insertionSort(prime_sum, size);  //Array sorting
	    
	    //Array printing in reverse order
	    for(i = size-1; i >= 0; i--)
	        printf("%d ", prime_sum[i]);
	    
	    printf("\n");
	}
	
	return 0;
}
