#include <stdio.h>
#include <stdlib.h>    
#include <time.h>     
#include <string.h>
#include <iostream>

int main()
{
    char article[5][10] = {"the ", "a " , "one ", "some ", "any "};
    char noun[5][10] = {"boy ", "girl " , "dog ", "town ", "car "};
    char verb[5][10] = {"drove ", "jump " , "ran ", "walked ", "skip "};
    char preposition[5][10] = {"to ", "from " , "over ", "under ", "on "};
    srand(time(NULL));
    char final[100] = {};
    
    int ran = 0;
    for(int i = 0; i < 6; i++)
    {
        ran = rand()%4;
        switch(i)
        {
            case 0:
                {
                    char firstWord[10] = {};
                    strcpy(firstWord, article[ran]);
                    firstWord[0] = firstWord[0] - 'a' + 'A';
                    strcat(final, firstWord);
                    break;
                }
            case 1: 
                strcat(final, noun[ran]);
                break;
            case 2:
                strcat(final, verb[ran]);
                break;
            case 3:
                strcat(final, preposition[ran]);
                break;
            case 4:
                strcat(final, article[ran]);
                break;
            case 5:
                strcat(final, noun[ran]);
                final[strlen(final)-1] = '.';
                break;
        }
    }
    printf("Sentence: %s", final);
    
    return 0;
}

