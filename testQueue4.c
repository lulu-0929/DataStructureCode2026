#include <stdio.h>
#include <stdlib.h>

//队列的链式结构
typedef int ElemType;
//储存结构
typedef struct node{
    ElemType data;
    struct node *next; 
}Queuenode;
typedef struct{
    Queuenode *front;
    Queuenode *rear;
}Queue;
//初始化
Queue* initQueue(){
    Queuenode* node=(Queuenode*)malloc(sizeof(Queuenode));
    node->data=0;
    node->next=NULL;
    Queue* q=(Queue*)malloc(sizeof(Queue));
    q->front=node;
    q->rear=node;
    return q;
}
//判断是否为空
int isEmpty(Queue* q){
    if(q->front==q->rear){
        return 1;
    }
    return 0;
}
//入队(尾插法)
void enQueue(Queue* q,ElemType e){
    Queuenode* node=(Queuenode*)malloc(sizeof(Queuenode));
    node->data=e;
    node->next=NULL;
    q->rear->next=node;
    q->rear=node;
}
//出队
int deQueue(Queue* q,ElemType *e){
    Queuenode* node=q->front->next;
    *e=node->data;
    q->front->next=node->next;
    if(node==q->rear){
        q->front=q->rear;
    }
    free(node);
    return 1;
}
//获取队头元素
int getHead(Queue* q,ElemType* e){
    if(q->front==q->rear){
        printf("空的\n");
        return 0;
    }
    *e=q->front->next->data;
    return 1;
}
//遍历
void elemQueue(Queue* q){
    if(q->front==q->rear){
        printf("空的\n");
        return ;
    }
    Queuenode *p=q->front;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}


int main(){
    Queue *q;
    //初始化
    q=initQueue();
    //入队
    enQueue(q,1);
    enQueue(q,2);
    enQueue(q,3);
    enQueue(q,4);
    enQueue(q,5);
    enQueue(q,6);
    enQueue(q,7);
    enQueue(q,8);
    enQueue(q,9);
    enQueue(q,10);
    elemQueue(q);
    //出队
    ElemType deledata1;
    deQueue(q,&deledata1);
    printf("出队的元素：%d\n",deledata1);
    elemQueue(q);
    ElemType deledata2;
    deQueue(q,&deledata2);
    printf("出队的元素：%d\n",deledata2);
    elemQueue(q);


    //获取队头元素
    ElemType topdata;
    getHead(q,&topdata);
    printf("队头元素：%d",topdata);






    return 0;
}