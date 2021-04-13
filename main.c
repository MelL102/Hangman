#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include<windows.h>                                                     //library to use textcolors

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
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    printf("\n\nYou already used the following chars:\n");
    for(i = 0; i < strlen(usedChars);i++){
        printf("%c ",usedChars[i]);
    }
    printf("\n");
    printf("You already guessed %i times!\n\n",attempts);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
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
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);    //change the textcolor
                printf("The char %c was already used in a previous guess please try again:\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);    //reset the textcolor
            }else{return input;}

        }else{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);    //change the textcolor
            printf("Invalid input try again:\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);    //reset the textcolor
        }

    }

}

void show_win_screen(char usedChars[], int attempts, char solution[]) { //function to show a new screen after you had guessed the word
    int i;

    system("cls");                                                      //clear the console
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);        //change the textcolor
    printf("\n\n____________________________________\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);        //change the textcolor
    printf("\n\nYou have figured out the word\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);        //change the textcolor
    printf("\n\nThe word was: ");
    for(int i = 0; i<strlen(solution); i++){
        printf("%c",solution[i]);
    }
    printf("\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);        //reset the textcolor
    printf("\n\nYour used chars: ");
    for(i = 0; i < strlen(usedChars);i++){
        printf("%c ",usedChars[i]);
    }
    printf("\n\nYour guesses: %i", attempts);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);        //change the textcolor
    printf("\n\n____________________________________\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);        //reset the textcolor
    scanf("");
}

int main()
{
    char in;
    char solution[MAX] = {"Justus"};
    char usedChars[MAX];
    char hiddenWord[MAX];
    int attempts = 0;

    // WICHTIG SPAETER ENTFERNEN
    //_____________________________
    convert_to_upper(solution);
    for(int i = 0; i<strlen(solution); i++){
        printf("%c",solution[i]);
    }
    //_____________________________

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

                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);    //change the textcolor
                system("cls");                                                  //clear the console
                printf("You guessed correctly!!\n\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);    //reset the textcolor

                for(int i=0; i<strlen(hiddenWord);i++){
                    if(solution[i] == in){
                        hiddenWord[i] = in;
                    }
                }
            }else{
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                system("cls");
                printf("Loser\n\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }
        for(int i = 0; i<strlen(solution); i++){
        printf("%c ",hiddenWord[i]);
        }
        attempts++;
        show_used_chars_and_attempts(usedChars, attempts);
    }

    show_win_screen(usedChars, attempts, solution);


    return 0;
}
