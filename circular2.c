#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node * first = NULL;

void ins_beg(int value){
    struct node * t;
    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = value;
    if(first == NULL){
        ptr -> next = ptr;
        first = ptr;
    }
    else{
        t = first;
        while(t -> next != first){
            t = t -> next;
        }
        ptr -> next = first;
        first -> next = ptr;
        first = ptr;
    }
}
void ins_end(int value){
    struct node * t;
    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = value;
    if(first == NULL){
        ptr -> next = ptr;
        first = ptr;
    }
    else{
        t = first;
        while(t -> next != first){
            t = t-> next;
        }
        ptr -> next = first;
        t -> next = ptr;
    }
}
void del_beg(){
    printf("Deleted node is %d\n",first -> data);
    struct node * t;
    if(first == NULL){
        printf("EMPTY");
    }
    else if(first -> next == first){
        free(first);
        first = NULL;
    }
    else{
        t = first;
        while(t -> next != first){
            t = t-> next;
        }
        t -> next = first -> next;
        free(first);
        first = t -> next;
    }
}
void del_end(){
    printf("Deleted node is %d\n",first -> data);
    struct node * t;
    if(first == NULL){
        printf("EMPTY");
    }
    else if(first -> next == first){
        free(first);
        first = NULL;
    }
    else{
        t = first;
        while(t ->next-> next != first){
            t = t-> next;
        }
        free(t-> next);
        t -> next = first;
    }
}
void display(){
    struct node * t = first;
    if(first == NULL){
        printf("EMPTY list\n");
    }
    else{
        do{
            printf("%d\n",t->data);
            t = t-> next;
        }while(t != first);
    }
}
int main(){
    int option;
    while(1){
        printf("Enter number for what you want\n");
        printf("1) Insertion at beginning\n");
        printf("2) Insertion at ending\n");
        printf("3) delete first node\n");
        printf("4) delete last node\n");
        printf("5) traverse and display all nodes\n");
        printf("6) exit\n");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            int value;
            printf("Enter value you want to add in beginning: ");
            scanf("%d",&value);
            ins_beg(value);
            break;
        case 2:
            printf("Enter value you want to add in ending: ");
            scanf("%d",&value);
            ins_end(value);
            break;
        case 3:
            del_beg();
            break;
        case 4:
            del_end();
            break;
        case 5:
            display();
            break;
        case 6:
            return 0;
        default:
            break;
        }
    }
}