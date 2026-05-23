#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct node{
    ElemType data;
    struct node *next;
}Node;

//初始化(创建头节点)
Node* initList(){
    Node* head=(Node*)malloc(sizeof(Node));
    head->data=0;
    head->next=NULL;
}
//头插法(添加元素)
int insertHead(Node* L,ElemType e){
    Node* p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->next=L->next;
    L->next=p;
    return 1;
}
//遍历
void listElem(Node* L){
    Node* p=L;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
//尾插法（添加元素）
Node* get_tail(Node* L){
    Node* p=L;
    while(p->next !=NULL){
        p=p->next;
    }
    return p;
}
Node* insertTail(Node* tail,ElemType e){
    Node* p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->next=NULL;
    tail->next=p;
    return p;//直接返回尾节点，这样就不用每次都get_tail
}
//在指定位置插入数据
int insertNode(Node* L,int pos,ElemType e){
    Node *p=L;
    int i=0;
    while(i<pos-1){
        p=p->next;
        i++;
        if(p==NULL){
        return 0;
        }
    }
    Node* q=(Node*)malloc(sizeof(Node));
    q->data=e;
    q->next=p->next;
    p->next=q;
    return 1;
}
//删除节点
int deleteNode(Node* L,int pos){
    Node *p=L;
    int i=0;
    while(i<pos-1){
        p=p->next;
        i++;
        if(p==NULL){
            return 0;
        }
    }
    Node *q=p->next;
    p->next=q->next;
    free(q);
    return 1;
}
//获取链表长度
int listLength(Node* L){
    int len =0;
    Node* p=L;
    while(p!=NULL){
        p=p->next;
        len++;
    }
    return len;
}
//释放链表
void freeList(Node* L){
    Node* p=L->next;
    Node *q;
    while(p!=NULL){
        q=p->next;
        free(p);
        p=q;
    }
    L->next=NULL;
}










int main(){
    Node *list;//声明一个list指针（地址）指向Node类型
    list = initList();//初始化
    listElem(list);
    //头插法插入元素
    insertHead(list,10);
    insertHead(list,20);
    insertHead(list,30);
    insertHead(list,40);
    listElem(list);
    printf("%d\n",listLength(list));
    //尾插法插入元素
    Node* tail=get_tail(list);
    tail=insertTail(tail,66);
    tail=insertTail(tail,99);
    tail=insertTail(tail,103);
    listElem(list);
    printf("%d\n",listLength(list));
    //在指定位置插入元素
    insertNode(list,5,250);
    listElem(list);
    printf("%d\n",listLength(list));
    //删除节点
    deleteNode(list,5);
    listElem(list);
    printf("%d\n",listLength(list));
    //释放链表
    freeList(list);
    listElem(list);


    return 0;    
}

