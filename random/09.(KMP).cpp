//KMP algorithm including the prefix function
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#define ll long long int
using namespace std;

vector<ll>prefix(string s);
ll KMP (string s, string t);

int main(){
    //cout<<"Enter master string and then the key string."<<endl; 
    string s, t;
    cin>>s>>t;
    ll count = KMP(s,t);
    cout<<count<<endl;
    return 0;
}
vector<ll> prefix(string s){
    ll n = s.length();
    vector<ll> p(n);
    p[0] = 0;
    for(ll i = 1; i<n; i++){
        ll l = p[i-1];
        while(l>0 && s[i]!=s[l])
            l = p[l-1];
        if(s[i]==s[l])
            l++;
        p[i] = l;
    }
    return p;
}
ll KMP (string s, string t){
    ll n = s.length();
    ll m = t.length();
    ll count = 0;
    ll prev = 0;
    vector<ll> pi = prefix(t);
    for(int i = 0; i<n; i++){
        ll l = prev;
        while(l>0 && s[i]!=t[l])
             l = pi[l-1];
        if(t[l]==s[i])
            l++;
        prev = l;
        if(l==m){
            count++;
            //cout<<i-m+1<<endl;
            //prints the starting indices of the  
            //string where the match is found
        }
    }
    return count;
}

//g++ "09.(KMP).cpp" && a
//g++ "F:\cpp\random\09.(KMP).cpp" && a 