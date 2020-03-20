//factorial of very large numbers
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#define ll long long int
#define f(i,a,b) for(ll i=a; i<=b; i++)
#define g(i,a,b) for(ll i=a; i>=b; i--)
#define append push_back

using namespace std;

string sadd(string s1, string s2);
string smul(string s1, string s2);
string fact(ll n);

int main(){
    cout<<"Ritoman is learning C++."<<endl;
    while(true){
        ll n;
        cin>>n;
        if (n==-1)
            break;
        cout<<fact(n)<<endl;
    }
    return 0;
}

string sadd(string s1, string s2){
    ll n1 = s1.length();
    ll n2 = s2.length();

    string res = "";
    ll c = 0;
    while(n1>0 && n2 >0) {
        n1--;
        n2--;
        ll x = s1[n1] - '0';
        ll y = s2[n2] - '0'; 
        res = res + to_string((x + y + c)%10);
        c = (x + y + c)/10;
    }
    while(n1>0){
        n1--;
        ll x = s1[n1] - '0';
        res = res + to_string((x + c)%10);
        c = (x + c)/10;
    }
    while(n2>0){
        n2--;
        ll y = s2[n2] - '0';
        res = res + to_string((y + c)%10);
        c = (y + c)/10;
    }
    if (c!=0)
        res = res+to_string(c);
    reverse(res.begin(), res.end());
    ll ch = res.length()-1;

    for(ll i = 0 ; i < res.length()-1; i++){
        if(res[i]!='0'){
            ch = i;
            break;
        }
    }
    return res.substr(ch, res.length()-ch);  
}
string smul(string s1, string s2){
    ll n1 = s1.length();
    ll n2 = s2.length();
    string res = "0";
    ll k = 0;
    for(ll i = n1-1; i>=0 ; i--){
        string m = "";
        ll l = k;
        while(l--)
            m = m + '0';
        k ++;
        ll c = 0;
        for(ll j = n2-1; j>=0; j--){
            ll x = s1[i] - '0';
            ll y = s2[j] - '0'; 
            m = m + to_string((x*y + c)%10);
            c = (x*y + c)/10;
        }
        if(c!=0)
            m = m + to_string(c);
        reverse(m.begin(),m.end());
        //cout<<m<<endl;
        res = sadd(res,m);
    }
    return res;
}
string fact(ll n){
    string res = "1";
    for(ll i = 1; i<=n; i++){
        string s = to_string(i);
        res = smul(res,s);
    }
    return res;
}