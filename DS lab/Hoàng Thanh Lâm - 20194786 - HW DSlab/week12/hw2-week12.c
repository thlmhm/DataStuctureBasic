#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 500000
void printfmenu(){
	printf("---------------MENU--------------\n");
	printf("1.Sequential search.\n");
	printf("2.Sequential search using Sentinel.\n");
	printf("3.Binary search.\n");
	printf("4.Exit.\n");
}
int sequential_search(int p[], int x){
	int k = 0;
	while(p[k] != x && k < MAX){
		k++;
	}
	if(k < MAX) return k;
	return -1;
}
int sentinel_search(int p[], int x){
	int k = 0; 
	p[MAX] = x;
	while(p[k] != x){
		k++;
	}
	if(k < MAX) return k;
	return -1;
}
int bin_search(int low, int high, int p[], int x){
	int mid;
	if(low<=high){
		mid = (low+high)/2;
		if(x == p[mid]) return mid;
		else if(x < p[mid]) return bin_search(low,mid-1,p,x);
		else return bin_search(mid+1,high,p,x);	
	}else return -1;
}
int main(){
	int *p;
	int i, choice, num;
	int check;
	clock_t start, end;
	double time_use;
	p = (int *)malloc(MAX *sizeof(int));
	for(i = 0; i<MAX; i++){
		p[i] = 2*i+3;
	} 
	do{
		printfmenu();
		printf("Enter your choice:");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Enter your number:");
				scanf("%d", &num);
				start = clock();
				check = sequential_search(p,num);
				end = clock();
				time_use = (double)(end - start)/CLOCKS_PER_SEC;
				if(check == -1){
					printf("No result!\n");
				}else printf("The number you have just chosen is p[%d] = %d\n",check, num);
				printf("Time execution of sequential search: %.10f\n", time_use);
				break;
			case 2:
				printf("Enter your number:");
				scanf("%d", &num);
				start = clock();
				check = sentinel_search(p,num);
				end = clock();
				time_use = (double)(end - start)/CLOCKS_PER_SEC;
				if(check == -1){
					printf("No result!\n");
				}else printf("The number you have just chosen is p[%d] = %d\n",check, num);
				printf("Time execution of sequential search using Sentinel: %.10f\n", time_use);
				break;
			case 3:
				printf("Enter your number:");
				scanf("%d", &num);
				start = clock();
				check = bin_search(0,MAX-1,p,num);
				end = clock();
				time_use = (double)(end - start)/CLOCKS_PER_SEC;
				if(check == -1){
					printf("No result!\n");
				}else printf("The number you have just chosen is %d\n", num);
				printf("Time execution of sequential search: %.10f\n", time_use);
				break;
			case 4:
				printf("Exit successful!\n");
				break;
			default:
				printf("Enter again! Your choice must be 1-4 !\n");
				break;
		}
	}while(choice!=4);
	free(p);
	return 0;
}
