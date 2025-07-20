#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * next;
    struct node * prev;
};
void display(struct node * ptr){
    while(ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr -> next;
    }
}
int count(struct node * ptr ){
    int node = 0;
    while(ptr != NULL){
        ptr = ptr -> next;
        node = node + 1;
    }
    return node;
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
struct node * ins_n(struct node * head, int data , int n){
    struct node * p;
    p =(struct node *)malloc(sizeof(struct node));
    p -> data = data;
    struct node * t = head;
    struct node * s = head;
    int i;
    int m = count(head) - 1;
    if(n == 0){
        head = ins_beg(head, data);
    }
    else if(n == m){
        head = ins_end(head, data);
    }
    else if(n < m){
        n = n-1;
        for(i = 0; i < n; i++){
            t = t -> next;
        }
        for(i = 0; i <= n; i++){
            s = s -> next;
        }
        p -> next = s;
        p -> prev = t;
        t -> next = p;
        s -> prev = p;
    }
    else{
        printf("ERROR");
    }
    return head;
}
struct node * del_beg(struct node * head){
    struct node * t = head;
    head = head -> next;
    head-> prev = NULL;
    free(t);
    return head;
}
struct node * del_end(struct node * head){
    struct node * t = head;
    struct node * s = head;
    while(t -> next != NULL){
        t = t -> next;
    }
    while(s -> next -> next != NULL){
        s = s -> next;
    }
    s -> next = NULL;
    free(t);
    return head;
}
struct node * del_n(struct node * head, int n){
    struct node * t = head;
    struct node * s;
    int i = 0;
    int m = count(head) - 1;
    if(n == 0){
        head = del_beg(head);
    }
    else if(n < m){
        for(i=0; i<n; i++){
            t = t -> next;
        }
        s = t -> prev;
        s -> next = t -> next;
        t -> next -> prev = s;
        free(t); 
    }
    else if(n == m){
        head = del_end(head);
    }
    else{
        printf("ERROR");
    }
    return head;
}
void reverse(struct node * head){
    struct node * t = head;
    while(t -> next != NULL){
        t = t -> next;
    }
    while(t != NULL){
        printf("%d\n",t -> data);
        t = t -> prev;
    }
}
void third_last(struct node * head){
    struct node * t = head;
    int m = count(head) - 3;
    int i = 0;
    if(m < 0){
        printf("NULL\n");
    }
    else{
        while(i != m){
            t = t -> next;
            i++;
        }
        printf("third last node is %d\n",t -> data);
    }
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
    int option;
    int data;
    int node;
    struct node * head = NULL;
    /*struct node * first;
    struct node * second;
    head =(struct node *)malloc(sizeof(struct node));
    first =(struct node *)malloc(sizeof(struct node));
    second =(struct node *)malloc(sizeof(struct node));

    head -> prev = NULL;
    head -> data = 5;
    head -> next = first;

    first -> prev = head;
    first -> data = 7;
    first -> next = second;

    second -> prev = first;
    second -> data = 6;
    second -> next = NULL;*/
    while(1){
        printf("Enter number for what you want\n");
        printf("1) Insertion at beginning\n");
        printf("2) Insertion at ending\n");
        printf("3) Insert at nth node\n");
        printf("4) traverse and display all nodes\n");
        printf("5) delete first node\n");
        printf("6) delete last node\n");
        printf("7) delete nth node\n");
        printf("8) count number of nodes\n");
        printf("9) reverse list\n");
        printf("10) third last\n");
        printf("11) merge two linked lists\n");
        printf("12) exit\n");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            printf("Enter data you want to insert: ");
            scanf("%d",&data);
            head = ins_beg(head, data);
            break;
        case 2:
            printf("Enter data you want to insert: ");
            scanf("%d",&data);
            head = ins_end(head, data);
            break;
        case 3:
            printf("Enter node at which you want to insert: ");
            scanf("%d",&node);
            printf("Enter data you want to insert: ");
            scanf("%d",&data);
            head = ins_n(head, data, node);
            break;
        case 4:
            display(head);
            break;
        case 5:
            head = del_beg(head);
            break;
        case 6:
            head = del_end(head);
            break;
        case 7:
            printf("Enter node at which you want to delete: ");
            scanf("%d",&node);
            head = del_n(head, node);
            break;
        case 8:
            printf("Number of nodes are: %d\n",count(head));
            break;
        case 9:
            reverse(head);
            break;
        case 10:
            third_last(head);
            break;
        case 11:
            int i = 0;
            int data;
            int node1;
            int p;
            struct node * head1 = NULL;
            struct node * head2 = NULL;
            printf("select linked list\n1) first\n2)second\n3)both different");
            scanf("%d",&p);
            if(p == 1){
                head1 = head;
                printf("Enter number of nodes in other list: ");
                scanf("%d",&node1);
                printf("Enter data for other linked list:\n ");
                while(i != node1){
                    scanf("%d",&data);
                    head2 = ins_beg(head2, data);
                    i = i + 1;
                }
            }
            else if(p == 2){
                head2 = head;
                printf("Enter number of nodes in other list: ");
                scanf("%d",&node1);
                printf("Enter data for other linked list:\n ");
                while(i != node1){
                    scanf("%d",&data);
                    head1 = ins_beg(head1, data);
                    i = i + 1;
                }
            }
            else{
                printf("Enter number of nodes in first list: ");
                scanf("%d",&node1);
                printf("Enter data for first linked list:\n ");
                while(i != node1){
                    scanf("%d",&data);
                    head1 = ins_beg(head1, data);
                    i = i + 1;
                }
                printf("Enter number of nodes in other list: ");
                scanf("%d",&node1);
                printf("Enter data for other linked list:\n ");
                while(i != node1){
                    scanf("%d",&data);
                    head2 = ins_beg(head2, data);
                    i = i + 1;
                }
            }
            head1 = merge(head1, head2);
            display(head1);
            break;
        case 12:
            return 0;
        default:
            break;
        }
    }
}