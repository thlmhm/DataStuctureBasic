#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX 81
void cpychar(FILE *f1, FILE *f2){
    int i = 0;
    char c;
    while( (c = fgetc(f1)) != EOF){
        fputc(c, f2);
        i ++;
    }
    printf("Total %d characters\n", i);
    fclose(f1);
    fclose(f2);
}

void cpyline(FILE *f1, FILE *f2){
    enum{max = 1000};
    int i = 0;
    char str[max];
    while( (fgets(str, max, f1)) != NULL){
        fprintf(f2, "%s", str);
        i ++;
    }
    printf("Total %d lines\n", i);
    fclose(f1);
    fclose(f2);
}

void cpyblock(FILE *f1, FILE *f2){
    printf("Enter block size: ");
    int MAX_LEN;
    scanf("%d", &MAX_LEN);
    int num;
    char buff[MAX_LEN + 1];
    while(!feof(f1)){
        num = fread(buff, sizeof(char), MAX_LEN, f1);
        buff[num * sizeof(char)] = '\0';
        fwrite(buff, sizeof(char), num, f2);
    }
    fclose(f1);
    fclose(f2);
}
void printmenu(){
    printf("--------MENU--------\n");
    printf("1. Copy by character.\n");
    printf("2. Copy by line.\n");
    printf("3. Copy by block.\n");
    printf("4. Exit.\n");
    printf("Enter choice: ");
}
int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Wrong number of arguments\n");
        return 0;
    }
    int menu;
    clock_t t;
    FILE *f1, *f2;
    do{
        printmenu();
        scanf("%d", &menu);
        if( (f1 = fopen(argv[1], "r")) == NULL){
            printf("Cannot open %s\n", argv[1]);
            return 0;
            }
        if( (f2 = fopen(argv[2], "w")) == NULL){
            printf("Cannot open %s\n", argv[2]);
            return 0;
        }
        switch (menu){
            case 1:
                t = clock();
                cpychar(f1, f2);
                t = clock() - t;
                printf("Excution time: %.10lf\n", (double)t / (CLOCKS_PER_SEC));
            break;

            case 2:
                t = clock();
                cpyline(f1, f2);
                t = clock() - t;
                printf("Excution time: %.10lf\n", (double)t / (CLOCKS_PER_SEC));
            break;

            case 3:
                t = clock();
                cpyblock(f1, f2);
                t = clock() - t;
                printf("Excution time: %.10lf\n", (double)t / (CLOCKS_PER_SEC));
            break;

            default:
            break;
        }
    }while(menu != 4);
}