#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int comp1=0;
int comp2=0;
int comp3=0;
int comp4=0;
// Swap utility
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
  
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
  
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    comp2++;
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
  
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    comp4++;
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = (l + (r - l) / 2);
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}
 

// Bubble sort
void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            comp1++;
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}
  
  
// Selection sort
void selectionSort(int arr[], int n)
{
    int i, j, midx;
  
    for (i = 0; i < n - 1; i++) {
  
        // Find the minimum element in unsorted array
        midx = i;
        for (j = i + 1; j < n; j++)
            comp3++;
            if (arr[j] < arr[midx])
                midx = j;
  
        // Swap the found minimum element
        // with the first element
        swap(&arr[midx], &arr[i]);
    }
}
int main()
{
    int n = 100000;
    int it = 0;
    FILE *fp1 = NULL,*fp2 = NULL;
    fp1=fopen("seqtime.txt","w");
    fp2=fopen("seqcount.txt","w");
    // Arrays to store time duration
    // of sorting algorithms
    float tim1[20], tim2[20], tim3[20], tim4[20];
    fprintf(fp1,"Time taken\n");
    fprintf(fp1,"A_size, Bubble, Quick, Selection, Merge\n");
    fprintf(fp2,"Number of comparisons\n");
    fprintf(fp2,"A_Size, Bubble, Quick, Selection, Merge\n");
    // Performs 20 iterations
    while (it++ < 20) {
        int a[n], b[n], c[n], d[n];
  
        // generating n random numbers
        // storing them in arrays a, c
        for (int i = 0; i < n; i++) {
            int no = rand() % n + 1;
            a[i] = no; //bubble
            b[i] = no; //quick
            c[i] = no; //selection
            d[i] = no; //merge
        }
  
        // using clock_t to store time
        clock_t start, end;
  
        // Bubble sort
        printf("bubble for %d\n",n);
        start = clock();
        bubbleSort(a, n-1);
        end = clock();
  
        tim1[it] = ((float)(end - start));
        tim1[it]/=CLOCKS_PER_SEC;
        
        // Merge sort
        printf("merge for %d\n",n);
            start = clock();
            mergeSort(d,0,n-1);
            end = clock();
            tim2[it] = ((float)(end - start));
            tim2[it]/=CLOCKS_PER_SEC;
  
        // Selection sort
        printf("selection for %d\n",n);
        start = clock();
        selectionSort(c, n-1);
        end = clock();
  
        tim3[it] = ((float)(end - start));
        tim3[it]/=CLOCKS_PER_SEC;
        //Quick sort
        printf("quick for %d\n",n);
        start = clock();
        quickSort(b,0,n-1);
        end = clock();
        
        tim4[it] = ((float)(end - start));
        tim4[it]/=CLOCKS_PER_SEC;
        // type conversion to long int
           fprintf(fp1,"%d\t %f\t %f\t %f\t\t %f\n",n,tim1[it],tim2[it],tim3[it],tim4[it]);
           fprintf(fp2,"%d    %d    %d    %d    %d\n",n,comp1,comp2,comp3,comp4);
        // increases the size of array by 50000
        n += 50000;
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
