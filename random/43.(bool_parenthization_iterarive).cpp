//https://www.interviewbit.com/problems/evaluate-expression-to-true/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int m = 1003;

class Solution {
  public:
    int cnttrue(string s);
};

int Solution::cnttrue(string s) {
    int n = s.size();
    int dp[n/2 +1][n/2 +1][2];
    memset(dp,0,sizeof(dp));
    
    for(int x=0; x<n; x+=2){
        int i = 0;
        for(int j = x; j<n; j+=2){
            if(i==j){
                dp[i/2][j/2][0] = s[i]=='F';
                dp[i/2][j/2][1] = s[i]=='T';
            }
            else{
                int ans0 = 0, ans1 = 0;
                for(int k = i+1; k<j; k+=2){
                    int lt = dp[i/2][(k-1)/2][1];
                    int lf = dp[i/2][(k-1)/2][0];
                    int rt = dp[(k+1)/2][j/2][1];
                    int rf = dp[(k+1)/2][j/2][0];
                    
                    if(s[k]=='&'){
                        ans1 += lt*rt;
                        ans0 += lf*rf + lt*rf + lf*rt;
                    }
                    else if(s[k]=='^'){
                        ans1 += lt*rf + lf*rt;
                        ans0 += lf*rf + lt*rt;
                    }
                    else if(s[k]=='|'){
                        ans1 += lt*rf + lf*rt + lt*rt ;
                        ans0 += lf*rf ;
                    }
                }
                dp[i/2][j/2][0] = ans0%m;
                dp[i/2][j/2][1] = ans1%m;
            }
            i += 2;
        }
    }
    return dp[0][n/2][1]%m;
}

int main(){
    //cout<<"Hello Ritoman"<<endl;
    Solution Sol;
    cout<<Sol.cnttrue("F&F&T^T")<<endl;
    return 0;
}