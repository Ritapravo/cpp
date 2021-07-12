#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "";
    string s1 ="abcd -> asd";
    int x = 0;
    while(s1[x]!=' '){
        s+= s1[x++];
    }

    cout<<s<<s;
}

//g++ "Untitled-1.cpp" && a
//g++ "F:\cpp\random\Untitled-1.cpp" && a 