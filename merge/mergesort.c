#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void msort(int a[],int low,int high,int n,int *count);
void merge(int a[],int low,int mid,int high,int n,int *count);
int main()
{
FILE *fp1=fopen("MergesortTime.txt","w");
FILE *fp2=fopen("MergesortNumber.txt","w");
int n = 100000;
int it=0;
int i,count=0;
clock_t start,end;
fprintf(fp1,"Time taken\n");
fprintf(fp1,"A_size, Merge\n");
fprintf(fp2,"Number of Comparisions\n");
fprintf(fp2,"A_size, Merge\n");
while (n <= 1000000)
	{ 
	int a[n];
 	for(i=0;i<n;i++){
 		int no = rand() % n + 1;
			a[i] = no;} 

 //merge sort
	start=clock();
	msort(a,0,n-1,n,&count);
	end=clock();
        float time = (float)(end-start);
        time=time/CLOCKS_PER_SEC;
 
 //result
	fprintf(fp1,"%d	, %f\n", n,time);
	fprintf(fp2,"%d, %d\n", n, count);
 	n+=50000;
 	
 	}
fclose(fp1);
fclose(fp2);
}

void msort(int a[],int low,int high,int n,int *count)
{
 if(low<high)
   {
    int mid=(low+high)/2;
    msort(a,low,mid,n,count);
    msort(a,mid+1,high,n,count);
    merge(a,low,mid,high,n,count);
   }
}
void merge(int a[],int low,int mid,int high,int n,int *count)
{
 int i=low;
 int j=mid+1;
 int k=0;
 int b[n];  
 while(i<=mid && j<=high)
   {
    (*count)++;
    if(a[i]<a[j])
      { b[k++]=a[i];i++;} 
    else
      {
        b[k++]=a[j];j++;
      }
    }
 while(i<=mid)
  {
    b[k++]=a[i];i++;
   }
 while(j<=high)
  {
   b[k++]=a[j];j++;
   }
  int l=low;
 for(i=0;i<k;i++)
   a[l++]=b[i];//array a from low to high
}
