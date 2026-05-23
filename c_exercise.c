#include <stdio.h>
#include <string.h>
int main(){
    //字符串
    char str[]="HelloWorld!!!";
    int len=sizeof(str)/sizeof(str[0]);
    for(int i=0;i<len;i++){
        printf("%c",str[i]);
    }
    printf("\n");
    char str2[13];
    strcpy(str2,"Hello VScode");
    int len2=sizeof(str2)/sizeof(str2[0]);
    for(int i=0;i<len2;i++){
        printf("%c",str2[i]);
    }
    printf("\n======================\n");
    //数组
    int arr1[]={116,52,7854,55,54,656};
    printf("%p\n",&arr1);
    printf("%p\n",&arr1[0]);
    printf("\n=======================\n");
    //指针
    int a=5;
    int *p=&a;
    printf("%p\n",&a);
    printf("%p\n",p);
    printf("%p\n",&p);
    *p=100;
    printf("%d\n",a);
    printf("%p\n",&a);
    return 0;
}