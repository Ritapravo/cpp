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
    int i = p+1, j = q, x =arr[p];
    while(i<=j){
        while(i<=j && (arr[i]<=x ||arr[j]>=x)){
			if (arr[i]<=x)i++;
			if (arr[j]>=x)j--;
		}
		if(i<j)swap(arr[i],arr[j]);
    }
    swap(arr[pivot],arr[j]);
    return j;
}


void QuickSort(int arr[], int p, int q){
    if(p<q){
        int j = partition(arr,p,q);
        QuickSort(arr, p, j-1);
        QuickSort(arr, j+1, q);
    }
}


signed main(){
    cout<<"Hello Ritoman"<<endl;
    int arr[] = {35,20,40,50,30,60,15,75};
    int n = sizeof(arr)/sizeof(arr[0]);
    QuickSort(arr,0,n-1);
    for(int i = 0; i<n; i++){cout<<arr[i]<<" ";}


	int arr2[] = {2,2,2,2,2,2,2};
	int n2 = sizeof(arr2)/sizeof(arr2[0]);
    int x = partition(arr2,0,n2-1);
	cout<<"\n"<<x<<endl;
    for(int i = 0; i<n2; i++){cout<<arr2[i]<<" ";}
    return 0;
}

//g++ "51.QuickSort.cpp" && a
//g++ "F:\cpp\random\51.QuickSort.cpp" && a 




/* int partition_fail(int arr[], int p, int q){
    int pivot = p;
    int i = p, j = q+1, x =arr[p];
    while(i<j){
        while(arr[++i]<x);
        while(arr[--j]>x);
        if(i<j)swap(arr[i],arr[j]);
    }
    swap(arr[pivot],arr[j]);
    return j;
} */