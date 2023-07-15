#include<bits/stdc++.h>

using namespace std;

void insertionSort(int A[], int n){
	for (int i = 1; i<n;i++)
	{
			int temp = A[i];
			int pos = i;
			// compare temp to A[i-1],...,A[0]
			while(pos > 0 && temp < A[pos-1])
			{
				A[pos] = A[pos-1];
				pos--;	
			}
			A[pos] = temp;
	}
} 

void selectionSort(int a[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		//Iteration i:we need to find the smallest element in unsorted part 
		//a[i+1], ... put the found smallest element at element a[i]
		int index =i;
		for (int j = i+1; j<=n-1; j++){
			if(a[j] < a[index]) index = j;
		}
		int temp = a[i];
		a[i] = a[index];
		a[index] =temp;
	}
}

void bubbleSort(int a[], int n)
{
	bool alreadyS = false;
	for(int i=1;i<=n-1;i++)
	{
		if(alreadyS == false)
		{
			alreadyS =true;
			for(int j=0;j<=n-i-1;j++)
				if(a[j] > a[j+1])
				{	
					int temp = a[j]; a[j] = a[j+1]; a[j+1] = temp;
					alreadyS = false;
				}
		}else break;
	}
}
int main()
{
	int a[] = {23,78,45,8,32,56};
	//insertionSort(a,6);
	//selectionSort(a,6);
	bubbleSort(a,6);
	cout<<"Array after sorting: ";	
	for (int i = 0; i<6;i++)
		cout<< a[i]<< "   ";

}

