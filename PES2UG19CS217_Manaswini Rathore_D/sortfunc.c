#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"PES2UG19CS217.h"
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
void quickSort(int arr[], int low, int high,int *comp2)
{
    (*comp2)++;
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
  
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1,comp2);
        quickSort(arr, pi + 1, high,comp2);
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
void mergeSort(int arr[], int l, int r, int *comp4)
{
    (*comp4)++;
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = (l + (r - l) / 2);
 
        // Sort first and second halves
        mergeSort(arr, l, m,comp4);
        mergeSort(arr, m + 1, r,comp4);
 
        merge(arr, l, m, r);
    }
}
 

// Bubble sort
void bubbleSort(int a[], int n, int *comp1)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            (*comp1)++;
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}
  
  
// Selection sort
void selectionSort(int arr[], int n, int *comp3)
{
    int i, j, midx;
  
    for (i = 0; i < n - 1; i++) {
  
        // Find the minimum element in unsorted array
        midx = i;
        for (j = i + 1; j < n; j++)
            (*comp3)++;
            if (arr[j] < arr[midx])
                midx = j;
  
        // Swap the found minimum element
        // with the first element
        swap(&arr[midx], &arr[i]);
    }
}
