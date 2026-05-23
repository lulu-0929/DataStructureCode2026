#include <stdio.h>
#include <string.h>



#define MAXSIZE 100
typedef int ElemType;
typedef struct {
    ElemType data[MAXSIZE];
    int length;
}Seqlist;
void initList(Seqlist *L){
    L->length=0;
}
int appendElem(Seqlist *L,ElemType e){
    if(L->length>=MAXSIZE){
        printf("顺序表已满\n");
        return 0;
    }
    L->data[L->length]=e;
    L->length++;
    return 1;   
}
void listElem(Seqlist *L){
    for (int i=0;i<L->length;i++){
        printf("%d ",L->data[i]);
    }
    printf("\n");
}
int insertElem(Seqlist *L,int pos,ElemType e){
    if(L->length==0){
        printf("空表\n");
        return 0;
    }
    if(pos<1 || pos>L->length){
        printf("插入位置错误!\n");
        return 0;
    }
    for (int i=L->length-1;i>=pos-1;i--){
        L->data[i+1]=L->data[i];        
    }
    L->data[pos-1]=e;
    L->length++;
    return 1;
}
int deleteElem(Seqlist *L,int pos,ElemType *e){
    
    if(L->length==0){
        printf("空表\n");
        return 0;
    }
    if(pos<1 || pos >L->length){
        printf("删除位置错误!\n");
        return 0;
    }
    *e =L->data[pos-1];//记录删除的元素
    if(pos <L->length){
        for(int i=pos;i<L->length;i++){
            L->data[i-1]=L->data[i];
        }
    }
    L->length--;
    return 1;
}
int findElem(Seqlist *L,ElemType e){
    for (int i=0;i<L->length;i++){
        if(L->data[i]==e){
            return i+1;//返回找到元素的位置
        }
    }
    return 0;
}
int main(){
    Seqlist list;//声明一个seqlist类型的数据list
    initList(&list);//初始化
    //添加元素
    appendElem(&list,83);
    appendElem(&list,66);
    appendElem(&list,33);
    appendElem(&list,95);
    appendElem(&list,23);
    appendElem(&list,25);
    listElem(&list);
    //插入元素
    insertElem(&list,3,900);
    listElem(&list);
    //删除元素
    ElemType deldata;
    deleteElem(&list,2,&deldata);
    printf("删除的元素是：%d\n",deldata);
    listElem(&list);
    //查找元素
    int flag=findElem(&list,33);
    printf("33在顺序表里的位置：%d\n",flag);
    return 0;
}


