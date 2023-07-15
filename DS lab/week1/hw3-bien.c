#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100
int random(int min, int max){
    return min + rand() % (max - min + 1);
}
int main(){
	int i;
    char sentence[10][50];
    char art[5][5];
    strcpy(art[0], "the");
    strcpy(art[1], "a");
    strcpy(art[2], "one");
    strcpy(art[3], "some");
    strcpy(art[4], "any");
    char nou[5][5];
    strcpy(nou[0], "boy");
    strcpy(nou[1], "girl");
    strcpy(nou[2], "dog");
    strcpy(nou[3], "town");
    strcpy(nou[4], "car");
    char ver[5][8];
    strcpy(ver[0], "drove");
    strcpy(ver[1], "jumped");
    strcpy(ver[2], "ran");
    strcpy(ver[3], "walked");
    strcpy(ver[4], "skipped");
    char pre[5][6];
    strcpy(pre[0], "to");
    strcpy(pre[1], "from");
    strcpy(pre[2], "over");
    strcpy(pre[3], "under");
    strcpy(pre[4], "on");
    srand((int) time(0));
    for( i = 0; i < 10; i ++){
        if(i != 9){
            strcpy(sentence[i], art[random(0, 4)]);
            strcat(sentence[i], " ");
            strcat(sentence[i], nou[random(0, 4)]);
            strcat(sentence[i], " ");
            strcat(sentence[i], ver[random(0, 4)]);
            strcat(sentence[i], " ");
            strcat(sentence[i], pre[random(0, 4)]);
            strcat(sentence[i], " ");
            strcat(sentence[i], art[random(0, 4)]);
            strcat(sentence[i], " ");
            strcat(sentence[i], nou[random(0, 4)]);
        }else{
            char s[5];
            strcpy(s, art[random(0, 4)]);
            s[0] = s[0] - 'a' + 'A';
            strcpy(sentence[i], s);
            strcat(sentence[i], " ");
            strcat(sentence[i], nou[random(0, 4)]);
            strcat(sentence[i], " ");
            strcat(sentence[i], ver[random(0, 4)]);
            strcat(sentence[i], " ");
            strcat(sentence[i], pre[random(0, 4)]);
            strcat(sentence[i], " ");
            strcat(sentence[i], art[random(0, 4)]);
            strcat(sentence[i], " ");
            strcat(sentence[i], nou[random(0, 4)]);
            strcat(sentence[i], ".");
        }
    }
    for( i = 0; i < 10; i ++)
        printf("%d. %s\n", i+1, sentence[i]);

}
