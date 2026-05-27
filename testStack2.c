#include <stdio.h>
#include <stdlib.h>

//栈的存储结构(顺序结构--动态内存分配)
#define MAXSIZE 100
typedef int ElemType;
typedef struct{
    ElemType *data;
    int top;
}Stack;
//初始化
Stack* initStack(){
    Stack *s=(Stack*)malloc(sizeof(Stack));
    s->data=(ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    s->top=-1;
    return s;
}
//进栈
int push(Stack* s,ElemType e){
    if(s->top>=MAXSIZE-1){
        printf("已满\n");
        return 0;
    }
    s->top++;
    s->data[s->top]=e;
    return 1;
}
//出栈
int pop(Stack* s,ElemType *e){
    if(s->top==-1){
        printf("空的\n");
        return 0;
    }
    *e=s->data[s->top];
    s->top--;
    return 1;
}
//获取栈顶元素
int getTop(Stack* s,ElemType* e){
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
    Stack *stack2;
    //初始化
    stack2=initStack();
    //进栈
    push(stack2,3);
    push(stack2,13);
    push(stack2,76);
    push(stack2,29);
    push(stack2,105);
    push(stack2,88);
    elemStack(stack2);
    //出栈
    ElemType popdata;
    pop(stack2,&popdata);
    printf("出栈的元素：%d\n",popdata);
    elemStack(stack2);
    //获取栈顶元素
    ElemType topdata;
    getTop(stack2,&topdata);
    printf("栈顶元素：%d\n",topdata);
    return 0;
}