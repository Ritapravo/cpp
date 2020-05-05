//number of subsets having a definite sum
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;
void print(int row, int col);
int subsetno(int arr[], int n , int s);
int dp[101][1001];

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(dp, -1, sizeof(dp));
    int arr[] = {0,0,0,0};
    int n  = sizeof(arr)/sizeof(arr[0]);
    int s = 0;
    cout<<subsetno(arr, n, s)<<endl;
    print(n+1, s+1);
    return 0;
}

int subsetno(int arr[], int n , int s){
    if(s==0 && n==0){
        dp[n][s] = 1;
        return dp[n][s];
    }
    if(n==0){
        dp[n][s] = 0;
        return dp[n][s];
    }
    if(dp[n][s]!=-1){
        return dp[n][s];
    }
    if(arr[n-1]>s){
        dp[n][s] = subsetno(arr, n-1, s);
        return dp[n][s];
    }
    else{
        dp[n][s] = subsetno(arr,n-1,s) + subsetno(arr, n-1, s-arr[n-1]);
        return dp[n][s];
    }
}

void print(int row, int col){
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}