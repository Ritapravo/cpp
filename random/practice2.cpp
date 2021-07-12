#include<iostream>
#include<bits/stdc++.h>
#define int long long int
using namespace std;


signed main(){
    int s = 0, f = 1;
    for(int i = 1; i<10; i++){
        f = f*i;
        s += f*f*(i+1);
    }
    cout<<s<<endl;
}