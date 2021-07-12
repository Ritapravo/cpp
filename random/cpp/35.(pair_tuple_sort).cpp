//tuple sort / pair sort
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;

bool s2(pair<int,int> &a, pair<int,int> &b) 
{return a.second<b.second;} 

bool sortbysec( tuple<int, int, int>& a,   tuple<int, int, int>& b) 
{ 
    return get<1>(a) < get<1>(b); 
}

signed main(){
    cout<<"Hello Ritoman"<<endl;


    /* ----- tuple part----- */
    vector<tuple<int, int, int>> arr{{3,2,5},{1,1,3},{1,1,2},{2,2,0}};
    sort(arr.begin(), arr.end(), sortbysec);
    for(auto i: arr){
        cout<<get<0>(i)<<" "<<get<1>(i)<<" "<<get<2>(i)<<endl;
    }

    cout<<"\n\n";
    /* -----pair part----- */
    vector<pair<int, int>> arr2{{3,2},{1,1},{1,1},{2,2}};
    sort(arr2.begin(), arr2.end(), s2);
    for(auto i : arr2){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}