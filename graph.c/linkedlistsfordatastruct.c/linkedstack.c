#include <stdio.h>
#include <stdlib.h>

struct cell {
    int element;
    struct cell* following;
};

typedef struct cell cell;
typedef struct cell* stack;

void show(stack L){
    while (L != NULL) {
        printf("%d ", L->element);
        L = L->following;
    }
    printf("\n");
}

void put_on_stack(stack* L, int X){
    stack C = malloc(sizeof(cell));
    C->element = X;
    C->following = *L;
    (*L) = C;
}

void pop_from_stack(stack* L){
    stack C = *L;
    (*L) = (*L)->following;
    free(C);
}

int main(int argc, char const *argv[])
{
    stack L = NULL;
    put_on_stack(&L, 1);
    put_on_stack(&L, 2);
    put_on_stack(&L, 3);
    put_on_stack(&L, 4);
    put_on_stack(&L, 5);
    show(L);
    pop_from_stack(&L);
    show(L);
    return 0;
}
