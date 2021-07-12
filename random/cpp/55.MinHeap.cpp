//implementation of min heap

#include<iostream>
#include<bits/stdc++.h>
#define int long long int
#define N 20
using namespace std;
void adjust(int[], int, int);   //O(log(n))
void heapify (int[], int);      //O(n)
void heapify2(int[], int);      //O(nlog(n))
void push(int[], int &, int);   //O(log(n))
int  pop(int[], int & );        //O(log(n))
void heapsort(int[], int);      //O(nlog(n))
void change(int[],int,int,int); //O(nlog(n))

signed main(){
    cout<<"Hello Ritoman"<<endl;
    int arr[N] = {60,50,20,15,70,80,50,25,90};
    int n = 9;
    heapify(arr, n);
    //push(arr,n,65);
    //push(arr,n,75);
    //int x = pop(arr,n);
    //heapsort(arr,n);
    //change(arr,7,10,n);
    for(int i = 0; i<n; i++){cout<<arr[i]<<" ";}  
    return 0;
}


void change(int arr[], int i, int key, int n){
    if(key<arr[i]){
        while(i>0 and arr[(i-1)/2]>key){
            arr[i] = arr[(i-1)/2];
            i = (i-1)/2;
            arr[i] = key; 
        }
    }
    else if(key>arr[i]){
        arr[i] = key;
        adjust(arr,i,n);
    }
}


void heapsort(int arr[],int n){
    heapify(arr,n);
    for(int i = n-1; i>0; i--)
        arr[i] = pop(arr,n);
}


void heapify2(int arr[], int n){
    int temp[N];
    int n1 = 0;
    for(int i = 0; i<n; i++){push(temp,n1,arr[i]);}
    for(int i = 0; i<n; i++){arr[i] = temp[i];}
}

void adjust(int arr[], int i, int n){
    int j = 2*i + 1;
    int item = arr[i];
    while(j<n){
        if(j<n-1 && arr[j]>arr[j+1])j++;
        if(arr[j]>=item)break;
        arr[(j-1)/2] = arr[j];
        arr[j] = item;
        j = 2*j + 1;
    }
}

void heapify(int arr[], int n){
    for(int i = n/2-1; i>=0; i--){
        adjust(arr, i, n);
    }
}

void push(int arr[], int &n, int x){
    int i = n;
    while(i>0 and arr[(i-1)/2]>x){
        arr[i] = arr[(i-1)/2];
        i = (i-1)/2;
    }
    arr[i] = x;
    n ++;
}

int pop(int arr[], int &n ){
    int item = arr[0];
    arr[0] = arr[n-1];
    adjust(arr,0,n-1);
    n--;
    return item;
}


//g++ "55.minheap.cpp" && a
//g++ "F:\cpp\random\55.minheap.cpp" && a 