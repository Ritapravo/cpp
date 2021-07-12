//counting inversions in inversions
//inversion if i<j and arr[i]>arr[i]

#include<iostream>
#include<bits/stdc++.h>
#define int long long int
using namespace std;
int merge(int [], int, int, int);
int inversions(int[], int, int);
int compute(int[], int);

signed main(){
    int arr[] =  {6,5,3,8,2,9,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans2 = compute(arr,n);
    int ans = inversions(arr,0,n-1);
    cout<<ans2<<" "<<ans<<endl;
    //for(int i = 0; i<n; i++)cout<<arr[i]<<" ";
    return 0;
}


int merge(int arr[], int l, int mid, int h){
    int n1 = mid-l+1, n2 = h-mid, inv =0;
    int a[n1], b[n2];
    for(int i=0; i<n1; i++)a[i] = arr[l+i];
    for(int i=0; i<n2; i++)b[i] = arr[mid+i+1];
    int i = 0, j = 0, k = l;
    while(i<n1 && j<n2){
        if(a[i]<=b[j])arr[k++]=a[i++];
        else{ 
            arr[k++] = b[j++];
            inv += mid -(l+i) + 1;
        }
    }
    while(i<n1)arr[k++]=a[i++];
    while(i<n2)arr[k++]=b[j++]; 
    return inv; 
}

int inversions(int arr[], int l, int h){
    if(l<h){
        int mid = (l+h)/2;
        return  inversions(arr, l, mid)+
                inversions(arr, mid +1, h)+
                merge(arr, l, mid, h);
    }
    return 0;
}

int compute(int arr[], int n){
    int inv = 0;
    for(int i = 0; i<n-1; i++)
        for(int j =i+1; j<n; j++)
            if(arr[i]>arr[j])
                inv ++;
    return inv;
}

//g++ "48.Inversions_inversions.cpp" && a
//g++ "F:\cpp\random\48.Inversions_inversions.cpp" && a 