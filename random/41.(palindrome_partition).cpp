//Palindrome partition
#include<iostream>
#include<bits/stdc++.h>
#define v(x) vector<x>
#define int long long int
using namespace std;
void print(int row, int col);
int dp[101][101];

bool ispal(string s, int i, int j){
    int n = j-i+1;
    for(int k =0 ; k<n/2; k++)
        if(s[i+k]!=s[j-k])
            return false;
    return true;
}

int solve(string s, int i, int j){
    if(i>=j){
        dp[i][j] = 0;
        return dp[i][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(ispal(s,i,j)){
        dp[i][j] = 0;
        return dp[i][j];
    }
    int mn = INT_MAX;
    for(int k = i; k<j; k++){
        if(dp[i][k]==-1)
            dp[i][k] = solve(s,i,k);
        if(dp[k+1][j]==-1)
            dp[k+1][j] = solve(s, k+1, j);

        int tmp = 1 + dp[i][k] + dp[k+1][j];
        mn = min(tmp,mn);
    }
    dp[i][j] = mn;
    return dp[i][j];
}

signed main(){
    memset(dp, -1, sizeof(dp));
    string s = "ababb";
    int n = s.size();
    int ans = solve(s,0,n-1);
    cout<<ans<<endl;
    print(n-1,n-1);

}

void print(int row, int col){
    for(int i= 0; i<= row; i++){
        for (int j = 0; j<=col; j++)
            cout<<(dp[i][j]==-1 ? "X":to_string(dp[i][j]))<<" ";
        cout<<endl;
    }
}

