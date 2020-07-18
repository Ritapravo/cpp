#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;
void print(v(v(int)) &arr);
void print(v(int)&arr);


signed main(){
    int n;
    cin>>n;
    string s1, s2;
    cin>>s1>>s2;
    int j = 0, tmp;
    for(int i = 0; i<n; i++){
        int x = 0;
        while(x<n){
            if(s1[i]==s2[(j+x)%n]){
                j++;
                break;
            }
            else
                j++;
            x++;
        }
        if()
    }

}
