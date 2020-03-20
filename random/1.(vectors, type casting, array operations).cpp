//vectors, type casting, array operations
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#define maxv(a) *max_element(a.begin(), a.end())
#define maxa(a) *max_element(a, a+(sizeof(a) / sizeof(a[0])))
#define ll long long int
#define f(i,a,b) for(ll i=a; i<=b; i++)
#define g(i,a,b) for(ll i=a; i>=b; i--)
#define append push_back

using namespace std;

ll pow(ll n, ll k, ll p=1000000007){
    ll res = 1;
    n = n%p;
    while(n>0){
        if(k%2==1){
            k--;
            res = (res*n)%p;
        }
        else{
            k = k/2;
            n = (n*n)%p;
        }
    }
    return res;
}


int main(){
    cout<<"Ritoman's first C++ code."<<endl;
    vector<ll> arr = {5,3,9,6,8,1,6,5,6};
    /* while(true){
        ll a ;
        cin>>a;
        if(a==-1)
            break;
        arr.append(a);
    } */
    
    f(i,0,arr.size()-1)
        cout<<arr[i]<<" ";
    cout<<endl;
    sort(arr.begin(), arr.begin()+4);
    //std::partial_sort(arr.begin(),arr.begin()+3,arr.end());
    f(i,0,arr.size()-1)
        cout<<arr[i]<<" ";
    cout<<endl;
    ll a[] = {5,9,4,2};
    //cout << *max_element(b.begin(), b.end()); 
    cout<< maxa(a)<<endl;
    string s = "1111";
    char c = '1';
    c = c-'0';
    cout<<c+1<<endl;
    ll p = 12345678;
    ll x = stoll(s);
    //ll s = (ll)s;
    cout<<x+3<<endl;
    string y = to_string(x);
    cout<<y+'b'<<endl;
    float ab = 13.002;
    ll ai = (ll)ab;
    cout<<ai<<endl;
    cout<<pow(2,3)<<endl;
    return 0;
}