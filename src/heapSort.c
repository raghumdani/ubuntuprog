//program to heapsort input integers
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
#include<string.h>
#include<regex.h>
#include<sys/types.h>

int left(int* Arr,int i){
   return Arr[2*i];}

int right(int* Arr,int i){
   return Arr[2*i +1];}  

int parent(int* Arr,int i){
   return Arr[i/2];}

void swapIt(int* Arr,int m,int n){
   int temp;
   temp = Arr[m];
   Arr[m] = Arr[n];
   Arr[n] = temp;
}

void maxHeapify(int* Arr,int n){
   int i,left(int*,int),right(int*,int);
   void swapIt(int*,int,int);
   for(i=n/2;i>=1;i--){
      if(left(Arr,i)>Arr[i])
          swapIt(Arr,2*i,i);
      if(((2*i+1)<=n)&& right(Arr,i)>Arr[i])
          swapIt(Arr,2*i+1,i);
   }
}
void printMaxHeap(int* Arr,int n){
   int i;
   for(i=1;i<=n;i++)
     printf("%d\t",*(Arr+i));
}
    
int main(int argc,char *argv[]){
    void printMaxHeap(int*,int),maxHeapify(int*,int),swapIt(int*,int,int);
    int arr[MaxSize+1],i=1,n,k=0,c,reval1,reval2,reval3,reval;
    char integer[5000];
    //regex_t regex1,regex2,regex3;
    //regmatch_t matches1[3],matches2[3],matches3[3];
    //data collection
    if(argv[1]==NULL){
       printf("Enter The Numbers to be HeapSorted followed by 0:\n");
       if(scanf("%d",&n)!= 1) n = 0;
       while(n!=0){
          arr[i++] = n;
          if(scanf("%d",&n)!=1) n = 0;
       }
       n = i-1;
    }
    else{ i = 1;
          while(i<argc){
            arr[i] = atoi(argv[i]);
            i++;
          }
       }
    for(i=1;i<n;i++){
       maxHeapify(arr,n-i+1);
       swapIt(arr,1,n-i+1);
       printMaxHeap(arr,n);
       printf("\n");
    }
    return 0;
}
