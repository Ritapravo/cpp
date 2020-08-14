#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;
void print(v(v(int)) &arr);
void print(v(int)&arr);


int func(int temp[], int dist[], int x, int d, int n, unordered_map<int, int>&map){
    int xp = map[x];
    int a[n], b[n];
    for(int i = 0 ; i<n; i++){
        int p = map[temp[i]];
        a[i] = (d+p-xp)%d;
        b[i] = (d+xp-p)%d;
        cout<<a[i]<<" "<<b[i]<<endl;
    }
    int m = -1, pos=-1;
    for(int i = 0 ; i<n ; i++){
        int mp = min(a[i],b[i]);
        cout<<mp<<" "<<m<<" "<<pos<<endl;
        if(mp>=m){
            if(mp==m){
                if(b[i]<b[pos])
                    pos = i;
            }
            else
                pos = i;
            m = mp;
        }
    }
    return pos;
}

signed main(){
    cout<<"Hello Ritoman"<<endl;
    int temp[] = {0,1,2}, dist[]={0,1,2,3,4};
    int x = 3, d = 5, n = 3;
    unordered_map<int, int> map;
    for(int i = 0; i<d; i++)
        map[dist[i]] = i;
    cout<<func(temp, dist, x, d, n, map)<<endl;
    return 0;
}
