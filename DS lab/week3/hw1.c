#include<stdio.h>
#include<string.h>
#define MAX 81
int main(int argc, char *argv[]) {
    if(argc != 2 && argc != 3){
        printf("Wrong number of argument\n");
        printf("CORRECT SYNTAX: <\\.mycat> <filename> (-p)\n");
        return 1;
    }

    if(argc == 2){
        FILE *f;
        int count = 1;
        if( (f = fopen(argv[1], "r")) == NULL){
            printf("Cannot open %s\n", argv[1]);
        }else{
            printf("\n");
            char c;
            do{
                c = fgetc(f);
                printf("%c", c);
                if(c == '\n') 
                    count ++;
            }while(c != EOF);
            printf("\n\nTotal %d lines\n", count);
        }
        fclose(f); 

    }
    
    if(argc == 3){
        FILE *f;
        if(strcmp(argv[2], "-p") == 0){
            if( (f = fopen(argv[1], "r")) == NULL){
                printf("Cannot open %s\n", argv[1]);
            }else{
                char s[MAX];
                int count = 0;
                printf("\n");
                while(fgets(s, MAX, f) != NULL){
                    printf("%s", s);
                    count ++;
                    if(count % 28 == 0){
                        char c;
                        do{
                            printf("\nEnd of page %d", count / 28);
                            printf("\nContinue to next page? (Y/N) ");
                            scanf(" %c", &c);
                            printf("\n");
                            if (c == 'N')
                                return 1;
                        }while(c != 'Y');
                    }
                }
                printf("\n\nEnd of page %d\n", (count / 28) + 1);
                fclose(f);
            }
        }else{
            printf("CORRECT SYNTAX: <\\.mycat> <filename> (-p)\n");
        }
    }
}
