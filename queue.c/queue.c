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
