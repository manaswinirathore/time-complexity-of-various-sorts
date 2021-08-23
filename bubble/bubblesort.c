// C program to store time taken by bubble sort, 
// insertion sort and selection sort 
// for sorting exactly same arrays. 

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
int count;
// Swap utility 
void swap(long int* a, long int* b) 
{ 
	int tmp = *a; 
	*a = *b; 
	*b = tmp; 
} 

// Bubble sort 
void bubbleSort(long int a[], long int n) 
{ 
	for (long int i = 0; i < n - 1; i++) { 
		for (long int j = 0; j < n - 1 - i; j++) {
            count++;
			if (a[j] > a[j + 1]) { 
				swap(&a[j], &a[j + 1]); 
			} 
		} 
	} 
} 

// Driver code 
int main() 
{ 
	FILE *fp1=fopen("BubblesortTime2.txt","w");
	FILE *fp2=fopen("BubblesortNumber2.txt","w");
	long int n = 100000; 
	int it = 0; 

	// Arrays to store time duration 
	// of sorting algorithms 
	double tim1[20];
	fprintf(fp1,"BubbleSort\n");
	fprintf(fp1,"A_size,  Time\n"); 
	fprintf(fp2,"BubbleSort\n");
	fprintf(fp2,"A_size,  Comparisions\n"); 

	// Performs 10 iterations 
	while (it++ < 20) {
		long int a[n];
		// generating n random numbers 
		// storing them in arrays a, b, c 
		for (int i = 0; i < n; i++) { 
			long int no = rand() % n + 1; 
			a[i] = no; 
		} 

		// using clock_t to store time 
		clock_t start, end; 

		// Bubble sort 
		start = clock(); 
		bubbleSort(a, n); 
		end = clock(); 

		tim1[it] = ((double)(end - start));  

		// type conversion to long int 
		// for plotting graph with integer values 
		fprintf(fp1,"%li, %li\n", n, (long int)tim1[it]);
		fprintf(fp2,"%li, %d\n", n, count);

		// increases the size of array by 10000 
		n += 50000;
		
	} 
	fclose(fp1);
	fclose(fp2);
	return 0; 
} 

