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
    comp1++;
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
  

int main()
{
    int n = 100000;
    int it = 0;
    FILE *fp1 = NULL,*fp2 = NULL;
    fp1=fopen("quick_seqtime.txt","w");
    fp2=fopen("quick_seqcount.txt","w");
    float tim1[20];
    fprintf(fp1,"Time taken\n");
      fprintf(fp1,"A_size, Quick\n");
      fprintf(fp2,"Number of comparisons\n");
      fprintf(fp2,"A_Size, Quick\n");
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
          quickSort(a,0, n-1);
          end = clock();
          tim1[it] = ((float)(end - start));
          tim1[it]=tim1[it]/CLOCKS_PER_SEC;
           fprintf(fp1,"%d\t %f\n",n,tim1[it]);
           fprintf(fp2,"%d    %d\n",n,comp1);
                  // increases the size of array by 50000
                  n += 50000;
              }
              fclose(fp1);
              fclose(fp2);
              return 0;
          }

