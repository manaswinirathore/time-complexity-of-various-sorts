#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int comp1=0;
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
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
    comp1++;
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

int main()
{
    int n = 100000;
    int it = 0;
    FILE *fp1 = NULL,*fp2 = NULL;
    fp1=fopen("seqtime.txt","w");
    fp2=fopen("seqcount.txt","w");
    int tim1[20];
    fprintf(fp1,"Time taken\n");
      fprintf(fp1,"A_size, Bubble, Quick, Selection, Merge\n");
      fprintf(fp2,"Number of comparisons\n");
      fprintf(fp2,"A_Size, Bubble, Quick, Selection, Merge\n");
      // Performs 20 iterations
      while (it++ < 20) {
          int a[n];
    
          // generating n random numbers
          // storing them in arrays a, c
          for (int i = 0; i < n; i++) {
              int no = rand() % n + 1;
              a[i] = no; //bubble
             // b[i] = no; //quick
              //c[i] = no; //selection
             // d[i] = no; //merge
          }
    
          // using clock_t to store time
          clock_t start, end;
    
          // Bubble sort
          start = clock();
          mergeSort(a,0,n-1);
          end = clock();
          tim1[it] = ((int)(end - start));
           fprintf(fp1,"%d\t %d\n",n,tim1[it]);
           fprintf(fp2,"%d    %d\n",n,comp1);
                  // increases the size of array by 50000
                  n += 50000;
              }
              fclose(fp1);
              fclose(fp2);
              return 0;
          }

