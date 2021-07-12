#include<stdio.h>

void adjust(int arr[], int i, int n){
    int tmp = arr[i], j = i*2 +1;
    while(j<n && arr[j]<tmp){
        if(j<(n-1) && arr[j+1]<arr[j])j++;
        arr[(j-1)/2]=arr[j];
        arr[j] = tmp;
        j = j*2 + 1;
    }
}

void heapify(int arr[], int n){
    for (int i = n/2 -1 ; i>=0 ; i--)
        adjust(arr, i, n);
}

void insert(int arr[], int &n, int x){
    arr[n] = x;
    int i = n;
    while(i>0 && arr[(i-1)/2]>x){
        arr[i] = arr[(i-1)/2];
        i = (i-1)/2;
    }
    arr[i] = x;
    n++;
}

int main(){
    int arr[] = {60,50,20,15,70,80,50,25,90};
    int n = sizeof(arr)/sizeof(int);
    heapify(arr,n);
    insert(arr, n, 35);
    for(int i = 0; i<n; i++){printf("%d ", arr[i]);}
}

//g++ "p2.cpp" && a
//g++ "F:\cpp\random\p2.cpp" && a 