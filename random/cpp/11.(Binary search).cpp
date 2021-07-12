//Binary search
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#define ll long long int
#define f(i,a,b) for(ll i=a;i<=b;i++)
using namespace std;
ll binarysearch(vector<ll> arr, ll x, ll l, ll r);

int main(){
    vector<ll>arr{1,2,4,4,6,9,10,10,10,12,13};
    ll x;
    cin>>x;
    cout<<binarysearch(arr,x,0,arr.size()-1)<<endl;
}
ll binarysearch(vector<ll> arr, ll x, ll l,ll r){
    if(l<=r){
        ll mid = l + (r-l)/2;
        if(x==arr[mid])
            return mid;
        if(x>arr[mid])
            return binarysearch(arr, x, mid+1, r);
        else 
            return binarysearch(arr, x, l, mid-1);
    }
    return -1;
}