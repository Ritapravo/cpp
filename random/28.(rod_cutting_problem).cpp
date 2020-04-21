//unbounded knapsack || rod cutting problem
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;
int dp[101][1001];

int ks(int length[], int values[], int n , int l){
    if(n==0 || l==0){
        dp[n][l] = 0;
        return dp[n][l];
    }
    if(dp[n][l]!=-1){
        return dp[n][l];
    }
    if(length[n-1]>l){
        dp[n][l] = ks(length , values, n-1, l);
        return dp[n][l];
    }
    else{
        dp[n][l] = max(values[n-1]+ks(length, values, n, l-length[n-1]),
                        ks(length, values, n-1, l));
        return dp[n][l];
    }
}


signed main(){
    memset(dp, -1, sizeof(dp));
    int n = 4, l = 7;
    int length[] = {1,2,3,4};
    int values[] = {5,6,16,8};
    cout<<ks(length, values, n , l)<<endl;
    return 0;
}
