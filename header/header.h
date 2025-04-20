#ifndef FUNCTION_H
#define FUNCTION_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct List {
    char field;
    struct List *ptr;
};
struct Queue {
    struct List *first, *last;
};
int input_Number(int*);
void initQ(struct Queue*);
int isemptyQ(struct Queue*);
struct List *init_Char(char);
void pushQ(struct Queue*, char);
char popQ(struct Queue*);
char viewQ(struct Queue*);
void Queue();
//////////////////////////////////

struct Node {
    char symbol;
    struct Node *prev, *next;
};
struct Deque {
    struct Node *front, *back;
};
void initD(struct Deque*);
int isemptyD(struct Deque *);
void pushD_front(struct Deque *, char);
void pushD_back(struct Deque *, char);
char popD_front(struct Deque *);
char popD_back(struct Deque *);
void freeD(struct Deque *);
void Deque();

struct ListS {
    char* field;
    struct ListS *ptr;
};
struct QueueString {
    struct ListS *first, *last;
};
char* input_string(int* len_str);
void pushQS(struct QueueString *, char*);
char* popQS(struct QueueString *);
char* viewQS(struct QueueString *); 
void freeQS(struct QueueString *);
void Namein_Queue();

#endif

///////////////////////////

int input_Number(int* number) {
    rewind(stdin);
    *number = 0;
    int digit, sign = 1, started = 0;
    while ((digit = getchar()) != '\n' && digit != ' ') {
        if (digit == '-') {
            sign = -1;
        } else if (digit < '0' || digit > '9') {
            printf("Incorrect number\n");
            while ((digit = getchar()) != '\n' && digit != ' ');
            *number = 0;
            return -1;
        } else {
            started = 1;
            *number = *number * 10 + (digit - '0');
        }
    }
   return started ? *number * sign : 0;
}
void initQ(struct Queue *q){
    q->first = NULL;
    q->last = NULL;
}
int isemptyQ(struct Queue *q){
    if(q->first == NULL){
        return 1;
    } 
    else return 0;
}
struct List *init_Char(char x){
    struct List *tmp;
    tmp = (struct List*)malloc(sizeof(struct List));
    tmp->field = x;
    tmp->ptr = NULL;
    return (tmp);
}
void pushQ(struct Queue *q, char x) {
    struct List *tmp = init_Char(x);
    if (isemptyQ(q)) {
        q->first = q->last = tmp;
    } else {
        q->last->ptr = tmp;  
        q->last = tmp;        
    }
}
char popQ(struct Queue *q) {
    if (isemptyQ(q)) {
        printf("Error: Queue underflow!\n");
        return '\0';
    }
    
    struct List *tmp = q->first;
    char value = tmp->field;
    
    q->first = q->first->ptr;
    if (q->first == NULL) {
        q->last = NULL;
    }
    
    free(tmp);
    return value;
}
char viewQ(struct Queue *q) {
    if (isemptyQ(q)) {
        printf("Queue is empty!\n");
        return '\0'; 
    }
    return q->first->field;
}

////////////////////

void initD(struct Deque *dq) {
    dq->back = NULL;
    dq->front = NULL;
}
int isemptyD(struct Deque *dq) {
    if(dq->front == NULL) {
        return 1;
    }
    else return 0;
}
void pushD_front(struct Deque *dq, char x) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->symbol = x;
    newNode->next = dq->front;
    newNode->prev = NULL;

    if(dq->front != NULL) {
        dq->front->prev = newNode;
    } 
    else {
        dq->back = newNode;
    }
    dq->front = newNode;
}
void pushD_back(struct Deque *dq, char x) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->symbol = x;
    newNode->prev = dq->back;
    newNode->next = NULL;

    if(dq->back != NULL) {
        dq->back->next = newNode;
    } 
    else {
        dq->front = newNode;
    }
    dq->back = newNode;
}
char popD_front(struct Deque *dq) {
    if(dq->front == NULL) {
        return -1;
    }
    struct Node *tmp = dq->front;
    char value = tmp->symbol;
    dq->front = dq->front->next;
    if(dq->front != NULL) {
        dq->front->prev = NULL;
    }
    else {
        dq->back = NULL;
    }
    free(tmp);
    return value;
}
char popD_back(struct Deque *dq) {
    if(dq->back == NULL) {
        return -1;
    }
    struct Node *tmp = dq->back;
    char value = tmp->symbol;
    dq->back = dq->back->prev;
    if(dq->back != NULL) {
        dq->back->next = NULL;
    }
    else {
        dq->front = NULL;
    }
    free(tmp);
    return value;
}
void freeD(struct Deque *dq) {
    while(dq->front != NULL) {
        popD_front(dq);
    }
    free(dq);
}

////////////////////

void initQS(struct QueueString *q){
    q->first = NULL;
    q->last = NULL;
}
int isemptyQS(struct QueueString *q) {
    return q == NULL || q->first == NULL;
}
char* input_string(int* len_str) {
    *len_str = 0;
    int capacity = 1; 
    char* s = (char*)malloc(capacity * sizeof(char)); 

    char c; 
    while ((c = getchar()) != '\n') {
        if (*len_str + 1 >= capacity) {
            capacity *= 2;
            s = realloc(s, capacity * sizeof(char));
        }

        s[(*len_str)++] = c;
    }
    s[(*len_str)] = '\0';

    return s;
}
struct ListS *init_CharString(char* x){
    struct ListS *tmp;
    tmp = (struct ListS*)malloc(sizeof(struct ListS));
    tmp->field = strdup(x);
    if (!tmp->field) {
        free(tmp);
        return NULL;
    }

    tmp->ptr = NULL;
    return tmp;
}
void pushQS(struct QueueString *q, char* x){
    if((q->first == 0) && (q->last == 0)){
        q->last = init_CharString(x);
        q->first = q->last;
    }
}
char* popQS(struct QueueString *q) {
    if (isemptyQS(q)) {
        return NULL;
    }
    struct ListS *tmp = q->first;
    char* string = tmp->field; 
    q->first = q->first->ptr;
    if (q->first == NULL) {
        q->last = NULL;
    }
    free(tmp);
    return string;
}
char* viewQS(struct QueueString *q){
    return q->first->field;
}
void freeQS(struct QueueString *q) {
    if (!q) return;
    
    while (!isemptyQ(q)) {
        char* s = popQS(q);
        free(s);
    }
}

