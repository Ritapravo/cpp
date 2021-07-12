#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;

void TOH (char x, char y, char z, int n){
    static int step = 1;
    if(n==1){
        cout<<"Step "<<step++<<". Move disk "<<n<<" from "<<x<<"-->"<<y<<endl;
    }
    else{
        TOH(x,z,y,n-1);
        cout<<"Step "<<step++<<". Move disk "<<n<<" from "<<x<<"-->"<<y<<endl;
        TOH(z,y,x,n-1);
    }
}

signed main(){
    int n;
    cin>>n;
    TOH('x','y','z',n);
}

//g++ "45.TOH.cpp" && a
//g++ "F:\cpp\random\45.TOH.cpp" && a 

/* 
    |   |   |
    |   |   |
    |   |   |
-----------------
    x   y   z
*/