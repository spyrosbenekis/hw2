#include <stdio.h>
#include <stdlib.h>

int main() {
    int counter = 0;
    char my_choice = 'C';

    putchar(my_choice);
    putchar('\n');

    int input = getchar();
    while (counter != 1000000 && input != EOF) {

        if (input == EOF)
            break;

        if (input == 'C' || input == 'D') {

            my_choice = input;

            putchar(my_choice);
            putchar('\n');

            counter++;
        }
        else
            fflush(stdout);
    }

    return 0;
}