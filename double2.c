#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
    struct node * prev;
};
int count(struct node * ptr ){
    int node = 0;
    while(ptr != NULL){
        ptr = ptr -> next;
        node = node + 1;
    }
    return node;
}
void display(struct node * ptr){
    while(ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr -> next;
    }
}
struct node * ins_beg(struct node * head, int data){
    struct node * p;
    p =(struct node *)malloc(sizeof(struct node));
    p -> data = data;
    p -> next = head;
    p -> prev = NULL;
    head = p;
    return head;
}
struct node * ins_end(struct node * head, int data){
    struct node * p;
    struct node * t = head;
    p =(struct node *)malloc(sizeof(struct node));
    p -> data = data;
    while(t-> next != NULL){
        t = t -> next;
    }
    t -> next = p;
    p -> prev = t;
    p -> next = NULL;
    return head;
}
struct node * new(struct node * head){
    struct node * t = head;
    struct node * head2 = NULL;
    while(t != NULL){
        if(head2 == NULL){
            head2 = ins_beg(head2, t->data);
        }
        else{
            head2 = ins_end(head2, t-> data);
        }
        t = t -> next;
    }
    return head2;
}
struct node * longest(struct node * head1, struct node * head2){
    int a = count(head1);
    int b = count(head2);
    if(a>b){
        return head1;
    }
    else if(b>a){
        return head2;
    }
}
struct node * odd(struct node * head){
    struct node * ptr = head;
    struct node * head2;
    while(ptr != NULL)
    {
        if((ptr -> data)%2 != 0){
            head2 = ins_beg(head2,ptr -> data);
        }
        ptr = ptr -> next;
    }
    display(head2);
}
struct node * merge(struct node * head1, struct node * head2){
    struct node * t = head2;
    while(t != NULL){
        head1 = ins_end(head1, t -> data);
        t = t -> next;
    }
    return head1;
}

int main(){
    struct node * head;
    struct node * first;
    struct node * second;
    struct node * head2;
    struct node * first2;
    head =(struct node *)malloc(sizeof(struct node));
    first =(struct node *)malloc(sizeof(struct node));
    second =(struct node *)malloc(sizeof(struct node));
    head2 =(struct node *)malloc(sizeof(struct node));
    first2 =(struct node *)malloc(sizeof(struct node));

    head -> prev = NULL;
    head -> data = 5;
    head -> next = first;

    first -> prev = head;
    first -> data = 7;
    first -> next = second;

    second -> prev = first;
    second -> data = 6;
    second -> next = NULL;

    head2 -> prev = NULL;
    head2 -> data = 5;
    head2 -> next = first2;

    first2 -> prev = head2;
    first2 -> data = 7;
    first2 -> next = NULL;

    printf("new head2 from initial head\n");
    head2 = new(head);
    display(head2);

    printf("TO find the longest\n");
    longest(head, head2);

    printf("odd numbers in a list");
    odd(head);

    struct node * headn = longest(head, head2);
    if (headn == head){
        head = merge(head, head2);
        display(head);
    }
    else if(headn == head2){
        head2 = merge(head2, head);
        display(head2);
    }

}