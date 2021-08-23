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

// Selection sort 
int selectionSort(long int arr[], long int n) 
{ 
	long int i, j, midx; 

	for (i = 0; i < n - 1; i++) { 

		// Find the minimum element in unsorted array 
		midx = i; 

		for (j = i + 1; j < n; j++)
		{
			count++;
			if (arr[j] < arr[midx]) 
				midx = j; 
		}
		// Swap the found minimum element 
		// with the first element
		swap(&arr[midx], &arr[i]);
	}
    return count;
} 

// Driver code 
int main() 
{ 
	FILE *fp1=fopen("SelectionSort_Time.txt","w");
	FILE *fp2=fopen("SelectionSort_No.txt","w");
	long int n = 100000; 
	int it = 0; 

	// Arrays to store time duration 
	// of sorting algorithms 
	double tim[20];
	
	 fprintf(fp1,"Time taken\n");
      fprintf(fp1,"A_size, Selection\n");
      fprintf(fp2,"Number of comparisons\n");
	fprintf(fp2,"A_size,  Selection\n"); 

	// Performs 10 iterations 
	while (it++ < 20) {
		long int c[n]; 

		// generating n random numbers 
		// storing them in array c 
		for (int i = 0; i < n; i++) { 
			long int no = rand() % n + 1; 
			c[i] = no; 
		} 

		// using clock_t to store time 
		clock_t start, end; 

		// Selection sort 
		start = clock(); 
		selectionSort(c, n); 
		end = clock(); 

		tim[it] = ((double)(end - start)); 

		// type conversion to long int 
		// for plotting graph with integer values 
		fprintf(fp1,"%li, %li\n", n, (long int)tim[it]); 
		fprintf(fp2,"%li, %d\n", n, count);
		// increases the size of array by 10000 
		n += 50000;
		
	} 
	fclose(fp1);
	fclose(fp2);
	return 0; 
} 

