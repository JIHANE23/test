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
