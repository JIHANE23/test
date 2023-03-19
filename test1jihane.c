

/*this is the dynamic array */

#include <stdio.h>
#include <stdlib.h>
struct dynamic{
    int *arr;
    int n;
};
int count=0;
void append(struct dynamic *A,int data){
    A->n++;
    A->arr=realloc(A->arr,A->n*sizeof(int));
    A->arr[A->n-1]=data;
    count++;
    if(data>A->n){
        A->arr=realloc(A->arr, 2*A->n*sizeof(int));
        A->arr[A->n]=data;
        count+=1;
    }
 }
int main() {
    struct dynamic A;
    int n;
    A.arr=NULL;
    A.n=0;
    append(&A,1);
    append(&A,2);
    append(&A,3);
    append(&A,4);
    append(&A,5);
    append(&A,6);
    append(&A,7);
    append(&A,8);
    for(int i=0;i<A.n;i++){
        printf("%d",A.arr[i]);
    }
    free(A.arr);
 
    return 0;
}

/*this is the stack */

#include <stdio.h>
#include <stdlib.h>
struct stack{
    int *arr;
    int n;
};
void push(struct stack *A,int data){
    A->n++;
    A->arr=realloc(A->arr,A->n*sizeof(int));
    A->arr[A->n-1]=data;
    count++;
    if(data > A->n){
        A->arr=realloc(A->arr, 2*A->n*sizeof(int));
        A->arr[A->n]=data;
    int i, j;
    for (i = 0, j = 0; j < A->n; j++) {
        if (A->arr[j] != 0) {
            A->arr[i++] = A->arr[j];
        };
    };
    A->n = i;
    A->arr = realloc(A->arr, A->n * sizeof(int));
};

    }
void pop(struct stack *A){
    if(A->arr==NULL){
        return;
    }else{
        if (A->n <= 0) {
            A->n = 0;
            A->arr = NULL;
        }else{
            A->n--;
            A->arr=(int*)realloc(A->arr,A->n * sizeof(int));
        }
    }
}

int main() {
    struct stack A;
    int n;
    A.arr=NULL;
    A.n=0;
    push(&A,1);
    push(&A,2);
    push(&A,3);
    push(&A,4);
    push(&A,5);
    push(&A,6);
    push(&A,7);
    push(&A,8);
    pop(&A);
    for(int i=0;i<A.n;i++){
        printf("%d",A.arr[i]);
    }
    free(A.arr);
 
    return 0;
}
*/this is the queue*/

#include <stdio.h>
#include <stdlib.h>
struct queue{
    int n;
    int front;
    int rear;
    int *arr;
};
void enqueue(struct queue *B,int s){
    if(B->arr==NULL){
        B->front=-1;
        B->rear=-1;
    }
    B->n++;
    B->arr=realloc(B->arr,B->n*sizeof(int));
    if (B->arr == NULL) {
        printf("Error: out of memory\n");
        exit(1);
    };
    B->arr[B->n-1]=s;
    B->rear++;
    if (B->front == -1) {
        B->front = 0;
    };

}
void dequeue(struct queue *B){
    if(B->arr!=NULL){
        for(int i=0;i<B->n-1;i++){
            B->arr[i]=B->arr[i+1];
        }
        B->front++;
        B->n--;
        B->arr=realloc(B->arr,B->n*sizeof(int));
        if(B->front==B->rear){
            B->front=-1;
            B->rear=-1;
        }
    }
}

int main() {
    struct queue B;
    int n;
    B.arr=NULL;
    B.n=0;
    enqueue(&B,1);
    enqueue(&B,2);
    enqueue(&B,3);
    enqueue(&B,4);
    enqueue(&B,5);
    dequeue(&B);
    for(int i=0;i<B.n;i++){
        printf("%d\n",B.arr[i]);
    }
    free(B.arr);
    return 0;
}





 
