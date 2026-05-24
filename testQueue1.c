#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElemType;
//储存结构(顺序结构实现)
typedef struct {
    ElemType data[MAXSIZE];
    int front;
    int rear;
}Queue;
//初始化
void initQueue(Queue *Q){
    Q->front=0;
    Q->rear=0;
}
//判断队列是否为空
int isEmptyQueue(Queue *Q){
    if(Q->front==Q->rear){
        printf("空的\n");
        return 1;
    }
    return 0;
}
//出队
int deQueue(Queue *Q,ElemType *e){
    if(Q->front==Q->rear){
        printf("空的\n");
        return 0;
    }
    *e=Q->data[Q->front];
    Q->front++;
    return 1;
}
//判断队列是否满了(能否入队)
int queueFull(Queue *Q){
    if(Q->front>0){
        int step=Q->front;
        for(int i=Q->front;i<=Q->rear;i++){
            Q->data[i-step]=Q->data[i];
        }
        Q->front=0;
        Q->rear=Q->rear -step;
        return 1;
    }else{
        printf("真的满了\n");
        return 0;
    }

}
//入队
int enQueue(Queue *Q,ElemType e){
    if(Q->rear>=MAXSIZE){
        if(!queueFull(Q)){
            return 0;
        }
    }
    Q->data[Q->rear]=e;
    Q->rear++;
    return 1;
}
//获取队头元素
int getHead(Queue *Q,ElemType *e){
    if(Q->front==Q->rear){
        printf("空的\n");
        return 0;
    }
    *e=Q->data[Q->front];
    return 1;
}
//遍历
void elemQueue(Queue *Q){
    if(Q->front==Q->rear){
        printf("空的\n");
        return ;
    }
    for(int i=Q->front;i<Q->rear;i++){
        printf("%d ",Q->data[i]);
    }
    printf("\n");
}


int main(){
    Queue Q;
    //初始化
    initQueue(&Q);
    //判断是否为空
    isEmptyQueue(&Q);
    //入队
    enQueue(&Q,15);
    enQueue(&Q,20);
    enQueue(&Q,25);
    enQueue(&Q,30);
    enQueue(&Q,35);
    enQueue(&Q,40);
    enQueue(&Q,45);
    enQueue(&Q,50);
    enQueue(&Q,55);
    elemQueue(&Q);
    //出队
    ElemType deledata1;
    deQueue(&Q,&deledata1);
    printf("出队的元素：%d\n",deledata1);
    elemQueue(&Q);
    ElemType deledata2;
    deQueue(&Q,&deledata2);
    printf("出队的元素：%d\n",deledata2);
    elemQueue(&Q);








    return 0;
}