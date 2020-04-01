//finding molecular mass of chemical
//spoj question MMASS
#include<iostream>
#include<vector>
#include <bits/stdc++.h> 
#define ll long long int
using namespace std;
ll mmass(string s){
    stack<int> st;
    for (char i: s){
        if(i=='(')
            st.push(-1);
        else if(i=='H')
            st.push(1);
        else if(i=='C')
            st.push(12);
        else if(i=='O')
            st.push(16);
        else if(i>='0' && i<='9'){
            int x = i-'0';
            int y = st.top();
            st.pop();
            st.push(x*y);
            //cout<<y<<endl;
        }
        else if(i==')'){
            ll tmp = 0;
            while(st.top()!=-1){
                tmp += st.top();
                st.pop();
            }
            st.pop();
            //cout<<tmp<<endl;
            st.push(tmp);
        }
    }
    ll tot = 0;
    while(!st.empty()){
        tot += st.top();
        //cout<<st.top()<<" ";
        st.pop();
    }
    return tot;
}
int main(){
    cout<<"MASS.IN"<<endl;
    string s;
    cin>>s;
    cout<<"MASS.OUT"<<endl;
    ll tot = mmass(s);
    //cout<<endl;
    cout<<tot<<endl;  
    return 0;
}
/* 
#include<cstdio>
#include<iostream>
#include<stack>
#include<string>

using namespace std;

int findMass(string s){
    stack<int> st;
    for(int i=0;i<s.length();i++){
        if(s[i] == '(')
            st.push(-1);
        if(s[i] == 'C')
            st.push(12);
        if(s[i] == 'H')
            st.push(1);
        if(s[i] == 'O')
            st.push(16);
        if(s[i] >= '2' && s[i] <= '9'){
            int n = st.top();
            st.pop();
            st.push(n * (s[i] - '0'));
        }
        if(s[i] == ')'){
            int total = 0;
            while(st.top() != -1){
                total += st.top();
                st.pop();
            }
            st.pop();
            st.push(total);
        }
    }
    int res = 0;
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    return res;
}

int main(){
    cout<<"MASS.IN"<<endl;
    string s;
    cin >> s;
    cout<<"MASS.OUT"<<endl;
    cout << findMass(s);
    return 0;
} */