#include <stdio.h>  
int fun(int); //A function that takes integer parameter and returns integer
int main()  
{  
   int a,b;  
   int (*ip)(int);  //ip is a pointer to a function that takes a int parameter and returns integer
   int result;  
   ip=fun;  
   result=(*ip)(7);  
   printf("Value returned : %d",result);  
    return 0;  
}  
int fun(int a)  
{  
    int c=a*100;  
    return c;  
}  