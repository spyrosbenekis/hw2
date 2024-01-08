#include <stdio.h>
#include <stdlib.h>

int main() {
    int counter = 0;
    char my_choice = 'C';

    putchar(my_choice);
    fflush(stdout);
    putchar('\n');
    fflush(stdout);

    int flag = 0;

    int input = getchar();
    while (counter != 1000 && input != EOF) {

        if (input == EOF)
            break;

        if (input == 'C' || input == 'D') {

            my_choice = input;

            if(counter == 999 && flag == 0)
                my_choice = 'D';

            putchar(my_choice);
            fflush(stdout);
            putchar('\n');
            fflush(stdout);
            counter++;
        }

        if(my_choice == 'D')
            flag = 1;
    }

    return 0;
}