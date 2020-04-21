//coin changing problem - minimum coins
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;
void print(int row, int col);
int dp[101][1001];


int solve(int arr[], int n , int s){
    if(s==0){
        dp[n][s] = 0;
        return dp[n][s];
    }
    if(n==0){
        dp[n][s] = INT_MAX-1;
        return dp[n][s]; 
    }
    if(dp[n][s]!=-1)
        return dp[n][s];
    if(arr[n-1]>s){
        dp[n][s] = solve(arr, n-1, s);
        return dp[n][s];
    }
    else{
        dp[n][s] =min(1+solve(arr,n,s-arr[n-1]),solve(arr,n-1,s));
        return dp[n][s];
    }
}

signed main(){
    memset(dp, -1, sizeof(dp));
    int n =3, s = 5;
    int arr[] = {3,2,1};
    cout<<solve(arr, n, s)<<endl;
    print(n,s);
    return 0;
}



void print(int row, int col){
    for(int i = 0; i<=row; i++){
        for(int j = 0; j<=col; j++){
            cout<<(dp[i][j]==INT_MAX-1 ? "M":(dp[i][j]==-1 ? "X":to_string(dp[i][j])))<<" ";
        }
        cout<<endl;
    }
}