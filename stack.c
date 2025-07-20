#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node * top = NULL;
void push(int data){
    struct node * p;
    p = (struct node *)malloc(sizeof(struct node));
    p -> data = data;
    p -> next = NULL;
    if(top == NULL){
        top = p;
    }
    else{
        p -> next = top;
        top = p;
    }
}
int pop(){
    int d;
    if(top == NULL){
        printf("no element is in stack");
        return(-99);
    }
    else{
        struct node * t = top;
        top = top -> next;
        d = t -> data;
        free(t);
        return(d);
    }
}
void display(struct node * ptr){
    while(ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr -> next;
    }
}
int main(){
    int data;
    int ch;
    int d;
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
            printf("Enter data you want to insert ");
            scanf("%d",&data);
            push(data);
            break;
        case 2:
            d = pop();
            if(d != -99){
                printf("popped element is: %d\n",d);
            }
            else{
                printf("Empty list");
            }
            break;
        case 3:
            display(top);
            break;
        case 4:
            return 0;
        default:
            break;
        }
    }
}