//Finding all paths between two nodes in a graph using backtracking
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;
void print(v(v(int)) &arr);
void print(v(int)&arr);
v(v(int)) findpath(v(v(int))&graph, int s, int d);



signed main(){
    v(v(int))graph{{1,2,3},{3},{0,1},{}};
    int s = 2, d = 3;
    v(v(int))paths = findpath(graph, s,d);
    print(paths);
}

void findutil(v(v(int)) &graph, int u, int d, v(bool)vis, v(v(int)) &path, v(int)curr = {}){
    vis[u] = true;
    curr.push_back(u);
    if(u==d)
        path.push_back(curr);
    else{
        for(int i: graph[u]){
            if(!vis[i])
                findutil(graph, i, d, vis, path, curr);
        }
    }
    vis[u] = false;
}


v(v(int)) findpath(v(v(int))&graph, int s, int d){
    int n = graph.size();
    v(bool) vis(n, false);
    v(v(int)) path;
    int paths  = 0;
    findutil(graph,s, d,vis,path);
    //print(path);
    return path;
}

//g++ "first.cpp" && a
//g++ "F:\cpp\random\first.cpp" && a 



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