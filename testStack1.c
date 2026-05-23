#include <stdio.h>
#include <stdlib.h>


//栈的存储结构(顺序结构--无动态内存分配)
#define MAXSIZE 100
typedef int ElemType;
typedef struct {
    ElemType data[MAXSIZE];
    int top;
}Stack;
//初始化
void initStack(Stack *s){
    s->top=-1;
}
//判断是否为空栈
int isEmpty(Stack *s){
    if(s->top==-1){
        printf("空的\n");
        return 1;
    }
    return 0;
}
//进栈
int push(Stack *s,ElemType e){
    if(s->top>=MAXSIZE-1){
        printf("已满\n");
        return 0;
    }
    s->top++;
    s->data[s->top]=e;
    return 1;
}
//出栈
int pop(Stack *s ,ElemType *e){
    if(s->top==-1){
        printf("空的\n");
        return 0;
    }
    *e=s->data[s->top];
    s->top--;
    return 1;
}
//获取栈顶元素
int getTop(Stack *s,ElemType *e){
    if(s->top==-1){
        printf("空的\n");
        return 0;
    }
    *e=s->data[s->top];
    return 1;
}
//遍历
void elemStack(Stack *s){
    if(s->top==-1){
        printf("空的\n");
        return;
    }
    for(int i=0;i<=s->top;i++){
        printf("%d ",s->data[i]);
    }
    printf("\n");
}

int main(){
    Stack stack1;
    //初始化
    initStack(&stack1);
    //进栈
    push(&stack1,30);
    push(&stack1,15);
    push(&stack1,86);
    push(&stack1,99);
    push(&stack1,105);
    push(&stack1,12);
    elemStack(&stack1);
    //出栈
    ElemType popdata;
    pop(&stack1,&popdata);
    printf("出栈的元素：%d\n",popdata);
    elemStack(&stack1);
    //获取栈顶元素
    ElemType topdata;
    getTop(&stack1,&topdata);
    printf("栈顶元素：%d\n",topdata);



    return 0;
}
