#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*struct point
{
    int x;
    int y;
};*/
//创建一个函数，传入两个int参数，
//在函数里创建一个point类型的结构体，
//将传入的两个参数分别赋值，最后将该结构体变量返回
/*struct point creatPoint(int x,int y)
{
    struct point temp;
    temp.x=x;
    temp.y=y;
    return temp;
}*/
/*typedef struct{
    int x;
    int y;
}po;*/


int main(){
    /*struct point
    {
        int x;
        int y;
    };*/
    /*struct point p;
    p.x=11;
    p.y=6;
    struct point *pp;
    pp=&p;
    pp -> x =10;
    pp -> y =5;
    /*(*pp).x=11;
    (*pp).y=6;*/
    /*po p;
    po *pp;
    pp=&p;
    p.x=10;
    p.y=5;
    pp->x=12;
    pp->y=6;
    printf("%d\n",p.x);
    printf("%d\n",p.y); 
    printf("%d\n",pp->x);
    printf("%d\n",pp->y);*/
    char *s;
    s=(char *)malloc(10);
    strcpy(s,"Hello");
    printf("%s\n",s);
    free(s);

    return 0;
}