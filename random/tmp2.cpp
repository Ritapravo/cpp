#include<stdio.h>

int a = 10;
void B(){
    int b;
    int c = 30;
    a = 40;
}
int main(){
    int a = 20;
    int b;
    b = 30;
    B();
    printf("%d %d", a,b);
}