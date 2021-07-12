#include <stdio.h>

void For(int a, int b, int c){
    printf("%d\n", a+b+c);
}
void While(int a, int b){
    printf("%d\n",a-b);
}
void If(int a){
    printf("%d\n",a);
}

int main()
{
    int a = 4, b = 3, c = 2;
    If(a);
    For(a,b,c);
    while(5,1){
        printf("Haguman\n");
        break;
    }
    return 0;
}
//g++ "test.cpp" && a
//g++ "F:\cpp\random\test.cpp" && a 