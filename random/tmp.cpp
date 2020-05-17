#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;
void print(v(v(int)) &arr);
void print(v(int)&arr);

int min3(int a, int b, int c){
    return min(a,min(b,c));
}

int solve(int arr[], int n, int m){
    if(n==0){
        return 0;
    }
    if(arr[n-1]==0){
        return 1 + count(arr, n-1, 0);
    }
    if(arr[n-1]==1){
        if(m==0){
            
        }    
        return min(1+count(arr, n-1, 0), (m==1? INT_MAX: count(arr, n-1, 1)));
    }
    if(arr[n-1]==2){
        return min(1+count(arr, n-1, 0), (m==2? INT_MAX: count(arr, n-1, 2)));
    }
    else{

    }
}


signed main(){
    int arr = {1,3,3,2,1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = solve(arr, n, 0);
}
