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
    while(i<n2)arr[k++]=b[j++];  
}

void mergesort_2_way(int arr[], int l, int h){
    int i = 1;
    int n = h-l+1;
    while(i<n){
        for(int j = 0; j<n; j+=2*i){
            l = j;
            int mid = j+i-1;
            h = j+2*i-1;
            mid = mid>=n?n-1:mid;
            h = h>=n?n-1:h;
            //cout<<l<<" "<<mid<<" "<<h<<endl;
            merge(arr, l, mid, h);
        }
        i = 2*i;
    }
}


signed main(){
    int arr[] =  {3,7,2,5,1,6,9,3,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergesort_2_way(arr,0,n-1);
    for(int i = 0; i<n; i++)cout<<arr[i]<<" ";
    return 0;
}


//g++ "50.2_way_mergesort.cpp" && a
//g++ "F:\cpp\random\50.2_way_mergesort.cpp" && a 