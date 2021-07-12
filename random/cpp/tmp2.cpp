#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;
void print(v(v(int)) &arr);
void print(v(int)&arr);


signed main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int n1 = s1.size();
    int n2 = s2.size();
    int f1[26] = {0};
    int f2[26] = {0};
    for(int i = 0; i<n1-1; i++){
        f1[s1[i]-'a']++;
    }
    for(int i = 0; i<n2-1; i++){
        f2[s2[i]-'a']++;
    }
    int max1=0, min1 = 9999999999;
    int max2=0, min2 = 9999999999;
    for(int i = 0; i<26; i++){
        if(f1[i]>max1)max1 = f1[i];
        if(f2[i]>max2)max2 = f2[i];

        if(f2[i]<min2)min2 = f2[i];
        if(f1[i]<min1)min1 = f1[i];

        cout<<f1[i]<<" ";
    }
    cout<<endl;
    cout<<max1<<" "<<min1<<endl;
    cout<<max2<<" "<<min2<<endl;

    int x1 = max1-min1;
    int x2 = max2-min2;

    string p1 = "", p2 = "";

    if(s1[n1-1]=='n')p1+="North";
    else if(s1[n1-1]=='s')p1+="South";
    else if(s1[n1-1]=='e')p1+="East";
    else if(s1[n1-1]=='w')p1+="West";

    if(s2[n2-1]=='n')p2+="North";
    else if(s2[n2-1]=='s')p2+="South";
    else if(s2[n2-1]=='e')p2+="East";
    else if(s2[n2-1]=='w')p2+="West";

    cout<<x1<<" "<<p1<<" "<<x2<<" "<<p2<<endl;


    return 0;
}


//g++ "tmp2.cpp" && a
//g++ "F:\cpp\random\tmp2.cpp" && a 