//g++ "xyz.cpp" && a
//g++ "F:\cpp\random\xyz.cpp" && a 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    string s;
    vector<int> v;
    int count = 0;
    while(cin>>s){
        if(s[0]>=48 && s[0]<=57)
            v.push_back(stoi(s));
    }
    for (int c: v)
        cout<<c<<endl;
    return 0;
}

//g++ "xyz.cpp" && a
//g++ "F:\cpp\random\cpp\xyz.cpp" && a 