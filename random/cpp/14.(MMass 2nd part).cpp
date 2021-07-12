//g++ "14.(MMass 2nd part).cpp" && a
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool isnumber(string s);
ll dsearch(string s);
ll mmass(vector<string> elem);
vector<string> conv(string s);

int main(){
    
    string s;
    cin>>s;
    vector<string> elem = conv(s);
    cout<<mmass(elem)<<endl;
    
}

bool isnumber(string s){
    for(char i: s){
        if(!isdigit(i)){
            return false;
        }
    }return true;
}

ll mmass(vector<string> elem){
    stack<ll> st;
    for (string i: elem){
        if(i=="(")
            st.push(-1);
        else if(dsearch(i)!=-1)
            st.push(dsearch(i));

        else if(isnumber(i)){
            ll x = stoll(i);
            ll y = st.top();
            st.pop();
            st.push(x*y);
            //cout<<y<<endl;
        }
        else if(i==")"){
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

vector<string> conv(string s){
    int n  = s.length();
    s = s + "#";
    vector<string> elem;
    int i = 0;
    while(i<n){
        string num = "";
        while(isdigit(s[i])){
            num = num+s[i];
            i = i+1;
        }
        if(num!="")
            elem.push_back(num);

        if(s[i]=='(' || s[i]==')'){
            string tmp ="";
            tmp = tmp + s[i];
            elem.push_back(tmp);
            i = i+1;
        }    
        else if(s[i]>='A' && s[i]<='Z'){
            if(s[i+1]>='a' && s[i+1]<='z'){
                string tmp="";
                tmp = tmp+ s[i]+s[i+1];
                elem.push_back(tmp);
                i = i+2;
            }
            else{
                string tmp ="";
                tmp = tmp+s[i];
                elem.push_back(tmp);
                i = i+1;
            }
               
        }   
    }
    return elem;
}


ll dsearch(string s){
    unordered_map<string,ll> elements;
    elements["H"]=1;
    elements["He"]=4;
    elements["Li"]=7;
    elements["Be"]=9;
    elements["B"]=11;
    elements["C"]=12;
    elements["N"]=14;
    elements["O"]=16;
    elements["F"]=19;
    elements["Ne"]=20;
    elements["Na"]=23;
    elements["Mg"]=24;
    elements["Al"]=27;
    elements["Si"]=28;
    elements["P"]=31;
    elements["S"]=32;
    elements["Cl"]=35;
    elements["Ar"]=40;
    elements["K"]=40;
    elements["Ca"]=40;
    elements["Sc"]=45;
    elements["Ti"]=48;
    elements["V"]=51;
    elements["Cr"]=52;
    elements["Mn"]=55;
    elements["Fe"]=56;
    elements["Co"]=58;
    elements["Ni"]=58;
    elements["Cu"]=64;
    elements["Zn"]=65;
    elements["Ga"]=70;
    elements["Ge"]=73;
    elements["As"]=75;
    elements["Se"]=79;
    elements["Br"]=80;
    elements["Kr"]=84;
    elements["Rb"]=85;
    elements["Sr"]=88;
    elements["Y"]=89;
    elements["Zr"]=91;
    elements["Nb"]=93;
    elements["Mo"]=96;
    elements["Tc"]=98;
    elements["Ru"]=101;
    elements["Rh"]=103;
    elements["Pd"]=106;
    elements["Ag"]=108;
    elements["Cd"]=112;
    elements["In"]=115;
    elements["Sn"]=119;
    elements["Sb"]=122;
    elements["Te"]=128;
    elements["I"]=127;
    elements["Xe"]=131;
    elements["Cs"]=133;
    elements["Ba"]=137;
    elements["La"]=137;
    elements["Ce"]=140;
    elements["Pr"]=141;
    elements["Nd"]=144;
    elements["Pm"]=145;
    elements["Sm"]=150;
    elements["Eu"]=152;
    elements["Gd"]=157;
    elements["Tb"]=159;
    elements["Dy"]=163;
    elements["Ho"]=165;
    elements["Er"]=167;
    elements["Tm"]=169;
    elements["Yb"]=173;
    elements["Lu"]=175;
    elements["Hf"]=178;
    elements["Ta"]=181;
    elements["W"]=184;
    elements["Re"]=186;
    elements["Os"]=190;
    elements["Ir"]=192;
    elements["Pt"]=195;
    elements["Au"]=197;
    elements["Hg"]=201;
    elements["Tl"]=204;
    elements["Pb"]=207;
    elements["Bi"]=209;
    elements["Po"]=209;
    elements["At"]=210;
    elements["Rn"]=222;
    elements["Fr"]=223;
    elements["Ra"]=226;
    elements["Ac"]=227;
    elements["Th"]=232;
    elements["Pa"]=231;
    elements["U"]=238;

    if(elements.find(s)==elements.end())
        return -1;
    else
        return elements[s];   
}