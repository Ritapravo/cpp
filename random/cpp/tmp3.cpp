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
    string s1, s2;
    cin>>s1>>s2;
    ll count = KMP(s2,s1);
    int n1 = s1.size();
    int n2 = s2.size();
    bool ind  = false;
    for(int i = 0; i<=n2-n1; i++)
    {
        string t = s2.substr(i, n1);
        int x1 = KMP(s1,t);
        int x2 = KMP(t,s1);
        //cout<<t<<endl;
        //cout<<x1<<" "<<x2<<endl;
        if(x1+x2==n1){
            ind = true;
            break;
        }
    }

    cout<<(ind?"true":"false")<<endl;
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
    ll prev = 0;
    ll l;
    vector<ll> pi = prefix(t);
    for(int i = 0; i<n; i++){
        l = prev;
        while(l>0 && s[i]!=t[l])
             l = pi[l-1];
        if(t[l]==s[i])
            l++;
        prev = l;
        
    }
    return l;
}