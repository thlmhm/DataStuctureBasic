#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct phone
{
    char name[100];
    char memoryspace[11];
    char screensize[25];
    int price;
}element;

//MaxHeapify
void MaxHeapify(element a[],int i,int n){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if((left<n)&&(strcmp(a[left].name,a[largest].name)>0)) largest=left;
    if((right<n)&&(strcmp(a[right].name,a[largest].name)>0)) largest=right;
    if(largest!=i){
        element temp;
        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        MaxHeapify(a,largest,n);
    }
}

void buildHeap(element a[],int n){
    int i;
    for(i=(n-1)/2;i>=0;i--){
        MaxHeapify(a,i,n);
    }
}

void heapsort(element a[],int n){
    buildHeap(a,n);
    printf("Build heap complete!\n");
    int heapsize=n;
    while(heapsize>1){
        element temp;
        temp=a[0];
        a[0]=a[heapsize-1];
        a[heapsize-1]=temp;
        MaxHeapify(a,0,heapsize-1);
        heapsize--;
    }
}

void main(){
    element a[21];
    int i=0;
    FILE *f=fopen("PhoneDB.dat","rb");
    if(f==NULL) printf("Cannot open the file!\n");
    else
    {
        while(fread(&a[i],sizeof(element),1,f)>0) i=i+1;
        heapsort(a,21);
        printf("After sort: \n");
        for(i=0;i<21;i++) printf("%-5d%-30s%-10s%-15s%-10d\n",i+1,a[i].name,a[i].memoryspace,a[i].screensize,a[i].price);
    }
    
}
