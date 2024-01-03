#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int score = 0, counter = 0;
    char my_choice='C', choice;

    putchar(my_choice);
    putchar('\n');

    while((choice=getchar())!=EOF && counter!=1000000){

        if(choice=='C'){
            if(my_choice=='D')
                score+=5;
            else
                score+=3;

            my_choice = choice;

            putchar(my_choice);
            putchar('\n');
        }
        else if(choice=='D'){

            if(my_choice=='D')
                score += 1;
        
            my_choice = choice;

            putchar(my_choice);
            putchar('\n');
        }
        counter++;
    }

    putchar(score);
    putchar('\n');

    return 0;
}