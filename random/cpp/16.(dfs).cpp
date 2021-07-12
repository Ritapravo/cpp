#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;
void print(v(v(int)) &arr);
void print(v(int)&arr);

v(int) dfs1(v(v(int)) &graph, int v, v(bool) *vis,v(int)* traversal );
v(v(int)) dft(v(v(int)) &graph);
v(int) dfs(v(v(int)) &graph, int v);//not recommended for test cases




signed
 main(){
    v(v(int)) graph1,graph2;
    graph1 = {{2,3},{1,4,5},{1,6,7},{2,8},{2,8},{3,8},{3,8},{4,5,6,7}};
    graph2 = {{},{4,5},{6,7},{2},{2},{3},{3},{}};
    
    v(v(int)) components = dft(graph2);
    print(components);
    v(int) df1 = dfs(graph1, 1);
    for(int i: df1)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
v(int) dfs(v(v(int)) &graph, int v){
    static v(int) traversal;
    static v(bool) vis((graph).size(), false);
    vis[v-1] = true;
    traversal.push_back(v);
    for (int i: (graph)[v-1]){
        if(not vis[i-1]){
            dfs(graph,i);
        }
    }
    return traversal;
}
v(int) dfs1(v(v(int)) &graph, int v, v(bool) &vis,v(int) &traversal ){
    vis[v-1] = true;
    traversal.push_back(v);
    for (int i: (graph)[v-1]){
        if(not vis[i-1]){
            dfs1(graph,i,vis,traversal);
        }
    }
    return traversal;
}
v(v(int)) dft(v(v(int)) &graph){
    int n = (graph).size();
    v(bool) visited(n, false);
    v(v(int)) components;
    for (int i = 1; i<=n; i++){
        if(!visited[i-1]){
            v(int) traversal;
            components.push_back(dfs1(graph,i,visited,traversal));
        }
    }
    return components;
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