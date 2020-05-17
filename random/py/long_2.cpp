#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;
void print(v(v(int)) &arr);
void print(v(int)&arr);


signed main(){
    int t;
    cin>>t;
    while(t--){
        int n, q ;
        cin>>n>>q;
        string s;
        cin>>s;
        int arr[26] = {0};
        for(char c: s)
            arr[c-'a']++;
        /* for(int i =0; i<26; i++)cout<<arr[i]<<" ";
        cout<<endl; */
        while(q--){
            int x;
            cin>>x;
            int ans = 0 ;
            for(int i =0 ; i<26; i++){
                ans += max((int)0, arr[i]-x);
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
