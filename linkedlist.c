#include<stdio.h>
#include<stdlib.h>
struct list {
    int data;
    struct list *next;
};
struct list *start=NULL;
int main()
  {
    struct list *p,*q; 
    int i=0;
    while(i<3)
      {
       p=(struct list *) malloc(sizeof(struct list));
       scanf("%d",&p->data);
       if (start==NULL)
           start=p;
       else
          {
           q=start;
           while(q->next!=NULL)
              q=q->next;
           q->next=p;   
          } //end else   
       i++;   
      }//end of while()

   q=start;
   printf("the list is: ");
   //while(q->next!=NULL)
     do {
       printf("%d ",q->data);
       q=q->next;
  }while(q->next!=NULL);
  }//end main