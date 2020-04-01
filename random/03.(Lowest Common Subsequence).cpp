//Lowest Common Subsequence in C++
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#define maxv(a) *max_element(a.begin(), a.end())
#define maxa(a) *max_element(a, a+(sizeof(a) / sizeof(a[0])))
#define ll long long int
#define len(a) sizeof(a)/sizeof(a[0])
#define f(i,a,b) for(ll i=a; i<=b; i++)
#define g(i,a,b) for(ll i=a; i>=b; i--)
#define append push_back

using namespace std;
set<string> printLCS(vector<vector<ll>> arr, string s1, string s2, ll n1, ll n2, string c="");


int main(){
    cout<<"Ritoman's C++ code."<<endl;
    string s1 = "abcdef";
    string s2 = "abdcf";
    ll n1 = s1.length();
    ll n2 = s2.length();
    reverse(s1.begin(), s1.end()); 
    reverse(s2.begin(), s2.end()); 
    vector<vector<ll>> arr(n1+1, vector<ll>(n2+1,0));

    f(i,0,n1){
        f(j,0,n2){
            if(i==0 || j== 0 )
                arr[i][j] = 0 ;
            else if(s1[i-1]==s2[j-1])
                arr[i][j] = arr[i-1][j-1]+1;
            else
                arr[i][j] = max(arr[i][j-1], arr[i-1][j]);
        }
    }
    f(i,0,n1){
        f(j,0,n2)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    cout<<arr[n1][n2]<<endl;

    //string c = "";
    set<string> s = printLCS(arr, s1, s2, n1, n2);
    for(string st: s)
        cout<<st<<endl;

    return 0;
}



set<string> printLCS(vector<vector<ll>> arr, string s1, string s2, ll n1, ll n2, string c){
    static set<string> s={};   
    if(n1==0 || n2==0){
        s.insert(c);
        return  s;
    }
    if(s1[n1-1]==s2[n2-1]){
        c = c + s1[n1-1];
        printLCS(arr, s1, s2, n1-1, n2-1, c);
    }
    else{
        if(arr[n1][n2]==arr[n1-1][n2])
            printLCS(arr, s1, s2, n1-1, n2, c);
        if(arr[n1][n2]==arr[n1][n2-1])
            printLCS(arr, s1, s2, n1, n2-1, c);
    }
    return s;
}