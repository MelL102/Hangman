#ifndef HANGMAN_H_INCLUDED
#define HANGMAN_H_INCLUDED

void print_hangman(int failed)
void pick_solution(char* solution)
void show_used_chars_and_attempts(char usedChars[], int attempts)
void convert_to_upper(char solution[])
char input(char usedChars[])
void show_win_loss_screen(char usedChars[], int attempts, int failed, int correct,char hiddenWord[], char solution[], long time_limit, unsigned long seconds)
char get_user(int input_user)
void show_users()
void create_user(char username[])

#endif // HANGMAN_H_INCLUDED

