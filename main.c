#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 255

void show_used_chars_and_attempts(char usedChars[], int attempts){      //function to show used chars and the number of attempts made
    char tmp;
    int i, j;
    for(i = 0; i < strlen(usedChars);i++){                              //bubble sort to sort used chars !NOT WORKING PROPERLY ATM THIRD OR FOURTH CHARAKTER IS BUGGED
        for(j = 0; j < strlen(usedChars)-1;j++){

            if(usedChars[j] > usedChars[j+1]){

                tmp = usedChars[j];
                usedChars[j] = usedChars[j+1];
                usedChars[j+1] = tmp;

            }

        }
    }
    printf("\nYou already used the following chars:\n");
    for(i = 0; i < strlen(usedChars);i++){
        printf("%c ",usedChars[i]);
    }
    printf("\n");
    printf("You already guessed %i times!\n",attempts);
}

void convert_to_upper(char solution[]){                                 //function to convert a string to uppercase
    int i = 0;
    char chr;

    while (solution[i]) {
        chr = solution[i];
        solution[i] = toupper(chr);
        i++;
    }
}

char input(char usedChars[]){                                           //function for input and input validation

char input;

    while(1) {
        printf("Guess a letter: \n");
        scanf("%c",&input);
        input = toupper(input);
        fflush(stdin);
        if(input >= 'A' && input <= 'Z'){
            if(strchr(usedChars, input)){
                printf("The char %c was already used in a previous guess please try again:\n");
            }else{return input;}

        }else{
            printf("Invalid input try again:\n");
        }

    }

}



int main()
{
    char in;
    char solution[MAX] = {"Justus"};
    char usedChars[MAX];
    char hiddenWord[MAX];
    int attempts = 0;

    convert_to_upper(solution);
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
        in = input(usedChars);
        usedChars[attempts] = in;
         if(strchr(solution, in)){

                printf("You guessed correctly!!\n");

                for(int i=0; i<strlen(hiddenWord);i++){
                    if(solution[i] == in){
                        hiddenWord[i] = in;
                    }
                }
            }else{
                printf("Loser\n");
            }
    for(int i = 0; i<strlen(solution); i++){
        printf("%c ",hiddenWord[i]);
    }
    attempts++;
    show_used_chars_and_attempts(usedChars, attempts);
    }


    return 0;
}
