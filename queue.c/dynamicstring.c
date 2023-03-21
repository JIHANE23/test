#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct dynamic{
    char *str;
    int n;
};
int count=0;
void append(struct dynamic *A,char *data){
    int data_len=strlen(data);
    A->n=+data_len;
    A->str=realloc(A->str,(A->n+1)*sizeof(char));
    strcat(A->str,data);
    count+=data_len;
    if(data_len>A->n){
        A->str=realloc(A->str, 2*(A->n +1)*sizeof(char));
        strcat(A->str,data);
        count+=data_len;
    }
 }
int main() {
    struct dynamic A;
    int n;
    A.str=NULL;
    A.n=0;
    append(&A,"hello ");
    append(&A,"i'm ");
    append(&A,"a ");
    append(&A,"c programmer ");
    append(&A,"!");
    printf("%s\n",A.str);
    free(A.str);
 
    return 0;
}