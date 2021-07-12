#include<iostream>
#include<bits/stdc++.h>
using namespace std;

pair<int, int> max_min(int arr[], int low, int high){
    int ma, mi;
    if(low==high){
        ma = arr[low];
        mi = arr[low];
    }
    else if(low == high - 1){
        ma = max(arr[low],arr[high]);
        mi = min(arr[low],arr[high]);
    }
    else{
        int mid = low + (high-low)/2;
        pair<int, int>p1 = max_min(arr, low, mid);
        pair<int, int>p2 = max_min(arr,mid+1,high);
        ma = max(p1.first, p2.first);
        mi = min(p1.second,p2.second);
    }
    return pair<int, int>{ma,mi};
}


int main(){
    int arr[] = {35,20,40,30,60,15,75,76,76};
    int n = sizeof(arr)/sizeof(arr[0]);
    pair<int, int>p = max_min(arr,0, n-1);
    cout<<p.first<<" "<<p.second<<endl;
}

//g++ "53.max_min.cpp" && a
//g++ "F:\cpp\random\53.max_min.cpp" && a 















/* 
pair<int, int> max_min(int arr[], int low, int high, int ma, int mi){
    if(low==high){
        ma = arr[low];
        mi = arr[low];
    }
    else if(low = high - 1){
        ma = max(arr[low],arr[high]);
        mi = min(arr[low],arr[high]);
    }
    else{
        int mid = low + (high-low)/2;
        int ma1,ma2,mi1,mi2;
        max_min(arr, low, mid, ma1, mi1);
        max_min(arr,mid+1,high,ma2, mi2);
        ma = ma1>ma2?ma1:ma2;
        mi = mi1<mi2?mi1:mi2;
    }
    return pair<int, int>{ma,mi};
} */