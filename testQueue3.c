#include <stdio.h>
#include <stdlib.h>

//队列顺序结构（循环队列）
#define MAXSIZE 100
typedef int ElemType;
typedef struct {
    ElemType *data;
    int front;
    int rear;
}Queue;
//初始化
Queue * initQueue(){
    Queue *q=(Queue*)malloc(sizeof(Queue));
    q->data=(ElemType *)malloc(sizeof(ElemType)*MAXSIZE);
    q->front=0;
    q->rear=0;
    return q;
}
//入队
int enQueue(Queue *q,ElemType e){
    if((q->rear+1)%MAXSIZE==q->front){
        printf("队列已满\n");
        return 0;
    }
    q->data[q->rear]=e;
    q->rear=(q->rear+1)%MAXSIZE;
    return 1;
}
//出队
int deQueue(Queue *q,ElemType *e){
    if(q->rear==q->front){
        printf("空的\n");
        return 0;
    }
    *e=q->data[q->front];
    q->front=(q->front+1)%MAXSIZE;
    return 1;
}
//遍历
void elemQueue(Queue *q){
    if(q->front==q->rear){
        printf("空的\n");
        return ;
    }
    for(int i=q->front;i!=q->rear;i=(i+1)%MAXSIZE){
        printf("%d ",q->data[i]);
    }
    printf("\n");
}
int main(){
    Queue *Q;
    Q=initQueue();
    //入队
    enQueue(Q,0);
    enQueue(Q,1);
    enQueue(Q,2);
    enQueue(Q,3);
    enQueue(Q,4);
    enQueue(Q,5);
    enQueue(Q,6);
    enQueue(Q,7);
    enQueue(Q,8);
    elemQueue(Q);
    //出队
    ElemType deledata1;
    deQueue(Q,&deledata1);
    printf("出队的元素：%d\n",deledata1);
    elemQueue(Q);
    ElemType deledata2;
    deQueue(Q,&deledata2);
    printf("出队的元素：%d\n",deledata2);
    elemQueue(Q);
    return 0;
}