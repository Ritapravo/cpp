//Minimum edit distance(iterative)

#include<iostream>
#include<bits/stdc++.h>
#define v(x) vector<x>
#define int long long int
using namespace std;

int min3(int a, int b, int c){
    int m = min(a,b);
    m = min(m,c);
    return m;
}


int MED(string &s1, string &s2){
    int row = s1.size(), col = s2.size();
    v(v(int)) dp(row+1, v(int)(col+1));
    
    for(int i = 0 ; i<=row; i++){
        for(int j = 0; j<=col; j++){
            if(i==0 || j==0)
                dp[i][j] = i+j;
            else
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = dp[i-1][j-1];  
                else
                    dp[i][j] = 1+min3(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
        }
    }
    return dp[row][col];
}



signed main(){
    int t;
    cin>>t;
    while(t--){
        string s1, s2;
        cin>>s1>>s2;
        int x = MED(s1,s2);
        cout<<x<<endl;
    }
    return 0;
}
