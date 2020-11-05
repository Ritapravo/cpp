#include<iostream>
#include<bits/stdc++.h>
#define int long long int
using namespace std;


void merge(int arr[], int l, int mid, int h){
    int n1 = mid-l+1, n2 = h-mid;
    int a[n1], b[n2];
    for(int i=0; i<n1; i++)a[i] = arr[l+i];
    for(int i=0; i<n2; i++)b[i] = arr[mid+i+1];
    int i = 0, j = 0, k = l;
    while(i<n1 && j<n2){
        if(a[i]<b[j])arr[k++]=a[i++];
        else arr[k++] = b[j++];
    }
    while(i<n1)arr[k++]=a[i++];
    while(j<n2)arr[k++]=b[j++];  
}

void mergesort(int arr[], int l, int h){
    if(l<h){
        int mid = (l+h)/2;
        mergesort(arr, l, mid);
        mergesort(arr, mid +1, h);
        merge(arr, l, mid, h);
    }
}


signed main(){
    int arr[] =  {10, 11, 10, 9, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,0,n-1);
    for(int i = 0; i<n; i++)cout<<arr[i]<<" ";
    return 0;
}


//g++ "47.MergeSort.cpp" && a
//g++ "F:\cpp\random\47.MergeSort.cpp" && a 