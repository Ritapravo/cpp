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


int MED(string &s1, string &s2,int n1, int n2 ){
    if(n1==0 || n2==0){
        dp[n1][n2] = n1 + n2;
        return dp[n1][n2];
    }
    if(dp[n1][n2]!=-1)
        return dp[n1][n2];
    if(s1[n1-1]==s2[n2-1]){
        dp[n1][n2] = MED(s1, s2, n1-1, n2-1);
        return dp[n1][n2];
    }
    else{
        dp[n1][n2] = 1 + min3(MED(s1, s2, n1-1, n2-1),MED(s1, s2, n1-1, n2),MED(s1, s2, n1, n2-1));
        return dp[n1][n2];
    }
}



signed main(){
    int t;
    cin>>t;
    while(t--){
        memset(dp, -1, sizeof(dp));
        string s1, s2;
        cin>>s1>>s2;
        int n1 = s1.size(), n2 = s2.size();
        int x = MED(s1,s2, n1, n2);
        cout<<x<<endl;
    }
    return 0;
}
