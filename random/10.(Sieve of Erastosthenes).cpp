//Sieve of Erastosthenes
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#define ll long long int
using namespace std;

vector<bool> sieve(ll n){
    vector<bool> primes (n+1, true);
    primes[0]=false;
    primes[1]=false;
    
    for(ll p = 2 ; p*p<=n ; p++)
        if(primes[p]==true)
            for(ll i = p*p; i<=n; i+=p)
                primes[i]=false;
    return primes;
}

int main(){
    cout<<"-1 for exit."<<endl;
    while(true){
        ll n ;
        cin>>n;
        if(n==-1)
            break;
        ll ans = sieve(n)[n];
        cout<<ans<<endl;
    }
}