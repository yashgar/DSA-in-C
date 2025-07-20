//Q1 & Q2//
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
void push(int stack[], int *top){
    int element;
    if(*top == MAXSIZE - 1){
        printf("\nStack overflow!");
    }
    else
    {
        printf("\nEnter the element to be pushed: ");
        scanf("%d", &element);
        *top += 1;
        stack[*top] = element;
        printf("\nElement pushed successfully!");
    }
}
void pop(int stack[], int *top)
{
    if (*top == -1){
        printf("\nStack underflow!");
    }
    else
    {
    printf("\nPopped element: %d", stack[*top]);
    *top -= 1;
    }
}
void peek(int stack[], int *top)
{
    if (*top == -1){
        printf("\nStack is empty!");
    }
    else{
        printf("\nTop element: %d", stack[*top]);
    }
}
void display(int stack[], int *top)
{
    int i;
    if (*top == -1){
        printf("\nStack is empty!");
    }
    else{
        printf("\nStack elements: ");
        for (i = *top; i >= 0; i--){
            printf("%d ", stack[i]);
        }
    }    
}
int main(){
    int stack[MAXSIZE], top = -1;
    int choice;
    do{
    printf("\n1. Push element");
    printf("\n2. Pop element");
    printf("\n3. Peek element");
    printf("\n4. Display stack");
    printf("\n5. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            push(stack, &top);
            break;
        case 2:
            pop(stack, &top);
            break;
        case 3:
            peek(stack, &top);
            break;
        case 4:
            display(stack, &top);
            break;
        case 5:
            printf("\nExiting the program...");
            break;
        default:
        printf("\nInvalid choice! Try again.");
    }
    } while (choice != 5);
    return 0;
}
//Q3//
#include <stdlib.h>
#include <stdio.h>
#define MAXSIZE 10

void push(char stack[], int *top, char element)
{
    if (*top == MAXSIZE - 1){
        printf("\nStack overflow!");
    }
    else{
        *top += 1;
        stack[*top] = element;
        printf("\nElement pushed successfully!");
    }
}
char pop(char stack[], int *top)
{
    char element;
    if (*top == -1){
        printf("\nStack underflow!");
        return '\0';
    }
    else{
        element = stack[*top];
        *top -= 1;
        return element;
    }
}
void RevcopyStack(char stack1[], int top1, char stack2[], int *top2){
    int i;
    if (top1 == -1){
        printf("\nStack1 is empty!");
    }
    else{
        *top2 = -1;
        for (i = top1; i >= 0; i--){
            push(stack2, top2, stack1[i]);
        }
        printf("\nStack1 copied into Stack2 successfully!");
    }
}
void display(char stack[], int top)
{
    int i;
    if (top == -1){
        printf("\n Stack is Empty!");
    }
    else
    {
        printf("\nStack elements: ");
        for (i = top; i >= 0; i--){
            printf("%c ", stack[i]);
        }
    }
}
int main(){
    char stack1[MAXSIZE], stack2[MAXSIZE];
    int top1 = -1, top2 = -1;
    char element;
    int choice;
    do{
        printf("\n1. Push element");
        printf("\n2. Reverse - Copy stack");
        printf("\n3. Display Original Stack");
        printf("\n4. Display Reversed Stack");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            printf("\nEnter the element to be pushed: ");
            scanf(" %c", &element);
            push(stack1, &top1, element);
            break;
        case 2:
            copyStack(stack1, top1, stack2, &top2);
            break;
        case 3:
            display(stack1, top1);
            break;
        case 4:
            display(stack2, top2);
            break;
        case 5:
            printf("\nExiting the program...");
            break;
        default:
            printf("\nInvalid choice! Try again.");
        }
    } while (choice != 5);
    return 0;
}