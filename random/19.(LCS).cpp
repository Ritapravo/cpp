//Longest common subsequence
#include<iostream>
#include<bits/stdc++.h>
#define v(x) vector<x>
#define int long long int
using namespace std;

void print(v(v(int)) &arr){
    cout<<"{";
    for(auto i = arr.begin(); i!=arr.end(); i++){
        cout<<"{";
        for(auto j =(*i).begin(); j!=(*i).end(); j++){
            cout<<*j;    
            if(j!=(*i).end()-1)
                cout<<",";
        }
        cout<<"}";
        if(i!=arr.end()-1)
                cout<<","<<endl<<" ";
    }cout<<"}"<<endl;
}

void subs(v(v(int))&dp, string &s1, string &s2, int row, int col, set<string>&s, string curr=""){
    if(row==0 || col ==0){
        s.insert(curr);
        return ;
    }
    if(s1[row-1]==s2[col-1]){
        curr = curr + s1[row-1];
        subs(dp, s1,s2, row-1, col-1, s, curr);
    }
    else{
        if(dp[row][col]==dp[row-1][col])
            subs(dp, s1, s2, row-1, col, s, curr);
        if(dp[row][col]==dp[row][col-1])
            subs(dp, s1, s2, row, col-1, s, curr );
    }
    return ;
}

void LCS(string &s1, string &s2){
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
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
    //print(dp);
    set<string> s;
    subs(dp, s1, s2, row, col, s);
    for(string str:s)
        cout<<str<<" ";
    cout<<endl;
}



signed main(){
    string s1, s2;
    cin>>s1>>s2;
    LCS(s1,s2);
}
