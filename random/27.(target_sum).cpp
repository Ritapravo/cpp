//assign + ans - such a way that the result is the target
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
        dp[n][s] = solve(arr, n-1, s);
        return dp[n][s];
    }
    else{
        int x = solve(arr, n-1, s-arr[n-1]);
        int y = solve(arr, n-1, s);
        if(x==1 || y==1)
            dp[n][s] = 1;
        else 
            dp[n][s] = 0;
        return dp[n][s];
    }
}


signed main(){
    cout<<"Hello Ritoman"<<endl;
    memset(dp, -1, sizeof(dp));
    int arr[] = {1,1,1,1,1};
    int target = 3;
    int sum = 0, n = sizeof(arr)/sizeof(arr[0]);
    for(int i =0; i<n ; i++)sum+=arr[i];
    int ans;
    if((sum+target)%2==1)
        ans = 0;
    else 
        ans = solve(arr, n, (target+sum)/2);
    cout<<ans<<endl;
    print(n,(target+sum)/2 );
    return 0;
}

void print(int row, int col){
    for(int i =0; i<=row; i++){
        for(int j=0; j<=col; j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
}