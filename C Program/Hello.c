#include<stdio.h>

int main()
{
    char a='a';
    char *p=&a;
    printf("the address of a is:%c",*p);
    return 0;
}