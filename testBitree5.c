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
//队列的储存结构(循环队列且为顺序结构)
#define MAXSIZE 100
typedef struct queue{
    BiTree data[MAXSIZE];
    int front;
    int rear;
}Queue;
Queue* initQueue(){
    Queue*q=(Queue*)malloc(sizeof(Queue));
    q->front=0;
    q->rear=0;
    return q;
}
int enQueue(Queue* q,BiTree T){
    if((q->rear+1)%MAXSIZE==q->front){
        return 0;
    }
    q->data[q->rear]=T;
    q->rear=(q->rear+1)%MAXSIZE;
    return 1;
}
int deQueue(Queue* q,BiTree *T){
    if(q->front==q->rear){
        return 0;
    }
    *T=q->data[q->front];
    q->front=(q->front+1)%MAXSIZE;
    return 1;
}
int isEmpty(Queue*q){
    if(q->front==q->rear){
        return 1;
    }
    return 0;
}
int queueSize(Queue* q){
    if(q->front==q->rear){
        return 0;
    }else{
        return (q->rear - q->front+MAXSIZE)%MAXSIZE;
    }
}
//层序遍历
int maxDepth(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int depth=0;
    Queue* q=initQueue();
    enQueue(q,root);
    while(!isEmpty(q)){
        int count=queueSize(q);
        while(count>0){
            TreeNode* curr;
            deQueue(q,&curr);
            if(curr->lchild!=NULL){
                enQueue(q,curr->lchild);
            }
            if(curr->rchild!=NULL){
                enQueue(q,curr->rchild);
            }
            count--;
        }
        depth++;
    }
    return depth;
}
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
int main(){
    Queue *q;
    idx=0;
    BiTree T;
    creatTree(&T);
    printf("%d\n",maxDepth(T));
    return 0;
}