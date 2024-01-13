#include <stdio.h>
#include <stdlib.h>

int main() {
    int counter = 0;        // Loop counter
    char my_choice = 'C';   // Initial choice
    int countC = 0;         // Counter for consecutive 'C' occurrences

    // Print the initial choice and a new line
    putchar(my_choice);
    fflush(stdout);
    putchar('\n');
    fflush(stdout);

    int input = getchar(); // Read input
    while (counter != 1000000 && input != EOF) { // Loop until the maximum number of iterations or EOF

        if (input == 'C' || input == 'D') { // Check if the input is 'C' or 'D'

            my_choice = input;  // Update the choice based on input

            if (input == 'C')
                countC++;
            else 
                countC = 0;

            if(counter % 1000 == 0 && countC == 0)
                my_choice = 'C';  // Choose 'C' every 1000 iterations if there are no consecutive 'C's

            if (countC == 5) {
                countC = 0;
                my_choice = 'D';  // Choose 'D' if there are 5 consecutive 'C's
            }

            putchar(my_choice);
            fflush(stdout);
            putchar('\n');
            fflush(stdout);
            counter++;
        }

        input = getchar();
    }

    return 0;
}