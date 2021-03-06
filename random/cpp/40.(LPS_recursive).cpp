//Longest Palindromic Subsequence(recursive)
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;
int dp[101][101];
void print(int row, int col);

int solve(string s, int i, int j){
    if(i==j){
        dp[i][j] = 1;
        return dp[i][j];
    }
    if(i>j){
        dp[i][j] = 0;
        return dp[i][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s[i]==s[j]){
        dp[i][j] = solve(s, i+1, j-1) + 2;
        return dp[i][j];
    }
    else{
        dp[i][j] = max(solve(s, i, j-1), solve(s,i+1,j));
        return dp[i][j];
    }
}


signed main(){
    cout<<"Hello Ritoman"<<endl;
    memset(dp, -1, sizeof(dp));
    string s = "alpha";
    int n = s.size();
    int ans = solve(s, 0, n-1);
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