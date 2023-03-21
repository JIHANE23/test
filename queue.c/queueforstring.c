#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct queue{
    int n;
    int front;
    int rear;
    char **arr;
};
void enqueue(struct queue *B,char *s){
    if(B->arr==NULL){
        B->front=-1;
        B->rear=-1;
    }
    B->n++;
    B->arr=realloc(B->arr,B->n*sizeof(char *));
    if (B->arr == NULL) {
        printf("Error: out of memory\n");
        exit(1);
    };
    B->arr[B->n-1]= malloc((strlen(s)+1) * sizeof(char));
    if (B->arr[B->n-1] == NULL) {
        printf("Error: out of memory\n");
        exit(1);
    }
    strcpy(B->arr[B->n-1], s);
    B->rear++;
    if (B->front == -1) {
        B->front = 0;
    };

}
void dequeue(struct queue *B){
    if(B->arr!=NULL){
        free(B->arr[B->front]);
        for(int i=1;i<B->n;i++){
            B->arr[i-1]=B->arr[i];
        }
        B->front++;
        B->n--;
        B->arr=realloc(B->arr,B->n*sizeof(char *));
        if(B->front==B->rear){
            B->front=-1;
            B->rear=-1;
        }
    }
}

int main() {
    struct queue B;
    char *s1 = "Hello ";
    char *s2 = "World ";
    char *s3 = "How ";
    char *s4 = "Are ";
    char *s5 = "You ";
    B.arr=NULL;
    B.n=0;
    enqueue(&B, s1);
    enqueue(&B, s2);
    enqueue(&B, s3);
    enqueue(&B, s4);
    enqueue(&B, s5);
    dequeue(&B);

    for(int i=0;i<B.n;i++){
        printf("%s",B.arr[i]);
    }
    for(int i=0;i<B.n;i++){
        free(B.arr[i]);
    }
    free(B.arr);

    return 0;
}