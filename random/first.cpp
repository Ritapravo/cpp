//Minimum edit distance(recursive)

#include<iostream>
#include<bits/stdc++.h>
#define v(x) vector<x>
#define int long long int
using namespace std;
int dp[2001][2001];

int min3(int a, int b, int c){
    int m = min(a,b);
    m = min(m,c);
    return m;
}


int LCS(string &s1, string &s2, int n1, int n2){
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
int lcs(string &s1, string &s2){
    int row = s1.size(), col = s2.size();
    v(v(int)) dp(row+1, v(int)(col+1,0));
    
    for(int i = 1 ; i<=row; i++){
        for(int j = 1; j<=col; j++){
            if(s1[i-1]==s2[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[row][col];
}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        memset(dp, -1, sizeof(dp));
        string s1, s2;
        cin>>s1>>s2;
        int n1 = s1.size(), n2 = s2.size();
        int y = max(n1,n2);
        //int x = LCS(s1,s2, n1, n2);
        int x = lcs(s1, s2);
        cout<<x<<endl;
    }
    return 0;
}
