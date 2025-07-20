#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
    struct node* prev;
};

struct node * head = NULL;

void ins_beg(int value){
    
}
void display(){
    struct node * t = head;
    if(head == NULL){
        printf("EMPTY LIST");
    }
    else{
        do{
            printf("%d\n",t->data);
            t = t-> next;
        }while(t != head);
    }    
}