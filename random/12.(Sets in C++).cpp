//Sets in C++
//Functions - find(return an iterator), insert, erase
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    //unordered set declaration
    unordered_set <ll> see{2,5,5,3,6,2,1};
    //converting a vector to a set
    vector<ll> alpha{5,6,2,2,3,6,1,9,10,6};
    //removing duplicates from vector
    unordered_set<ll> alpset(alpha.begin(), alpha.end());
    alpha=vector<ll>(alpset.begin(), alpset.end());
    cout<<"after removing duplicates from the vector alpha"<<endl;
    for(ll i : alpha)
        cout<<i<<" ";
    cout<<endl;
    alpset.insert(15);
    alpset.erase(1);
    cout<<"printing the sets after insert(15) and erase(1) operations"<<endl;
    for(ll i : alpset)
        cout<<i<<" ";
    cout<<endl;
    cout<<*alpset.find(6)<<" "<<*alpset.find(1);
}
//set contains only distinct elements