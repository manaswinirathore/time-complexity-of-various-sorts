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

int main()
{
    int n = 100000;
    int it = 0;
    FILE *fp1 = NULL,*fp2 = NULL;
    fp1=fopen("bubble_seqtime.txt","w");
    fp2=fopen("bubble_seqcount.txt","w");
    float tim1[20];
    fprintf(fp1,"Time taken\n");
      fprintf(fp1,"A_size, Bubble\n");
      fprintf(fp2,"Number of comparisons\n");
      fprintf(fp2,"A_Size, Bubble\n");
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
          bubbleSort(a, n-1);
          end = clock();
          tim1[it] = ((float)((end - start)/CLOCKS_PER_SEC));
           fprintf(fp1,"%d\t %f\n",n,tim1[it]);
           fprintf(fp2,"%d    %d\n",n,comp1);
                  // increases the size of array by 50000
                  n += 50000;
              }
              fclose(fp1);
              fclose(fp2);
              return 0;
          }

