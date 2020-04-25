#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;
int dp[101][101];
void print(int row, int col);

int solve(int arr[], int i, int j){
    if(i==j){
        dp[i][j] = 0;
        return dp[i][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mn = INT_MAX;
    for(int k = i; k<j; k++){
        int tmp = solve(arr, i, k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        mn = min(mn, tmp);
    }
    dp[i][j] = mn;
    return mn;
}


signed main(){
    cout<<"Hello Ritoman"<<endl;
    memset(dp, -1, sizeof(dp));
    int arr[] = {40,20,30,10,30};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = solve(arr, 1, n-1);
    cout<<ans<<endl;
    print(n-1,n-1);
    return 0;
}

void print(int row, int col){
    for(int i =0; i<=row; i++){
        for (int j =0; j<=col; j++)
            cout<<(dp[i][j]==-1? "X":to_string(dp[i][j]))<<" ";
        cout<<endl;
    }
}