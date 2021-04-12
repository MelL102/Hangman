#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 255


int main()
{
    char input;
    int checkInput;


    char solution[MAX] = {"Justus"};
    char usedChars[MAX];
    char hiddenWord[MAX];

    for(int i = 0; i<strlen(solution); i++){
        printf("%c",solution[i]);
    }
    printf("\n");
    for(int i = 0; i<strlen(solution); i++){
        hiddenWord[i] = '_';
        printf("%c ",hiddenWord[i]);
    }
    printf("\n");
    while(strchr(hiddenWord, '_')){
        printf("Guess a letter: \n");
        scanf("%c",&input);
        fflush(stdin);
         if(strchr(solution, input)){

                printf("You guessed correctly!!\n");

                for(int i=0; i<strlen(hiddenWord);i++){
                    if(solution[i] == input){
                        hiddenWord[i] = input;
                    }
                }
            }else{
                printf("Loser\n");
            }
    for(int i = 0; i<strlen(solution); i++){
        printf("%c ",hiddenWord[i]);
    }
    }


    return 0;
}
