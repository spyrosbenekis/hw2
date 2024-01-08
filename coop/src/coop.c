#include <stdio.h>
#include <stdlib.h>

int main() {
    int counter = 0;
    char my_choice = 'C';
    int countC = 0;

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

            if (input == 'C')
                countC++;
            else 
                countC = 0;

            if (countC == 5){
                countC = 0;
                my_choice = 'D';
            }

            if (my_choice == 'D')
                flag = 1;
            else if (counter > 990 && flag == 0)
                my_choice = 'D';

            putchar(my_choice);
            fflush(stdout);
            putchar('\n');
            fflush(stdout);
            counter++;
        }

        if(my_choice == 'D')
            flag = 1;

        input = getchar();
    }

    return 0;
}