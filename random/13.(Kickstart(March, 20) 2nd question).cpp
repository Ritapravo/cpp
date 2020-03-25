//Kickstart(March, 20) 2nd question
//link-https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d40bb
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#define ll long long int
using namespace std;

int main(){
    ll test ;
    cin>>test;
    for(ll xi = 1; xi<=test; xi++){
        ll n, k, p; //n->no. of stacks, k->no. of plates in stack
        cin>>n>>k>>p;
        vector<vector<ll>> dp(n+1,vector<ll>(p+1,0));

        for(ll i = 0; i<n; i++){
            vector<ll> input(k);
            for(int j =0 ; j<k ; j++)
                cin>>input[j];
            ll pt = max(p,k);
            vector<ll> pref(pt+1,0);
            //pref stores the sum of popped elements from current stack
            for(ll j=1; j<=k; j++)
                pref[j] = pref[j-1]+input[j-1];

            //coming to the dp part
            for (ll j = 1; j<=p ; j++){
                ll m = 0;
                for (ll l = 0; l<=j ; l++){
                    m = max(m,dp[i][j-l]+pref[l]);
                    if(l==k)
                        break;
                }
                dp[i+1][j] = m;
            }
        }
        /*for(int i = 0; i<=n ; i++){
            for (int j =0 ; j<=p; j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        } */
            
        cout<<"case #"<<xi<<": "<<dp[n][p]<<endl;
    }
    return 0;
}