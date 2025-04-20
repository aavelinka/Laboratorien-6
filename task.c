
void Queue(){
    struct Queue *Queue = (struct Queue*)malloc(sizeof(struct Queue));
    int number = 0;
    initQ(Queue);
    while(number <= 0) {
        puts("Please, enter the amout of the elements for Queue: ");
        if(input_Number(&number) < 0) {
            puts("You need to enter the namber > 0.\n Try again.");
            continue;
        }
    }
    char reapet_x;
    int flag = 0;
    for(int i = 0; i < number; ++i) {
        char x;
        printf("Enter %d elements: ", (i + 1));
        scanf(" %c", &x);
        if(x == reapet_x && flag != 0) {
            puts("Elements from Queue:");
            for(int j = 0; j < i; ++j) {
                printf("The (%d)'s - %c\n", j + 1, popQ(Queue));
            }
            printf("Queue size is %d\n", i);
            return;
        }
        pushQ(Queue, x);
        reapet_x = x;
        flag++;
    }
    int i = 1;
    while (!isemptyQ(Queue)) {
        printf("Element %d: %c\n", i, popQ(Queue));
        i++;
    }
}

void Deque(){    
    struct Deque *Deque = (struct Deque*)malloc(sizeof(struct Deque));
    int number = 0;
    initD(Deque);
    while(number <= 0) {
        puts("Please, enter the amout of the elements for Deque: ");
        if(input_Number(&number) < 0) {
            puts("You need to enter the namber > 0.\n Try again.");
            rewind(stdin);
            continue;
        }
    }
    int flag = 0;
    do {
        printf("How do you want to write the elements?\n");
        printf("1. Add to front;\n");
        printf("2. Add to end;\n");
        printf("3. Select element placement each time;\n");
        char option;
        scanf(" %c", &option);

        char reapet_x, front_x, back_x;
        int push;
        switch(option)
        {
            case '1':
                for(int i = 0; i < number; ++i) {
                    char x;
                    printf("Enter %d elements: ", (i + 1));
                    scanf(" %c", &x);
                    if(i == 0) {
                        back_x = x;
                    }
                    if(i != 0 && (reapet_x == x || back_x == x)) {
                        puts("Elements from Deque:");
                        for(int j = 0; j < i; ++j) {
                            printf("The %d's - %c\n", j + 1, popD_front(Deque));
                        }
                        printf("Deque size is %d.\n", i);
                        return;
                    }
                    pushD_front(Deque, x); 
                    reapet_x = x; 
                }
                break;
            case '2':
                for(int i = 0; i < number; ++i) {
                    char x;
                    printf("Enter %d elements: ", (i + 1));
                    scanf(" %c", &x);
                    if(i == 0) {
                        front_x = x;
                    }
                    if(i != 0 && (reapet_x == x || front_x == x)) {
                        puts("Elements from Deque:");
                        for(int j = 0; j < i; ++j) {
                            printf("The %d's - %c\n", j + 1, popD_front(Deque));
                        }
                        printf("Deque size is %d.\n", i);
                        return;
                    }
                    pushD_back(Deque, x);
                    reapet_x = x; 
                }   
                break;
            case '3':
            for(int i = 0; i < number; ++i) {
                char x;
                printf("Push to front - 0, back - 1: \n");
                scanf(" %d", &push);
                if(push == '0') {
                    printf("Enter %d elements: ", (i + 1));
                    scanf(" %c", &x);
                    pushD_front(Deque, x); 
                } 
                else if(push == '1') {
                    printf("Enter %d elements: ", (i + 1));
                    scanf(" %c", &x);
                    pushD_back(Deque, x);
                }
                else {
                    printf("Oh! There is no this choice, try again.\n");
                    i--;
                    continue;
                }
            }
                break;
            default:
                printf("Oh! There is no this choice, try again.\n");
                flag = -1;
                break;
        }
    } while (flag == -1);
    
    do {
        printf("Watch Deque from the beginning - 0, from the end - 1: ");
        scanf(" %d", &flag);
        if(flag == '0'){
            for(int i = 0; i < number; ++i) {
                printf("Elements %d: %c", i + 1, popD_front(Deque));
            }
        }
        else if(flag == '1') {
            for(int i = 0; i < number; ++i) {
                printf("Elements %d: %c", --number, popD_back(Deque));
            }
        }
        else {
            printf("Oh! There is no this choice, try again.\n");
            flag = -1;
        }
    } while(flag == -1);
    free(Deque);
}

void Namein_Queue() {
    struct QueueString *QueueString = (struct QueueString*)malloc(sizeof(struct QueueString));
    initQS(QueueString);
    int len_str;
    printf("Please, enter the String: ");
    rewind(stdin);
    char* string = input_string(&len_str);

    if (!string) {
        free(QueueString);
        return;
    }
    
    int has_names = 0;
    for(int i = 0; i < len_str; ++i) {
        if(string[i] >= 'A' && string[i] <= 'Z') {
            char single_char_str[2] = {string[i], '\0'};
            pushQS(QueueString, &string[i]);
            has_names++;
        } 
    }
    if (!has_names) {
        printf("There are no names in the line.\n");
        free(string);
        freeQS(QueueString);
        return;
    }

    int i = 0;
    while(!isemptyQS(QueueString)) {
        puts("Elements from Queue:");
        printf("The %d's - %s;\n", i + 1, popQS(QueueString));
    }
    free(string);
    free(QueueString);
}
