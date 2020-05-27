#include<stdio.h>

int main(){
    int x[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    printf("%u %u %u",x, (*x)+1,sizeof(char));
    return 0;
}