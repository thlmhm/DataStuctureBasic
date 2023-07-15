#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define SIZE 100
typedef struct{
    char student[40];
    char fname[10];
}class_t;
class_t class[SIZE];
char *first(char *a){
    int i;
    for (i = strlen(a) - 1; i >= 0; i--){
        if(a[i] == ' ') break;
    }
    return a + i + 1;
}
void swap(class_t *a, class_t *b){
    class_t c;
    c = *a;
    *a = *b;
    *b = c;
}
int main(){
    int n,i,j, max = 0;
    int check;
    printf("Enter number of students: ");
    scanf("%d", &n);
    for( i = 0; i < n; i++){
        printf("Student %d: ", i + 1);
        fflush(stdin);
        gets(class[i].student);
        sscanf(first(class[i].student),"%s",class[i].fname);
    }
    for( i = 0; i < n - 1 ; i++)
        for( j = 0; j < n - 1; j++){
            if (strcmp(class[j].fname, class[j+1].fname) > 0)
               swap(&class[j], &class[j+1]);
        }
    for( i = 0; i < n; i++){
        printf("%s\n", class[i].student);
    }
    for( i = 0; i < n - 1 ; i++){
         check = 0;
        for( j = 0; j < n - 1; j++){
            if(strcmp(class[i].fname, class[j].fname) == 0)
                check ++;
        }
        if(check > max) max = check;
    }
    printf("Maximum number of students having the same first name : %d\n", max);
}
