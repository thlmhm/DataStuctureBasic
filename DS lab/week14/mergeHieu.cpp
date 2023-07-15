#include <stdio.h>
#define MAX 10


void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge(int arr[], int first, int mid, int last)
{
    int numOfArr1 = mid - first + 1;
    int arr1[numOfArr1];
    for(int i = 0; i < numOfArr1; i++)
        arr1[i] = arr[first + i];
    int numOfArr2 = last - mid;
    int arr2[numOfArr2];
    for(int i = 0; i < numOfArr2; i++)
        arr2[i] = arr[mid + 1 + i];
    
    int i = 0, j = 0, index = first;
    while(i != numOfArr1 && j != numOfArr2)
    {
        if(arr1[i] > arr2[j])
        {
            arr[index] = arr1[i];
            i++;
        }else{
            arr[index] = arr2[j];
            j++;
        }
        index++;
    }
    while(i != numOfArr1)
    {
        arr[index] = arr1[i];
        index++;
        i++;
    }
    while(j != numOfArr2)
    {
        arr[index] = arr2[j];
        index++;
        j++;
    }
}

void mergeSort(int arr[], int first, int last)
{
    if(first < last)
    {
        int mid = (last + first)/2;
        mergeSort(arr, first, mid);
        mergeSort(arr, mid + 1, last);
        merge(arr, first, mid, last);
    }
}

void printfValue(int arr[], int number)
{
    for(int i = 0; i < number; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[MAX] = { 1, 3, 2, 4, -6, 4, 7, 4, 10, 9 };
    
    mergeSort(arr, 0, 9);
    printfValue(arr, MAX);
    
    return 0;
}
