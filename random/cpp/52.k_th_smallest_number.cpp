//find kth smallest element when all elements are distinct

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
    int pivot = arr[q], i = p;
    for(int j = p; j<q; j++)
        if(arr[j]<pivot)swap(arr[i++],arr[j]);
    swap(arr[i],arr[q]);
    return(i);
}

int kth_smallest(int arr[], int n , int k){
    int p =0, q = n-1;
    k--;
    while(p<=q){
        int j = partition(arr,p,q);
        if(j==k)
            return arr[j];
        if(k<j)
            q = j-1;
        else
            p = j+1;
    }
    return -1;
}


signed main(){
    cout<<"Hello Ritoman"<<endl;
    int arr[] = {35,20,40,50,30,60,15,75};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = kth_smallest(arr,n,5);
    cout<<x<<endl;
    for(int i = 0; i<n; i++){cout<<arr[i]<<" ";}
    return 0;
}

//g++ "52.k_th_smallest_number.cpp" && a
//g++ "F:\cpp\random\52.k_th_smallest_number.cpp" && a 