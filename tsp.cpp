#include<stdio.h>
#include<iostream>
using namespace std;
int c = 0,cost = 999;
int TDArray[4][4] = {{0, 10, 15, 20},
                    {10, 0, 35, 25},
                    {15, 35, 0, 30},
                    {20, 25, 30, 0}
                  };
void nTDArray(int a[], int n)
{
    int i, sum = 0;
    for(i = 0; i <= n; i++)
        //printf(" %d",sum += TDArray[a[i % 4]][a[(i + 1) % 4]]);
        sum += TDArray[a[i % 4]][a[(i + 1) % 4]];
    if (cost > sum)
        cost = sum;
} 
void printA(int a[],int n)
   { int i,j;
     for (i=0;i<3;i++){
        for(j=0;j<3;j++)
          printf("%d ",*(a+i+j));
        printf("\n");} 
   } 
void permute(int a[], int i) 
{
   int j, k; 
   int t;
   if (i == 3)
        nTDArray(a, 3);
   else
   {
        printA(a,3);
        for (j = i; j <= 3; j++)
        {
            t = *(a+1);
            *(a+1) = *(a+j);
            *(a+j) = t;
            permute(a, i + 1);
            t = *(a+1);
            *(a+1) = *(a+j);
            *(a+j) = t;
        }
    }
} 
int main()
{
   int i, j;
   int a[] = {0, 1, 2, 3};  
   permute(a, 0);
   cout<<"The cost:"<<cost<<endl;
}