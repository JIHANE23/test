#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node{
    struct node *left;
    struct node *right;
    int value;
    int height;
    struct node *parent;
};
int max(int a ,int b){
    return a > b ? a : b;
}
int min(int a,int b){
    return a < b ? a : b;

}
int height(struct node* A){
    if(A==NULL){
        return -1;
    }else{
        int left=height(A->left);
        int right=height(A->right);
        return max(left,right)+1;
    }
}
int balanced_factor[3]={-1,0,1};
void leftright_rotation(struct node**root){
    struct node* left_root=(*root)->left;
    struct node* left_right=(*root)->left->right;
    left_root->right = left_right->left;
    left_right->left = left_root;
    (*root)->left = left_right;
    struct node* right_child = left_right->right;
    left_right->right = (*root);
    (*root)->left = right_child;
    (*root) = left_right;
}
void rightleft_rotation(struct node**root){
    struct node* right_root=(*root)->right;
    struct node* right_left=(*root)->right->left;
    right_root->left = right_left->right;
    right_left->right = right_root;
    (*root)->right = right_left;
    struct node* left_child = right_left->left;
    right_left->left = (*root);
    (*root)->right = left_child;
    (*root) = right_left;
}


void insertion(struct node** root,int data){
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->value=data;
    new_node->right=NULL;
    new_node->left=NULL;
    new_node->parent=NULL;
    if(*root==NULL){
        *root=new_node;
    }
    if(data > (*root)->value){
        if((*root)->right==NULL){
            (*root)->right=new_node;
            new_node->value=data;
        }else{
            insertion(&(*root)->right,data);
        }
    }
    if(data < (*root)->value){
        if((*root)->left==NULL){
            (*root)->left=new_node;
            new_node->value=data;
        }else{
            insertion(&(*root)->left,data);
        }
    }
    new_node->height=height(new_node);
    struct node* current=new_node;
    int balance_factor=height(current->left)-height(current->right);
    if(balance_factor < -1){
        int balance_right_left=height(current->right->left)-height(current->right->right);
        if(balance_right_left>1){
            rightleft_rotation(&(*root));
        }else{
            leftright_rotation(&(*root));
        }
    }else if(balance_factor>1){
        int balance_left_right=height(current->left->left)-height(current->left->right);
        if(balance_left_right < -1){
            rightleft_rotation(&(*root));;
        }else if(balance_left_right > 1){
            leftright_rotation(&(*root));
        }
        while(current!=NULL){
            if(current== *root){
            break;
        }
        current=current->parent;
        }
         
    }
   
void free_tree(struct node* A ){
    if(A!=NULL){
        free_tree(A->right);
        free_tree(A->left);
        free(A);
    }
}
