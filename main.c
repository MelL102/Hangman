#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include<windows.h>                                             //library to use textcolors

#define MAX 255

int main()
{
    char in;
    int t_input;
    char solution[MAX];
    char usedChars[MAX] = {0};
    char hiddenWord[MAX];
    int attempts = 0;
    int failed = 0;
    int correct = 0;
    int tries = 10;
    unsigned long start_time;
    unsigned long end_time;
    unsigned long seconds;
    long time_limit = 10;
    int seconds_formated = 0;
    int minutes = 0;
    int count = 0;
    //int limit = 0;
    char username[255];

    printf("Please enter your username: \n");
    scanf("%s", &username);                                                     //get the username from the console input

    pick_solution(solution);
    convert_to_upper(solution);
    while(1)                                                                    //Loop runs as long as you make invalid inputs
    {
        printf("Do you want to set a time Limit? Y/N\n");
        scanf("%c",&in);
        in = toupper(in);
        fflush(stdin);
        printf("%c\n",in);
        if(in == 'Y' || in == 'N')                                              //checks if you want a time limit or not
        {
            if(in == 'N')
            {
                time_limit = 99999999;                                     //if N time limit is set to 9999999999999 seconds
                system("cls");
                break;
            }
            else
            {
                system("cls");
                printf("Enter your time limit in seconds:\n");                  //lets you enter your time limit in seconds
                scanf("%i",&t_input);
                fflush(stdin);
                time_limit = t_input;                                           //sets time limit to your input
                system("cls");
                printf("Time Limit of: %li minutes and %li seconds\n\nYour Time starts at your first guess!\n\n",time_limit/60, time_limit%60); //shows your time limit
                break;
            }

        }
        else
        {
            system("cls");
        }
    }

    // REMOVE LATER!!!
    //_____________________________
    for(int i = 0; i<strlen(solution); i++)
    {
        printf("%c",solution[i]);
    }
    printf("\n");
    //_____________________________



    for(int i = 0; i<strlen(solution); i++)
    {
        hiddenWord[i] = '_';
        printf("%c ",hiddenWord[i]);
    }
    printf("\n");

    while(tries != 0)
    {
        printf("\nYou have %i tries left\n\n", tries);
        in = input(usedChars);
        if(count == 0)                                                          //starts the timer after your first input count makes sure it only happens once
        {
            start_time = (unsigned long)time(NULL);                             //assigns the epoch time/Unix time to the variable start_time
            count++;
        }
        usedChars[attempts] = in;
        if(strchr(solution, in))                                               //checks if your input char is in the solution string
        {

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);    //change the textcolor
            system("cls");                                                  //clear the console
            printf("You guessed correctly!!\n\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);    //reset the textcolor
            correct++;
            print_hangman(failed);

            for(int i=0; i<strlen(hiddenWord); i++)
            {
                if(solution[i] == in)
                {
                    hiddenWord[i] = in;                                     //replaces the "_" in hidden word with your input
                }
            }
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            system("cls");
            printf("Loser\n\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            failed++;
            print_hangman(failed);
        }
        for(int i = 0; i<strlen(solution); i++)
        {
            printf("%c ",hiddenWord[i]);
        }
        attempts++;
        show_used_chars_and_attempts(usedChars, attempts);
        tries--;
        end_time = (unsigned long)time(NULL);                                   //assigns the epoch time/Unix time to the variable end_time
        minutes = (end_time - start_time)/60;                                   //converts epoch time into minutes
        seconds_formated = (end_time - start_time)%60;                          //calculates the remaining seconds after minute conversion
        seconds = end_time - start_time;                                        //calculates time passed in seconds
        if(seconds >= time_limit)                                               //if the time limit is exceeded end the loop
        {
            break;
        }
        if(strchr(hiddenWord, '_') == 0)                                        // if the hidden word string no longer contains "_" end the loop
        {
            break;
        }
    }

    show_win_loss_screen(usedChars, attempts, failed, correct, hiddenWord, solution, time_limit, seconds);


    return 0;
}
