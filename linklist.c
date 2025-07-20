#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node * insert_beg(struct node * head, int data){
    struct node* ptr = (struct node *) malloc(sizeof(struct node));
    ptr -> next = head;
    ptr -> data = data;
    head = ptr;
    return head;
}
struct node * insert_end(struct node * head ,int data){
    struct node* ptr = (struct node *) malloc(sizeof(struct node));
    ptr -> data = data;
    struct node * p = head;
    while(p-> next != NULL){
        p = p-> next;
    }
    p-> next = ptr;
    ptr -> next = NULL;
    return head;
}
void display(struct node * ptr){
    while(ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr -> next;
    }
}
void search(struct node * ptr ,int value){
    int node = 0;
    while(ptr -> data != value){
        ptr = ptr -> next;
        node = node + 1;
    }
    printf("node index is %d\n",node);
}
int main(){
    int option;
    struct node * head;
    struct node * second;
    struct node * third;
    head = (struct node *) malloc(sizeof(struct node));
    second = (struct node *) malloc(sizeof(struct node));
    third = (struct node *) malloc(sizeof(struct node));
    head -> data = 5;
    head -> next = second;
    second -> data = 7;
    second -> next = third;
    third -> data = 9;
    third -> next = NULL;
    printf("Enter number for what you want\n");
    printf("1) Insert in beginning\n");
    printf("2) Insert in ending\n");
    printf("3) display the list\n");
    printf("4) Search for an enlement\n");
    printf("5) Exit\n");
    scanf("%d",&option);
    switch (option)
    {
    case 1:
        int value;
        printf("Enter value you want to add in beginning: ");
        scanf("%d",&value);
        head = insert_beg(head , value);
        display(head);
        break;
    case 2:
        printf("Enter value you want to add in ending: ");
        scanf("%d",&value);
        head = insert_end(head , value);
        display(head);
        break;
    case 3:
        display(head);
        break;
    case 4:
        printf("Enter value you want to serach: ");
        scanf("%d",&value);
        search(head,value);
        break;
    case 5:
        break;
    default:
        break;
    }
}