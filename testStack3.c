#include <stdio.h>
#include <stdlib.h>


//链式结构栈
typedef int ElemType;
typedef struct stack{
    ElemType data;
    struct stack *next;
}Stack;
//初始化
Stack * initStack(){
    Stack *s=(Stack*)malloc(sizeof(Stack));
    s->data=0;
    s->next=NULL;
    return s;
}
//判断栈是否为空
int isEmpty(Stack *s){
    if(s->next==NULL){
        printf("空的\n");
        return 1;
    }
    return 0;
}
//进栈（头插法）
int push(Stack *s,ElemType e){
    Stack *p=(Stack*)malloc(sizeof(Stack));
    p->data=e;
    p->next=s->next;
    s->next=p;
    return 1;
}
//出栈
int pop(Stack *s,ElemType *e){
    if(s->next==NULL){
        printf("空的\n");
        return 0;
    }
    Stack *q=s->next;
    *e=q->data;
    s->next=q->next;
    free(q);
    return 1;
}
//获取栈顶元素
int getTop(Stack *s,ElemType *e){
    if(s->next==NULL){
        printf("空的\n");
        return 0;
    }
    *e=s->next->data;
    return 1;
}
//遍历
void elemStack(Stack *s){
    if(s->next==NULL){
        printf("空的\n");
        return ;
    }
    Stack *p=s;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main(){
    Stack *stack;
    //初始化
    stack=initStack();
    //进栈
    push(stack,1);
    push(stack,2);
    push(stack,3);
    push(stack,4);
    push(stack,5);
    push(stack,6);
    push(stack,17);
    push(stack,8);
    elemStack(stack);
    //获取栈顶元素
    ElemType topdata;
    getTop(stack,&topdata);
    printf("栈顶元素为：%d\n",topdata);
    //出栈
    ElemType popdata;
    pop(stack,&popdata);
    printf("删除的元素为：%d\n",popdata);







    return 0;
}
