#include<stdio.h>
long bin = 0;
int conver(int n){
	if(n == 0){
		return 0;
	}
	else{
		return n % 2 +10*(conver(n/2));
	}
}
int main(){
	int dec;
	int i = 0;
	printf("Enter decimal number:");
	scanf("%d", &dec);
	printf("Convert to binary number: %d\n", conver(dec));	
	return 0;
}
