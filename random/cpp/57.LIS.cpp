#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;


signed main(){
    cout<<"Hello Ritoman"<<endl;
    v(int)A = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int n  = A.size();
    int dp[n] ;
    for(int i =0; i<n; i++)dp[i] = 1;
    for(int i =1; i<n; i++){
        for(int j=0; j<i; j++){
            if(dp[j]+1>dp[i] && A[j]<A[i])
                dp[i] = dp[j] + 1;
        }
    }
    
    int ans = 0;
    for (int i = 0; i<n; i++)
        if(dp[i]>ans)ans = dp[i];
    cout<<ans<<endl;
    return 0;
}