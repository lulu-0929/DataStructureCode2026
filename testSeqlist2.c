#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElemType;
typedef struct {
    ElemType *data;
    int length;
}Seqlist;

//初始化函数
Seqlist* initList(){
    Seqlist *L=(Seqlist*)malloc(sizeof(Seqlist));
    L->data=(ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    L->length=0;
    return L;
}
//添加元素
void appendElem(Seqlist *L,ElemType e){
    L->data[L->length]=e;
    L->length++;
}
//遍历
void listElem(Seqlist *L){
    for(int i=0;i<L->length;i++){
        printf("%d ",L->data[i]);
    }
    printf("\n");
}
//插入元素
int insertElem(Seqlist *L,int pos,ElemType e){
    if(L->length==0){
        printf("空表\n");
        return 0;
    }
    if(pos<1 || pos >L->length){
        printf("插入位置错误!\n");
        return 0;
    }
    if(pos <=L->length){
        for(int i=L->length-1;i>=pos-1;i--){
            L->data[i+1]=L->data[i];
        }
        L->data[pos-1]=e;
        L->length++;
    }
    return 1;
}
//删除元素
int deleteElem(Seqlist *L,int pos,ElemType *e){
    if(L->length==0){
        printf("空表\n");
        return 0;
    }
    if(pos<1 || pos >L->length){
        printf("删除位置错误!\n");
        return 0;
    }
    *e=L->data[pos-1];
    if(pos<L->length){
        for(int i=pos;i<L->length;i++){
            L->data[i-1]=L->data[i];
        }
        L->length--;
    }
    return 1;
}
//查找元素
int findElem(Seqlist *L,ElemType e){
    for(int i=0;i<L->length;i++){
        if(L->data[i]==e){
            return i+1;
        }
    }
    return 0;
}

int main(){
    Seqlist *list;
    //初始化
    list=initList();
    //添加元素
    appendElem(list,83);
    appendElem(list,66);
    appendElem(list,33);
    appendElem(list,95);
    appendElem(list,23);
    appendElem(list,25);
    listElem(list);
    //插入元素
    insertElem(list,3,900);
    listElem(list);
    //删除元素
    ElemType deldata;
    deleteElem(list,4,&deldata);
    printf("删除元素：%d\n",deldata);
    listElem(list);
    //查找元素
    int flag=findElem(list,33);
    printf("33是否在顺序表里：%d\n",flag);
    return 0;


}


