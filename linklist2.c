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
    return ptr;
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
struct node * insert_after(struct node * head ,int data,int n){
    int i = 0;
    struct node* ptr = (struct node *) malloc(sizeof(struct node));
    ptr -> data = data;
    struct node * p = head;
    while(n != i){
        p = p -> next;
        i++;
    }
    ptr -> next = p -> next;
    p -> next = ptr;
}
struct node * insert_before(struct node * head ,int data,int n){
    int i = 0;
    int j = 1;
    struct node* ptr = (struct node *) malloc(sizeof(struct node));
    ptr -> data = data;
    struct node * p = head;
    struct node * q = head;
    if(n==0){
        ptr = insert_beg(head,data);
    }
    else{
        while(n != i){
            p = p -> next;
            i++;
        }
        while(n != j){
            q = q -> next;
            j++;
        }
        q -> next = ptr;
        ptr -> next = p;
    }
    return ptr;
}
void display(struct node * ptr){
    while(ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr -> next;
    }
}
void count(struct node * ptr ){
    int node = 0;
    while(ptr != NULL){
        ptr = ptr -> next;
        node = node + 1;
    }
    printf("number of nodes are %d\n",node);
}
void update(struct node * ptr , int data , int n){
    int i = 0;
    while(i != n){
        ptr = ptr -> next;
        i++;
    }
    ptr -> data = data;
}
struct node * del_beg(struct node * head){
    struct node * t = head;
    head = head -> next;
    free(t);
    return head;
}
struct node * del_end(struct node * head){
    struct node * t = head;
    while(t -> next -> next != NULL){
        t = t-> next;
    }
    free(t-> next );
    t -> next = NULL;
    return head;
}
struct node * del_n(struct node * head, int n){
    struct node * t = head;
    struct node * p;
    int i = 1;
    if(n == 0 ){
        head = del_beg(head);
    }
    while(i != n){
        t = t -> next;
        i++;
    }
    p = t -> next;
    t -> next = p -> next;
    free(p);
    return head;
}
struct node * del_data(struct node * head, int d){
    struct node * t = head;
    struct node * p;
    while(t -> next -> data != d){
        t = t -> next;
    }
    p = t -> next;
    t -> next = p-> next;
    free(p);
    return head;
}
struct node * odd(struct node * head){
    struct node * ptr = head;
    struct node * head2;
    while(ptr != NULL)
    {
        if((ptr -> data)%2 != 0){
            insert_end(head2,ptr -> data);
        }
        ptr = ptr -> next;
    }
    display(head2);
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
    second -> data = 4;
    second -> next = third;
    third -> data = 7;
    third -> next = NULL;
    while(1){
        printf("Enter number for what you want\n");
        printf("1) Insertion at beginning\n");
        printf("2) Insertion at ending\n");
        printf("3) Insretion of new node after nth node\n");
        printf("4) Insretion of new node before nth node\n");
        printf("5) traverse and display all nodes\n");
        printf("6) count the number of nodes in linked list\n");
        printf("7) update data of nth node\n");
        printf("8) delete first node\n");
        printf("9) delete last node\n");
        printf("10) delete nth node\n");
        printf("11) delete node with entered data\n");
        printf("12) exit\n");
        printf("13) odd numbers ditribution\n");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            int value;
            printf("Enter value you want to add in beginning: ");
            scanf("%d",&value);
            head = insert_beg(head , value);
            break;
        case 2:
            printf("Enter value you want to add in ending: ");
            scanf("%d",&value);
            head = insert_end(head , value);
            break;
        case 3:
            int node;
            printf("Enter node index after which you want to add: ");
            scanf("%d",&node);
            printf("Enter value you want to add: ");
            scanf("%d",&value);
            insert_after(head,value,node);
            break;
        case 4:
            printf("Enter node index before which you want to add: ");
            scanf("%d",&node);
            printf("Enter value you want to add: ");
            scanf("%d",&value);
            insert_before(head,value,node);
            break;
        case 5:
            display(head);
            break;
        case 6:
            count(head);
            break;
        case 7:
            printf("Enter the node for which you want to update the value: ");
            scanf("%d",&node);
            printf("Enter value you want to update: ");
            scanf("%d",&value);
            update(head,value,node);
            break;
        case 8:
            head = del_beg(head);
            break;
        case 9:
            head = del_end(head);
            break;
        case 10:
            printf("Enter the node you want to delete: ");
            scanf("%d",&node);
            head = del_n(head,node);
            break;
        case 11:
            printf("Enter the data of node you want to delete: ");
            scanf("%d",&value);
            head = del_data(head,value);
            break;
        case 12:
            return 0;
        case 13:
            odd(head);
            break;
        default:
            break;
        }
    }
}