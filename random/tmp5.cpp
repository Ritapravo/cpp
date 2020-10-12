

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;


signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0; i<n; i++){
            cin>>arr[i];
        }
        int r3 = (arr[0]/arr[n-1])*n;
        cout<<r3<<endl;
    }
    return 0;
}

//g++ "tmp5.cpp" && a
//g++ "F:\cpp\random\tmp5.cpp" && a 