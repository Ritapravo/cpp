#include <iostream>
#include <vector>
#include <string>
#include<stdio.h>
#include <conio.h>

using namespace std;

void insertionsort(int array[], int n){
    for (int j = 1; j < n; j++)
    {
        int key = array[j];
        int i=j-1;
        while(i>=0 && array[i]>key){
            array[i+1]=array[i];
            i-=1;
        }
        array[i+1]=key;
    }
}

int main()
{

    int n,i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int array[6];
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&array[i]);
    }
    insertionsort(array,n);
    
    for ( i = 0; i<n; i++)
    {
        printf("%d ",array[i]);
    }

}
