#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define N 8

void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

int partition(int arr[], int p, int q){
    int pivot = p;
    int i = p, j = q+1, x =arr[p];
    while(i<j){
        while(arr[++i]<x);
        while(arr[--j]>x);
        if(i<j)swap(arr[i],arr[j]);
    }
    swap(arr[pivot],arr[j]);
    return j;
}

void QuickSort(int arr[], int p, int q){
    if(p<q){
        int j = partition(arr,p,q);
        /* cout<<p<<" "<<q<<" "<<j<<endl;
        for(int i = 0; i<N; i++){cout<<arr[i]<<",";}
        cout<<endl; */
        QuickSort(arr, p, j-1);
        QuickSort(arr, j+1, q);
    }
}


signed main(){
    cout<<"Hello Ritoman"<<endl;
    int arr[] = {35,20,40,50,30,60,15,75};
    int n = sizeof(arr)/sizeof(arr[0]);
    //int x = partition(arr,0,7);
    QuickSort(arr,0,n-1);
    //cout<<x<<endl;
    for(int i = 0; i<n; i++){cout<<arr[i]<<" ";}
    return 0;
}

//g++ "51.QuickSort.cpp" && a
//g++ "F:\cpp\random\51.QuickSort.cpp" && a 