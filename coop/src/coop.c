// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     int score = 0, counter = 0;
//     char my_choice = 'C';

//     putchar(my_choice);
//     putchar('\n');

//     while (counter != 1000000) {
//         int input = getchar();

//         if(input == EOF)
//             break;

//         if (input == 'C' || input == 'D') {
//             if (input == 'C') {
//                 if (my_choice == 'D')
//                     score += 5;
//                 else
//                     score += 3;
//             } else if (input == 'D') {
//                 if (my_choice == 'D')
//                     score += 1;
//             }

//             my_choice = input;

//             putchar(my_choice);
//             putchar('\n');

//             counter++;
//         } 
//         // else
//         //     fflush(stdin);
//     }

//     putchar(score);
//     putchar('\n');

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

int main() {
    int score = 0, counter = 0;
    char my_choice = 'C';

    putchar(my_choice);
    putchar('\n');

    while (counter != 1000000) {
        int input;

        do {
            input = getchar();
        } while (input != 'C' && input != 'D' && input != EOF);

        if (input == EOF)
            break;

        if (input == 'C' || input == 'D') {
            if (input == 'C') {
                if (my_choice == 'D')
                    score += 5;
                else
                    score += 3;
            } else if (input == 'D') {
                if (my_choice == 'D')
                    score += 1;
            }

            my_choice = input;

            putchar(my_choice);
            putchar('\n');

            counter++;
        }
    }

    printf("%d\n", score);

    return 0;
}