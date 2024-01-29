#include<stdio.h>
int main()
{
    int n = 8;
    int a[] = {1,5,3,2,10,8,20,4};
    int min_index;
    for(int i = 0; i < n - 1; i++) {
    //   for(int i = 0; i < n; i++) {
     //           printf(" %d", a[i]);
     //       }
   //     printf("\n");   
        min_index = i;
        for(int j = i + 1; j < n; j++) {
            if(a[min_index] > a[j]) {
                min_index = j;
            }
        }
        if(min_index != i)
        {
            int temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
        }
      for(int i = 0; i < n; i++) {
               printf(" %d", a[i]);
            }
       printf("\n");
    }
    printf("Sorted Array: ");
    for(int i = 0; i < n; i++)  {
        printf(" %d", a[i]);
    }
    return 0;
}