#include <stdio.h>
int main(){
    int a[]={15,22,67,43,87};
    int *p;
    p=a;
    //printf("%p\n",p);
    //printf("%p\n",a);
    //printf("%d\n",*p);
    for(int i=0;i<5;i++){
        printf("%d\n",*(p+i));
    }
    
    return 0;
}