//coin changing problem -> number of ways
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;
int dp[101][1001];

int solve(int arr[], int n , int s){
    if(s==0){
        dp[n][s] = 1;
        return dp[n][s];
    }
    if(n==0){
        dp[n][s] = 0;
        return dp[n][s]; 
    }
    if(dp[n][s]!=-1)
        return dp[n][s];
    if(arr[n-1]>s){
        dp[n][s] = solve(arr, n-1, s);
        return dp[n][s];
    }
    else{
        dp[n][s] = solve(arr,n,s-arr[n-1]) + solve(arr,n-1,s);
        return dp[n][s];
    }
}

signed main(){
    memset(dp, -1, sizeof(dp));
    int n =3, s = 6;
    int arr[] = {1,2,3};
    cout<<solve(arr, n, s)<<endl;
    return 0;
}
