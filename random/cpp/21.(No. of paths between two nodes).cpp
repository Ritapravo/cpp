//count the number of paths between two nodes in a graph using backtracking
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;
void print(v(v(int)) &arr);
void print(v(int)&arr);
int count(v(v(int))&graph, int s, int d);


signed main(){
    v(v(int))graph{{1,2,3},{3},{0,1},{}};
    int s = 2, d = 3;
    int n = count(graph, s,d);
    cout<<n<<endl;
}


void countutil(v(v(int)) &graph, int u, int d, v(bool)vis, int &paths){
    vis[u] = true;
    if(u==d)
        paths ++;
    else{
        for(int i: graph[u]){
            if(!vis[i])
                countutil(graph, i, d, vis, paths);
        }
    }
    vis[u] = false;
}


int count(v(v(int))&graph, int s, int d){
    int n = graph.size();
    v(bool) vis(n, false);
    int paths  = 0;
    countutil(graph,s, d,vis,paths);
    return paths;
}
//g++ "first.cpp" && a
//g++ "F:\cpp\random\first.cpp" && a 