#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};
struct node * last = NULL;
void push(int data){
    struct node * p;
    p =(struct node *)malloc(sizeof(struct node));
    p -> data = data;
    p -> next = NULL;
    if(last == NULL){
        last = p;
    }
    else{
        while(last -> next != NULL){
            last = last -> next;
        }
        last -> next = p;
    }
}
int main(){
    int ch, data;
    while(1){
        printf("Enter your choice: \n");
        printf("1) Push\n");
        printf("2) Pop\n");
        printf("3) Display\n");
        printf("4) Exit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter data you want to insert");
            scanf("%d",&data);
            
            break;
        
        default:
            break;
        }
    }
}