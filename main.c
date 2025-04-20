//Климова, 12 вариант, 18.04.25
#include "header.h"

int main(){
    printf("Hi!\nLet's see what I can offer you today ;)\n");
    char repeat;
    do
    {
        rewind(stdin);
        printf("Please, enter task number:\n");
        printf("1. Create a queue for characters.\n");
        printf("(The last character and the input character match, output the queue size)\n");
        printf("2. Create a deque for characters.\n");
        printf("3. Enter a line containing names.\n");
        char option;
        scanf("%c", &option);

        switch(option)
        {
            case '1':
                Queue();   
                break;
            case '2':
                Deque();
                break;
            case '3':
                Namein_Queue();
                break;
            default:
                printf("Oh! There is no this task, try again\n");
                break;
        }
        rewind(stdin);

        puts("Do you want repeat? YES - 1, NO - 0");
        scanf("%c", &repeat);
        
    } while (repeat == '1');
    
    puts("Good job, dear! See you later <3");
    return 0;
}
