//subsetsum problem using Memoization
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;
void print(int row, int col);
int dp[101][1001];

int subsetsum(int arr[], int n , int s){
    if(s==0){
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
        dp[n][s]  = subsetsum(arr, n-1, s);
        return dp[n][s];
    }
    else{
        if((subsetsum(arr, n-1, s)==1)|| (subsetsum(arr, n-1, s-arr[n-1])==1))
            dp[n][s] = 1;
        else    
            dp[n][s] = 0;
        return dp[n][s];
    }
}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(dp,-1, sizeof(dp));
    int arr[] = {2,3,7,8,10};
    int n = 5, s = 13;
    cout<<subsetsum(arr, n, s)<<endl;
    print(n+1, s+1);
    return 0;
}



void print(int row, int col){
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}