#include<stdio.h>
int a = 8;

int main(){
    extern int a;
    printf("%d\n", a);
    a = 20;
    printf("%d\n", a);
    return 0;
}
