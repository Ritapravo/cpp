#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void print(int[], int);
void swap(int &, int &);
void bubblesort(int[], int);
void insertionsort(int[], int);
void selectionsort(int[], int);
void mergesort(int [], int, int);
void quicksort(int [], int, int);



int main(){
    int arr[] = {5,6,9,5,7,8,7};
    int n = sizeof(arr)/sizeof(int);
    //bubblesort(arr, n);
    //insertionsort(arr, n);
    
    //selectionsort(arr, n);
    //mergesort(arr, 0, n-1);
    quicksort(arr, 0, n-1);
    print(arr, n);
    
    return 0;
}



void bubblesort(int arr[], int n){
    for(int i = 0; i<n; i++){
        bool swapped = false;
        for(int j = 0; j<n-1-i; j++){
            if (arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void insertionsort(int arr[], int n){
    for(int i=1; i<n; i++){
        int j = i-1, tmp = arr[i];
        while(j>=0 && arr[j]>tmp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=tmp;
    }
}

void selectionsort(int arr[], int n){
    for(int i = 0; i<n-1; i++){
        int minpos = i;
        for(int j = i+1; j<n; j++){
            if(arr[minpos]>arr[j])
                minpos = j;
        }
        swap(arr[minpos], arr[i]);
    }
}

void merge(int arr[], int low, int mid, int high){
    int n1 = mid-low+1, n2 = high - mid;
    int a[n1], b[n2], i =0, j = 0, k = low;
    for(int i = 0; i<n1; i++){a[i]=arr[low+i];}
    for(int i = 0; i<n2; i++){b[i]=arr[mid+1+i];}
    while(i<n1 && j<n2){
        if(a[i]<b[j])arr[k++] = a[i++];
        else arr[k++]=b[j++];
    }
    while(i<n1)arr[k++] = a[i++];
    while(j<n2)arr[k++] = b[j++];
}
void mergesort(int arr[], int l, int h){
    if(l<h){
        int mid = l + (h-l)/2;
        mergesort(arr, l,mid);
        mergesort(arr, mid+1, h);
        merge(arr, l, mid, h);
    }
}

int partition(int arr[], int l, int h){
    int pivot = arr[h], i = l-1;
    for(int j = l; j<h; j++)
        if(arr[j]<pivot)
            swap(arr[++i],arr[j]);
    swap(arr[i+1],arr[h]);
    return i+1;
}

void quicksort(int arr[], int l, int h){
    if(l<h){
        int j = partition(arr,l,h);
        quicksort(arr, l, j-1);
        quicksort(arr, j+1, h);
    }
}

void print(int arr[], int n){
    for(int i = 0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}