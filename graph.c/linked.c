#include <stdlib.h>
#include <stdio.h>
typedef struct s_node{
    int data;
    struct s_node *next;
}node;
void append(node *head,int val){
    if(head==NULL){
        return;
    }
    node *p=(node*)malloc(sizeof(node));
    p->data=val;
    p->next=NULL;
    node *current=head;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=p;
}
void del(node *head, int val) {
    node* A = head;
    node* B = NULL;
    while (A != NULL) {
        if (A->data == val) {
            if (B == NULL) {
                head = A->next;
            } else {
                B->next = A->next;
            }
            free(A);
            return;
        }
        B = A;
        A = A->next;
    }
}




int main() {
    node *head = (node*) malloc(sizeof(node));
    head->data = 1;
    head->next = NULL;
    append(head, 2);
    append(head, 3);
    node *current = head;
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
    }

    int value = 2;
    del(head, value);
    current = head;
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
}
 
 
    return 0;
}
