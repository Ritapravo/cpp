#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;
void print(int, int);
int dp[101][101][2];

int solve(string s, int i, int j, bool ind){
    if(i>j){
        return false;
    }
    if(dp[i][j][ind]!=-1){
        return dp[i][j][ind];
    }
    if(i==j){
        dp[i][j][ind] = ind ==(s[i]=='T'?1:0);
        return dp[i][j][ind];
    }
    int ans = 0;
    for(int k = i+1; k<j; k+=2){
        int lt = solve(s, i, k-1, true);
        int lf = solve(s, i, k-1, false);
        int rt = solve(s, k+1, j, true);
        int rf = solve(s, k+1, j, false);
        if(s[k]=='&'){
            if(ind)ans += lt*rt;
            else ans += lf*rf + lt*rf + lf*rt;
        }
        else if(s[k]=='^'){
            if(ind) ans += lt*rf + lf*rt;
            else ans += lf*rf + lt*rt;
        }
        else if(s[k]=='|'){
            if(ind) ans += lt*rf + lf*rt + lt*rt ;
            else ans += lf*rf ;
        }
    }
    dp[i][j][ind] = ans;
    return ans;
}


signed main(){
    //cout<<"Hello Ritoman"<<endl;
    memset(dp,-1,sizeof(dp));
    string s = "F&F&T^T";
    int n = s.size();
    int ans = solve(s,0,n-1, true);
    cout<<ans<<endl;
    print(n-1, n-1);
    return 0;
}


void print(int row, int col){
    cout<<endl;
    for(int i= 0; i<= row; i+=2){
        for (int j = 0; j<=col; j+=2)
            cout<<(dp[i][j][0]==-1 ? "X":to_string(dp[i][j][0]))<<" ";
        cout<<endl;
    }
    cout<<endl;
    for(int i= 0; i<= row; i+=2){
        for (int j = 0; j<=col; j+=2)
            cout<<(dp[i][j][1]==-1 ? "X":to_string(dp[i][j][1]))<<" ";
        cout<<endl;
    }
}