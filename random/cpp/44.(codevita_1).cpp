#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;
void print(v(v(int)) &arr);
void print(v(int)&arr);

string bin(int n){
    string s = "";
    while(n>0){
        s += to_string(n%2);
        n = n/2;
    }
    reverse(s.begin(), s.end()); 
    return s;
}

signed main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)cin>>arr[i];
    int ma = arr[0];
    for(int i=1; i<n; i++)
        if(arr[i]>ma)
            ma = arr[i];
    int m = bin(ma).size();

    //cout<<m<<" "<<ma<<endl;

    int arr2[n];
    for(int i = 0; i<n; i++){
        int cnt = 0;
        string s = bin(arr[i]);
        for (char c: s)
            if(c=='1')
                cnt += 1;
        arr2[i] = cnt;
    }
    int res = 0;
    for(int i = 0; i<1<<n; i++){
        int ones = 0, zero = 0;
        for(int j = 0; j<n; j++){
            if((i>>j)&1){
                ones += arr2[j];
                zero += m - arr2[j];
            }
        }
        if(ones==zero && ones!=0)
            res++;
    }
    string r = bin(res);
    int x = r.size();
    string ans = "";
    if(x>m){
        ans = r.substr(x-m,m);
    }
    else{
        for(int i = 0; i<m-x; i++){ans += "0";}
        ans += r;
    }
    cout<<ans<<endl;
    return 0;
}

//g++ "44.(codevita_1).cpp" && a
//g++ "F:\cpp\random\44.(codevita_1).cpp" && a 