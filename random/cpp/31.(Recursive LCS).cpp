//Longest common subsequence(recursive dp)
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;
void print(int row, int col);
void subs(string &s1, string &s2, int row, int col, set<string>&s, string curr="");
int dp[101][101];

int LCS(string s1, string s2, int n1, int n2){
    if(n1==0 || n2 ==0){
        dp[n1][n2] = 0;
        return dp[n1][n2];
    }
    if(dp[n1][n2]!=-1){
        return dp[n1][n2];
    }
    if(s1[n1-1]==s2[n2-1]){
        dp[n1][n2] = 1+LCS(s1,s2,n1-1,n2-1);
        return dp[n1][n2];
    }
    else{
        dp[n1][n2] = max(LCS(s1,s2,n1-1,n2),LCS(s1,s2,n1,n2-1));
        return dp[n1][n2];
    }
}


signed main(){
    memset(dp, -1, sizeof(dp));
    string s1 = "abcdef", s2 = "acbdfe";
    int n1 = s1.size(), n2 = s2.size();
    cout<<LCS(s1, s2, n1, n2)<<endl;
    print(n1,n2);
    
    
    set<string> s;
    subs( s1, s2, n1, n2, s);
    for(string str:s)
        cout<<str<<" ";
    cout<<endl;
    return 0;
}

void subs(string &s1, string &s2, int row, int col, set<string>&s, string curr){
    if(row==0 || col ==0){
        reverse(curr.begin(), curr.end());
        s.insert(curr);
        return ;
    }
    if(s1[row-1]==s2[col-1]){
        curr = curr + s1[row-1];
        subs(s1,s2, row-1, col-1, s, curr);
    }
    else{
        if(dp[row][col]==dp[row-1][col])
            subs(s1, s2, row-1, col, s, curr);
        if(dp[row][col]==dp[row][col-1])
            subs(s1, s2, row, col-1, s, curr );
    }
    return ;
}

void print(int row, int col){
    for(int i = 0; i<=row; i++){
        for(int j = 0; j<=col; j++){
            cout<<(dp[i][j]==-1 ? "X":to_string(dp[i][j]))<<" ";
        }
        cout<<endl;
    }
}