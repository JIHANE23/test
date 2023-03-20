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
