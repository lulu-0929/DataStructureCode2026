#include <stdio.h>
#include <stdlib.h>

//二叉树储存结构
typedef char ElemType;
typedef struct TreeNode{
    ElemType data;
    struct TreeNode * lchild;
    struct TreeNode * rchild;
}TreeNode;

typedef TreeNode* BiTree;

//前序遍历（递归方式）
void preOrder(BiTree T){
    if(T==NULL){
        return; 
    }
    printf("%c ",T->data);
    preOrder(T->lchild);
    preOrder(T->rchild);
}

//中序遍历（递归方式）
void inOrder(BiTree T){
    if(T==NULL){
        return;
    }
    inOrder(T->lchild);
    printf("%c ",T->data);
    inOrder(T->rchild);
}

//后序遍历（递归方式）
void postOrder(BiTree T){
    if(T==NULL){
        return;
    }
    postOrder(T->lchild);
    postOrder(T->rchild);
    printf("%c ",T->data);
}

//创造树
char str[]="ABDH#K###E##CFI###G#J##";
int idx=0;
void creatTree(BiTree *T){
    ElemType ch;
    ch=str[idx++];
    if(ch=='#'){
        *T=NULL;
    }else{
        *T=(BiTree)malloc(sizeof(TreeNode));
        (*T)->data=ch;
        creatTree(&(*T)->lchild);
        creatTree(&(*T)->rchild);
    }
}

int main(){
    BiTree T;
    creatTree(&T);
    //前序遍历
    preOrder(T);
    printf("\n");
    //中序遍历
    inOrder(T);
    printf("\n");
    //后序遍历
    postOrder(T);
    printf("\n");
    return 0;
}
