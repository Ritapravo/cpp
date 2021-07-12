//Longest repeating subsequence
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;
int dp[101][101];

void print(int row, int col){
    for(int i =0; i<=row; i++){
        for (int j =0; j<=col; j++)
            cout<<(dp[i][j]==-1? "X":to_string(dp[i][j]))<<" ";
        cout<<endl;
    }
}


int LRS(string s, int n1, int n2){
    if(n1 == 0 || n2 == 0){
        dp[n1][n2] = 0;
        return 0;
    }
    if(dp[n1][n2]!=-1){
        return dp[n1][n2];
    }
    if(n1!=n2 && s[n1-1]==s[n2-1]){
        dp[n1][n2] = 1 + LRS(s, n1-1, n2 -1);
        return dp[n1][n2];
    }
    else{
        dp[n1][n2] = max(LRS(s, n1-1, n2), LRS(s, n1, n2-1));
        return dp[n1][n2];
    }
    
}

void findLRS(string s, int n1, int n2, set<string> &ans, string curr = ""){
    if(n1==0 || n2 ==0){
        reverse(curr.begin(), curr.end());
        ans.insert(curr);
        return;
    }
    if(n1 != n2 && s[n1-1]==s[n2-1]){
        findLRS(s, n1-1, n2-1, ans, curr + s[n1-1]);
    }
    else{
        if(dp[n1][n2]==dp[n1-1][n2]){
            findLRS(s, n1-1, n2, ans, curr);
        }
        if(dp[n1][n2]==dp[n1][n2-1]){
            findLRS(s, n1, n2-1, ans, curr);
        }
    }
}



signed main(){
    cout<<"Hello Ritoman"<<endl;
    memset(dp,-1, sizeof(dp));
    string s = "aabcbddc";
    int n  = s.size();
    cout<<LRS(s,n,n)<<endl;
    print(n,n);

    set<string> ans;
    findLRS(s, n, n, ans);
    for(string str: ans)
        cout<<str<<" ";
    cout<<endl;
    return 0;
}
