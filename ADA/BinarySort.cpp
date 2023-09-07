#include <stdio.h>
#include <stdlib.h>

int* create(int N)
{
   int * A;
   A = (int *)malloc(100*sizeof(int));
   int i;
   for(i=0;i<N;i++)
   {
       printf("Enter element %d: ",i+1);// 1 Step
       scanf("%d",&A[i]);// 1 Step
   }
   return (A);
}
int binary_recursive(int l, int N, int A[],int e)
{
   if(A[(N+l)/2]==e)// 1 Step
   {
       return((N+l)/2+1);// 1 Step
   }
   else if (A[(N+l)/2]>e)// 1 Step
   {
       return(binary_recursive(l,(N+l)/2,A,e));// 1 Step
   }
   else if (A[(N+l)/2]<e)// 1 Step
   {
       return(binary_recursive((N+l)/2,N,A,e));// 1 Step
   }       
}

int main()
{
   int N;
   int * A;
   printf("Enter the size of the array: ");// 1 Step
   scanf("%d",&N);// 1 Step
   A = create(N);// 1 Step
  
   int e;

   printf("Enter Element for binary search: ");// 1 Step
   scanf("%d",&e);// 1 Step

   printf("Element %d is at %d\n",e,binary_recursive(0,N,A,e));// 1 Step

   return(0);
}

