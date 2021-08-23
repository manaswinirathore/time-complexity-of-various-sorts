#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"PES2UG19CS217.h"
int main()
{
    int n = 100000;
    int it = 0;
    int comp1=0;
    int comp2=0;
    int comp3=0;
    int comp4=0;
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
        start = clock();
        bubbleSort(a, n-1,&comp1);
        end = clock();
  
        tim1[it] = ((float)(end - start));
        tim1[it]/=CLOCKS_PER_SEC;
        
        // Merge sort
            start = clock();
            mergeSort(d,0,n-1,&comp4);
            end = clock();
            tim2[it] = ((float)(end - start));
            tim2[it]/=CLOCKS_PER_SEC;
  
        // Selection sort
        start = clock();
        selectionSort(c, n-1,&comp3);
        end = clock();
  
        tim3[it] = ((float)(end - start));
        tim3[it]/=CLOCKS_PER_SEC;
        //Quick sort
        start = clock();
        quickSort(b,0,n-1,&comp2);
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

