#include <stdio.h>
#include <stdlib.h>

int main() {
    int score = 0, counter = 0;
    char my_choice = 'C';

    putchar(my_choice);
    putchar('\n');

    while (counter != 1000000) {
        int input = getchar();

        if (input == EOF)
            break;

        char choice = (char)input;

        if (choice == 'C' || choice == 'D') {
            if (choice == 'C') {
                if (my_choice == 'D')
                    score += 5;
                else
                    score += 3;
            } else if (choice == 'D') {
                if (my_choice == 'D')
                    score += 1;
            }

            my_choice = choice;

            putchar(my_choice);
            putchar('\n');
        } else {
            fflush(stdin);
        }

        counter++;
    }

    putchar(score);
    putchar('\n');

    return 0;
}