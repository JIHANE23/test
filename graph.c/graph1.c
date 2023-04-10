 #include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
clion
typedef struct s_node{
    int data;
    struct s_node *next;
}node;
int main(){
    FILE *fp;
    char str[100];
    int nb_nodes,edges;
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    if (fgets(str, 100, fp) != NULL) {
        sscanf(str, "%d %d", &nb_nodes, &edges);
    }
    printf("Number of nodes: %d\n", nb_nodes);
    printf("Number of edges: %d\n", edges);
    node *array[nb_nodes];
    node *nodes_exists[nb_nodes];
    for(int i=0;i<nb_nodes;i++){
        array[i]=NULL;
        nodes_exists[i]=NULL;
    }
    for (int j = 0; j < nb_nodes; j++) {
    int data;
    if (fgets(str, 100, fp) != NULL) {
        sscanf(str, "%d", &data);
    }
    node *current = array[j];
    while (current != NULL) {
        if (current->data == data) {
            printf("the node %d already exists in the array %d", data, j);
            break;
        }
        current = current->next;
        if (current == NULL) {
            node *ptr = (node*)malloc(sizeof(node));
            ptr->next = NULL;
            ptr->data = data;
            if (nodes_exists[data] != NULL) {
                printf("the node is already exists");
            } else {
                array[j] = ptr;
                nodes_exists[data] = array[j];
            }
        }
    }

    node *heads[nb_nodes];
    for (int i = 0; i < nb_nodes; i++) {
        heads[i] = NULL;
    }

    current = array[j];
    data = current->data;

    for (int k = 0; k < edges; k++) {
        int node1, node2;
        if (fgets(str, 100, fp) != NULL) {
            if(k==0) continue;
            sscanf(str, "%d %d", &node1, &node2);
        }
        node *new_node=NULL;
        if (node1 == data) {
            node *new_node = (node*)malloc(sizeof(node));
            new_node->next = NULL;
            new_node->data = node2;
        }
        node *head = heads[node1];
        if (head == NULL) {
            head = (node*)malloc(sizeof(node));
            head->next = NULL;
            head->data = node1;
            heads[node1] = head;
        }
        node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    return 0;
}
}


/*traverse the graph by dfs:*/
typedef struct node{
    int value;
    struct node* next;
}node;
void DFS(node *current,int *visited,struct node* head){
    visited[current->value]=1;
    printf("%d ", current->value);
    while(current->next!=NULL){
        if(!visited[current->next->value]){
            DFS(current->next,visited,head);
        }
        current=current->next;
    }
}
/*traverse the graph by BFS:*/

void BFS(node *current, int visited[], struct node *head) {
    struct queue Q;
    Q.n = 0;
    Q.front = -1;
    Q.rear = -1;
    Q.arr = NULL;
    enqueue(&Q, current);
    while (Q.n > 0) {

        current = &(Q.arr[Q.front]);
        dequeue(&Q);
        
        if (visited[current->value] == 0) {
            visited[current->value] = 1;
            printf("%d ", current->value);
            
            node *neighbor = current->next;
            while (neighbor != NULL) {
                if (visited[neighbor->value] == 0) {
                    enqueue(&Q, neighbor);
                }
                neighbor = neighbor->next;
            }
        }
    }
    
    
    free(Q.arr);
}


/*check if the graph is a tree*/


void check_tree(node *head,int nb_nodes){
    DFS(head,nb_nodes);
    bool nodes_visited=true;
    for(int j=0;j<nb_nodes;j++){
        if(!visited[j]){
            nodes_visited=false;
            break;
        }
    }
    if(nodes_visited){
        printf("the graph is connected");
    }else{
        printf("the graph is not connected");
    }
    int nb_edges=0;
    node *current=head;
    while(current!=NULL){
        nb_edges+=1;
        current=current->next;
    }
    if(nb_edges!=nb_nodes-1){
        printf("the graph is not a tree");
    }

    
}
