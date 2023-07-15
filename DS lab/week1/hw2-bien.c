#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define SIZE 100
typedef struct{
    char student[40];
    char fname[10];
}funame;
funame fullname[SIZE];
char *first(char *a){
    int i;
    for (i = strlen(a) - 1; i >= 0; i--){
        if(a[i] == ' ') break;
    }
    return a + i + 1;
}
/*
void swap(class_t *a, class_t *b){
    class_t c;
    c = *a;
    *a = *b;
    *b = c;
}
*/
int main(){
    int n, max = 0;
    int i,j,check;
    printf("Enter number of students: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        printf("Student %d: ", i + 1);
        fflush(stdin);
        gets(fullname[i].student);
        sscanf(first(fullname[i].student), "%s",fullname[i].fname);
    }
    funame swap[SIZE];
    for( i = 0; i < n-1  ; i++)
        for( j = 0; j < n-1  ; j++){
            if (strcmp(fullname[j].fname, fullname[j+1].fname) > 0)
            {
            	strcpy(swap[j].fname , fullname[j].fname);
            	strcpy(fullname[j].fname , fullname[j+1].fname);
            	strcpy(fullname[j+1].fname , swap[j].fname);
			}
        }
    for( i = 0; i < n; i++){
        printf("%s\n", fullname[i].student);
    }
    for( i = 0; i < n  ; i++){
         check = 0;
        for( j = 0; j < n ; j++){
            if(strcmp(fullname[i].fname, fullname[j].fname) == 0)
                check ++;
        }
        if(check > max) max = check;
    }
    printf("Maximum number of students having the same first name : %d\n", max);
}
