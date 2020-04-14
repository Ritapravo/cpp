#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;

bool check(int n){
    for (int x=2; x<=sqrt(n); x++) { 
        float f = log(n) / log(x); 
        if ((f - (int)f) == 0.0)  
            return true;         
    }
    return false;
}
int factors(int n, v(bool)&chk){
    unordered_set<int> s;
    int res = 1;
    for(int i =1; i<=(int)sqrt(n);i++){
        if(n%i == 0 ){
            s.insert(i);
            s.insert(n/i);
        }
    }
    for (int i : s){
        if(chk[i])
            res += i;
    }
    return res;
}

signed main(){
    
    int t;
    cin>>t;
    int N = 100;
    v(bool) chk(N+1);
    for(int i = 1; i<=N; i++)
        chk[i] = check(i);
    v(int)dp(N + 1);
    dp[1] = 1;
    for(int i = 2;i<=N; i++)
        dp[i] = dp[i-1]+factors(i, chk);

    while(t--){
        int n;
        cin>>n;
        for(int i = 1; i<=n; i++)
            cout<<i<<"->"<<dp[i]<<endl;
    }
}