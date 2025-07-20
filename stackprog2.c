//Q1. Create a C program to convert infix expression to postfix expression.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 10
char stack[MAX_SIZE];
int top = -1;
void push(char);
char pop();
int isOperator(char);
int precedence(char);
void infixToPostfix(char[], char[]);
int main(){
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Enter infix expression: ");
    gets(infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s", postfix);
    return 0;
}
void push(char value)
{
 if(top == MAX_SIZE - 1)
 {
 printf("\nStack overflow. Cannot push element.");
 }
 else
 {
 top++;
 stack[top] = value;
 }
}
char pop()
{
 if(top == -1)
 {
 printf("\nStack underflow. Cannot pop element.");
 return '\0';
 }
 else
 {
 char value = stack[top];
 top--;
 return value;
 }
}
int isOperator(char ch)
{
 if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
 {
 return 1;
 }
 else
 {
 return 0;
 }
}
int precedence(char op)
{
 switch(op)
 {
 case '+':
 case '-':
 return 1;
 case '*':
 case '/':
 return 2;
 case '^':
 return 3;
 default:
 return -1;
 }
}
void infixToPostfix(char infix[], char postfix[])
{
 int i, j;
 for(i = 0; infix[i] != '\0'; i++)
 {
 postfix[i] = ' ';
 }
 postfix[i] = '\0';
 i = j = 0;
 while(infix[i] != '\0')
 {
 if(infix[i] == '(')
 {
 push(infix[i]);
 i++;
 }
 else if(infix[i] == ')')
 {
 while(stack[top] != '(')
 {
 postfix[j] = pop();
 j++;
 }
 pop();
 i++;
 }
 else if(isdigit(infix[i]) || isalpha(infix[i]))
 {
 postfix[j] = infix[i];
 j++;
 i++;
 }
 else if(isOperator(infix[i]))
 {
 while(top != -1 && precedence(infix[i]) <= precedence(stack[top]))
 {
 postfix[j] = pop();
 j++;
 }
 push(infix[i]);
 i++;
 }
 else
 {
 i++;
 }
 }
 while(top != -1)
 {
 postfix[j] = pop();
 j++;
 }
 postfix[j] = '\0';
}

//Q2. Create a C program to evaluate the given postfix expression
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 100
int stack[MAX_SIZE];
int top = -1;
void push(int x) {
 if (top >= MAX_SIZE - 1) {
 printf("Stack overflow\n");
 exit(1);
 }
 stack[++top] = x;
}
int pop() {
 if (top == -1) {
 printf("Stack underflow\n");
 exit(1);
 }
 return stack[top--];
}
int evaluatePostfix(char *postfix) {
 int i, x, y;
 char ch;
 for (i = 0; postfix[i] != '\0'; i++) {
 ch = postfix[i];
 if (isdigit(ch)) {
 push(ch - '0');
 } else {
 y = pop();
 x = pop();
 switch (ch) {
 case '+':
 push(x + y);
 break;
 case '-':
 push(x - y);
 break;
 case '*':
 push(x * y);
 break;
 case '/':
 push(x / y);
 break;
 case '%':
 push(x % y);
 break;
 default:
 printf("Invalid operator\n");
 exit(1);
 }
 }
 }
 return pop();
}
int main() {
 char postfix[MAX_SIZE];
 printf("Enter postfix expression: ");
 gets(postfix);
 int result = evaluatePostfix(postfix);
 printf("Result = %d\n", result);
 return 0;
}