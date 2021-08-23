#include <stdio.h>
#include <stdlib.h>
#include <time.h>
long int comp1=0;
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void selectionSort(int arr[], int n)
{
    int i, j, midx;
  
    for (i = 0; i < n - 1; i++) {
  
        // Find the minimum element in unsorted array
        midx = i;
        for (j = i + 1; j < n; j++)
            comp1++;
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
    fp1=fopen("selection_seqtime.txt","w");
    fp2=fopen("selection_seqcount.txt","w");
    double tim1[20];
    fprintf(fp1,"Time taken\n");
      fprintf(fp1,"A_size, Selection\n");
      fprintf(fp2,"Number of comparisons\n");
      fprintf(fp2,"A_Size, Selection\n");
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
          selectionSort(a, n-1);
          end = clock();
          tim1[it] = ((double)((end - start)/CLOCKS_PER_SEC));
           fprintf(fp1,"%li\t %li\n",n,(int)tim1[it]);
           fprintf(fp2,"%li    %li\n",n,comp1);
                  // increases the size of array by 50000
                  n += 50000;
              }
              fclose(fp1);
              fclose(fp2);
              return 0;
          }

