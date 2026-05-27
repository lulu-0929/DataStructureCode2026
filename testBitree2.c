#include <stdio.h>
#include <stdlib.h>


//储存结构
typedef char TreeType;
typedef struct TreeNode{
    TreeType data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
}TreeNode;

typedef TreeNode* BiTree;

//创造树
char str[]="ABDH#K###E##CFI###G#J##";
int idx=0;

void creatTree(BiTree *T){
    TreeType ch;
    ch=str[idx++];
    if(ch=='#'){
        *T=NULL;
    }else{
        *T=(BiTree)malloc(sizeof(TreeNode));
        (*T)->data=ch;
        (*T)->lchild=NULL;
        (*T)->rchild=NULL;
        creatTree(&(*T)->lchild);
        creatTree(&(*T)->rchild);
    }
}
//链式结构栈
typedef struct stack{
    BiTree bitree;
    struct stack * next;
}Stack;
//栈初始化
Stack * initStack(){
    Stack *s=(Stack*)malloc(sizeof(Stack));
    s->bitree=NULL;
    s->next=NULL;
    return s;
}
//判断栈是否为空
int isEmpty(Stack *s){
    if(s->next==NULL){
        return 1;
    }
    return 0;
}
//进栈
int push(Stack *s,BiTree T){
    Stack *p=(Stack*)malloc(sizeof(Stack));
    p->bitree=T;
    p->next=s->next;
    s->next=p;
    return 1;
}
//出栈
int pop(Stack *s,BiTree *T){
    if(s->next==NULL){
        return 0;
    }
    Stack *q=s->next;
    *T=q->bitree;
    s->next=q->next;
    free(q);
    return 1;
}

//前序遍历（非递归）
void iterPreOrder(Stack *s,BiTree T){
    while(T!=NULL || !isEmpty(s)){
        while(T!=NULL)  
        {
            printf("%c ",T->data);
            push(s,T);
            T=T->lchild;
        }
        pop(s,&T);
        T=T->rchild;
    }
}

int main(){
    idx=0;
    BiTree T;
    creatTree(&T);
    Stack *s=initStack();
    iterPreOrder(s,T);
    return 0;
}


