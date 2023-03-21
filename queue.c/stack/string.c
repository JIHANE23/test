 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack{
    char **str;
    int n;
};
void push(struct stack *A,char *data){
    A->n++;
    A->str=realloc(A->str,A->n*sizeof(char*));
    A->str[A->n-1]=malloc(strlen(data)+1);
    strcpy(A->str[A->n-1], data);

    }
void pop(struct stack *A){
    if(A->str==NULL){
        return;
    }else{
        if (A->n <= 0) {
            A->n = 0;
            A->str = NULL;
        }else{
            free(A->str[A->n-1]);
            A->n--;
            A->str=realloc(A->str,A->n * sizeof(char*));
        }
    }
}

int main() {
    struct stack A;
    int n;
    A.str=NULL;
    A.n=0;
    push(&A, "Hello");
    push(&A, "world");
    push(&A, "!");
    pop(&A);
    for (int i = 0; i < A.n; i++) {
        printf("%s ", A.str[i]);
    }
    printf("\n");
    for (int i = 0; i < A.n; i++) {
        free(A.str[i]);
    }
    free(A.str);
    return 0;

}