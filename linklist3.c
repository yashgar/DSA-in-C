#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

int count(struct node * ptr ){
    int node = 0;
    while(ptr != NULL){
        ptr = ptr -> next;
        node = node + 1;
    }
    return node;
}

int array(struct node * head , int n){
    int len = count(head);
    int arr[len];
    struct node* t = head;
    int i = 0;
    while(t != NULL){
        arr[i] = t-> data;
        i++;
        t = t-> next;
    }
    for(int j = 0; j < len; j++){
        printf("%d\n",arr[j]);
    }
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
struct node * new(struct node * head){
    struct node * t = head;
    struct node * p;
    while(t != NULL){
        insert_end(p,t-> data);
        t = t -> next;
    }
    return head;
}
void display(struct node * ptr){
    while(ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr -> next;
    }
}
struct node * insert_beg(struct node * head, int data){
    struct node* ptr = (struct node *) malloc(sizeof(struct node));
    ptr -> next = head;
    ptr -> data = data;
    return ptr;
}
struct node * rev(struct node * head){
    struct node * t = head;
    struct node * p = NULL;
    while(t != NULL){
        p = insert_beg(p,t-> data);
        t = t -> next;
    }
    return p;
}
int main(){
    struct node * head;
    struct node * second;
    struct node * third;
    struct node * forth;
    head = (struct node *) malloc(sizeof(struct node));
    second = (struct node *) malloc(sizeof(struct node));
    third = (struct node *) malloc(sizeof(struct node));
    forth = (struct node *) malloc(sizeof(struct node));
    head -> data = 5;
    head -> next = second;
    second -> data = 4;
    second -> next = third;
    third -> data = 7;
    third -> next = forth;
    forth -> data = 8;
    forth -> next = NULL;
    array(head, count(head));
    display(new(head));
    display((rev(head)));
    return 0;
}