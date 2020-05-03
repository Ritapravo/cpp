//Longest common substring(recursive dp)
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;
void print(int row, int col);
int dp[101][101];
int ans;

void LCS(string s1, string s2, int n1, int n2){
    if(n1==0 || n2 ==0){
        dp[n1][n2] = 0;
        ans = max(ans, dp[n1][n2]);
    }
    if(dp[n1][n2]!=-1){
        ans = max(ans, dp[n1][n2]);
        return ;
    }
    if(s1[n1-1]==s2[n2-1]){
        LCS(s1,s2,n1-1,n2-1);
        dp[n1][n2] = 1+dp[n1-1][n2-1];
        ans = max(ans, dp[n1][n2]);
    }
    else{
        dp[n1][n2] = 0;
        LCS(s1,s2,n1,n2-1);
        LCS(s1,s2,n1-1,n2);
        ans = max(ans, dp[n1][n2]);
    }
}


signed main(){
    memset(dp, -1, sizeof(dp));
    ans = 0;
    string s1 = "ab", s2 = "cabcdfe";
    int n1 = s1.size(), n2 = s2.size();
    LCS(s1, s2, n1, n2);
    cout<<ans<<endl;
    print(n1,n2);
    return 0;
}

void print(int row, int col){
    for(int i = 0; i<=row; i++){
        for(int j = 0; j<=col; j++){
            cout<<(dp[i][j]==-1 ? "X":to_string(dp[i][j]))<<" ";
        }
        cout<<endl;
    }
}