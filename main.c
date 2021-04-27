#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include<windows.h>                                           //library to use textcolors

#define MAX 255

void pick_solution(char* solution){                          //takes the pointer "solution" as parameter and picks a random word from a file and copies it into solution

    int i = 0;                                               //variable i is declared to later assign its value to the variable line_number to get the number of lines read
    int line_number;
    int random_number;


    FILE *the_file = fopen("words.txt", "r");                // declares which file to read
    if(the_file == NULL){                                    //if the file can't be opened print out an error message
        printf("Unable to open the file");
    }
    char line[20][200];                                      //declare array to store the words
    while(fgets(line[i], 200, the_file)){                    //read from the text document and store in array
        i++;
    }
    line_number = i;

    srand(time(NULL));                                      //initialize the random number generator

    random_number = rand() % line_number;                   //assigns a random number from 0 to the value of variable line_number to random_number

    strcpy(solution, line[random_number]);                  //copies a random word in the string solution
}




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
//function to show the end screen of the game. See if you lost or won and displays statistics
void show_win_loss_screen(char usedChars[], int attempts, int failed, int correct,char hiddenWord[], char solution[], int time_limit, unsigned long seconds) {


    int i;

    system("cls");
    printf("%lu seconds", seconds);
    if(seconds > time_limit){printf("test");}                                                     //clear the console
    if(strchr(hiddenWord, '_')|| seconds > time_limit){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);        //change the textcolor
    printf("\n\n____________________________________\n\n");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);        //change the textcolor
    printf("\n\nYou lost\n");

    if(seconds > time_limit){
        printf("You exceeded the time limit!\nTime Limit: %i minutes and %i seconds\nYour Time: %i minutes and %i seconds",time_limit/60,time_limit%60,seconds/60,seconds%60);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);        //change the textcolor
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
    printf("\n\nYour total guesses: %i", attempts);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);        //change the textcolor
    printf("\n\nYour correct guesses: %i\n",correct);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf("\nYour failed guesses: %i\n",failed);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);


    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);        //change the textcolor
    printf("\n\n____________________________________\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);        //reset the textcolor
    scanf("");

    }else{

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
    printf("\n\nYour total guesses: %i", attempts);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);        //change the textcolor
    printf("\n\nYour correct guesses: %i\n",correct);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf("\nYour failed guesses: %i\n",failed);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    printf("\nYour Time: %i minutes and %i seconds",seconds/60,seconds%60);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);        //change the textcolor
    printf("\n\n____________________________________\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);        //reset the textcolor
    scanf("");
    }
}

int main()
{
    char in;
    int t_input;
    char solution[MAX];
    char usedChars[MAX];
    char hiddenWord[MAX];
    int attempts = 0;
    int failed = 0;
    int correct = 0;
    int tries = 10;
    unsigned long start_time;
    unsigned long end_time;
    unsigned long seconds;
    int time_limit = 10;
    int seconds_formated = 0;
    int minutes = 0;
    int count = 0;
    int limit = 0;

    pick_solution(solution);
    convert_to_upper(solution);
    while(1){                                                                   //Loop runs as long as you make invalid inputs
        printf("Do you want to set a time Limit? Y/N\n");
        scanf("%c",&in);
        in = toupper(in);
        fflush(stdin);
        printf("%c\n",in);
        if(in == 'Y' || in == 'N'){                                             //checks if you want a time limit or not
            if(in == 'N'){
                time_limit = 9999999999999;                                     //if N time limit is set to 9999999999999 seconds
                system("cls");
                break;
            }else{
                system("cls");
                printf("Enter your time limit in seconds:\n");                  //lets you enter your time limit in seconds
                scanf("%i",&t_input);
                fflush(stdin);
                time_limit = t_input;                                           //sets time limit to your input
                system("cls");
                printf("Time Limit of: %i minutes and %i seconds\n\nYour Time starts at your first guess!\n\n",time_limit/60, time_limit%60); //shows your time limit
                break;
            }

        }else{
            system("cls");
        }
    }

    // REMOVE LATER!!!
    //_____________________________
    for(int i = 0; i<strlen(solution); i++){
        printf("%c",solution[i]);
    }
    printf("\n");
    //_____________________________



    for(int i = 0; i<strlen(solution); i++){                                    //bug here or at string value assignment: Peter works but Justus and Jonas seem to have an extra char at the end
        hiddenWord[i] = '_';
        printf("%c ",hiddenWord[i]);
    }
    printf("\n");

    while(tries != 0){
        printf("\nYou have %i tries left\n\n", tries);
        in = input(usedChars);
        if(count == 0){                                                         //starts the timer after your first input count makes sure it only happens once
            start_time = (unsigned long)time(NULL);                             //assigns the epoch time/Unix time to the variable start_time
            count++;
        }
        usedChars[attempts] = in;
         if(strchr(solution, in)){                                              //checks if your input char is in the solution string

                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);    //change the textcolor
                system("cls");                                                  //clear the console
                printf("You guessed correctly!!\n\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);    //reset the textcolor
                correct++;

                for(int i=0; i<strlen(hiddenWord);i++){
                    if(solution[i] == in){
                        hiddenWord[i] = in;                                     //replaces the "_" in hidden word with your input
                    }
                }
            }else{
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                system("cls");
                printf("Loser\n\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                failed++;
            }
        for(int i = 0; i<strlen(solution); i++){
        printf("%c ",hiddenWord[i]);
        }
        attempts++;
        show_used_chars_and_attempts(usedChars, attempts);
        tries--;
        end_time = (unsigned long)time(NULL);                                   //assigns the epoch time/Unix time to the variable end_time
        minutes = (end_time - start_time)/60;                                   //converts epoch time into minutes
        seconds_formated = (end_time - start_time)%60;                          //calculates the remaining seconds after minute conversion
        seconds = end_time - start_time;                                        //calculates time passed in seconds
        if(seconds >= time_limit){                                              //if the time limit is exceeded end the loop
        break;
    }
        if(strchr(hiddenWord, '_') == 0){                                       // if the hidden word string no longer contains "_" end the loop
           break;
        }
    }

    show_win_loss_screen(usedChars, attempts, failed, correct, hiddenWord, solution, time_limit, seconds);


    return 0;
}
