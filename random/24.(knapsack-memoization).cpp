//0-1 knapsack problem using memoization dp
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;
void print(int row, int col);
int knapsack(int wt[], int val[], int w, int n );
void ks(int wt[], int val[], int w, int n , string curr = "");
int dp[100][100];



signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(dp,-1,sizeof(dp));
    int wt[] = {1,3,4,5};
    int val[]= {1,5,5,9};
    int n = 4, w = 7;
    cout<<knapsack(wt, val, w, n)<<endl;
    print(n+1, w+1);
    ks(wt, val, w, n);
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


void ks(int wt[], int val[], int w, int n , string curr){
    if(n==0 || w==0){
        cout<<curr<<endl;
        return;
    }
    if(w<wt[n-1]){
        ks(wt, val, w, n-1, curr);
    }
    else{
        if(dp[n][w]==dp[n-1][w])
            ks(wt, val, w, n-1, curr);
        if(dp[n][w]==val[n-1]+dp[n-1][w-wt[n-1]]){
            curr = curr + " "+ to_string(val[n-1]);
            ks(wt, val, w-wt[n-1], n-1, curr);
        }
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