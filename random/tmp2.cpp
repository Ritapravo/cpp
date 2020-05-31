//0-1 knapsack problem using memoization dp
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;

int knapsack(int wt[], int val[], int w, int n );

int dp[100][100];



signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(dp,-1,sizeof(dp));
	int n,w;
	cin>>n>>w;
    int wt[n], val[n];
    for(int i =0; i<n; i++)cin>>val[i];
	for(int i =0; i<n; i++)cin>>wt[i];
    cout<<knapsack(wt, val, w, n)<<endl;
    return 0;
}



int knapsack(int wt[], int val[], int w, int n ){
    if(n==0 || w==0){
        dp[n][w] = 0;
        return dp[n][w];
    }
    if(dp[n][w]!=-1){
        return dp[n][w];
    }
    if(wt[n-1]<=w){
        dp[n][w] =  max(val[n-1]+knapsack(wt, val, w-wt[n-1], n-1),
                            knapsack(wt, val, w, n-1));
        return dp[n][w];
    }
    else{
        dp[n][w] = knapsack(wt, val, w, n-1);
        return dp[n][w];
    }
}




