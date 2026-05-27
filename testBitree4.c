#include <stdio.h>
#include <stdlib.h>


//二叉树的储存结构
typedef char TreeType;
typedef struct TreeNode{
    TreeType data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
}TreeNode;
typedef TreeNode* BiTree;
//栈的储存结构(链式)
typedef struct stack{
    BiTree bitree;
    struct stack* next;
}Stack;
Stack* initStack(){
    Stack* s=(Stack*)malloc(sizeof(Stack));
    s->bitree=NULL;
    s->next=NULL;
    return s;
}
int push(Stack* s,BiTree T){
    Stack* p=(Stack*)malloc(sizeof(Stack));
    p->bitree=T;
    p->next=s->next;
    s->next=p;
    return 1;
}
int pop(Stack* s,BiTree *T){
    if(s->next==NULL){
        return 0;
    }
    Stack* q=s->next;
    *T=q->bitree;
    s->next=q->next;
    free(q);
    return 1;
}
int isEmpty(Stack* s){
    if(s->next==NULL){
        return 1;
    }
    return 0;
}
//创造树
char str[]="ABDH#K###E##CFI###G#J##";
int idx=0;
void creatTree(BiTree *T){
    char ch=str[idx++];
    if(ch=='#'){
        *T=NULL;
    }else{
        *T=(BiTree)malloc(sizeof(TreeNode));
        (*T)->data=ch;
        creatTree(&(*T)->lchild);
        creatTree(&(*T)->rchild);
    }
}
//后序遍历（非递归）
void iterpostOrder(Stack* s,BiTree T){
    BiTree lastVisit = NULL;
    while(T!=NULL || !isEmpty(s)){
        while(T!=NULL){
            push(s,T);
            T=T->lchild;
        }
        pop(s,&T);
        if (T->rchild == NULL || T->rchild == lastVisit) {
            printf("%c ", T->data);
            lastVisit = T;
            T = NULL;
        } else {
            push(s, T);
            T = T->rchild;
        }
    }
}
int main(){
    BiTree T;
    Stack *s=initStack();
    idx=0;
    creatTree(&T);
    iterpostOrder(s,T);
    return 0;
}