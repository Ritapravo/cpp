//finding a single path betwwen two nodes in a graph
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;
void print(v(v(int)) &arr);
void print(v(int)&arr);

void fpath(v(v(int))&graph, int u, int d, v(bool)vis, v(int)&path,  v(int)curr = {});


signed main(){
    cout<<"Hello Ritoman"<<endl;
    v(v(int))graph{{1,2,3},{3},{0,1},{}};
    int s =2, d = 3;
    v(int) path = {};
    fpath(graph,s, d,v(bool)(graph.size(),false), path);
    print(path);
    return 0;
}


void fpath(v(v(int)) &graph, int u, int d, v(bool)vis, v(int)&path, v(int)curr){
    vis[u] = true;
    curr.push_back(u);
    if(u==d){
        path = curr;
        return;
    }
    else{
        for(int i: graph[u]){
            if(!vis[i])
                fpath(graph, i, d, vis, path, curr);
        }
    }
    vis[u] = false;
    return ;
}








void print(v(int)&arr){
    cout<<"{";
    for(auto i=arr.begin(); i!=arr.end(); i++){
        cout<<*i;
        if(i!=arr.end()-1)
            cout<<",";
    }cout<<"}"<<endl;
}
void print(v(v(int)) &arr){
    cout<<"{";
    for(auto i = arr.begin(); i!=arr.end(); i++){
        cout<<"{";
        for(auto j =(*i).begin(); j!=(*i).end(); j++){
            cout<<*j;
            if(j!=(*i).end()-1)
                cout<<",";
        }
        cout<<"}";
        if(i!=arr.end()-1)
                cout<<",";
    }cout<<"}"<<endl;
}