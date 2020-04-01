//bfs and dfs using queue and stack
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;
void print(v(v(int)) &arr);
void print(v(int)&arr);
v(int) bfs(v(v(int))&graph, int v);
v(int) dfs(v(v(int))&graph, int v);


signed  main(){
    v(v(int)) graph1{{2,3},{1,4,5},{1,6,7},{2,8},{2,8},{3,8},{3,8},{4,5,6,7}};
    v(int) traversal1 = dfs1(graph1,1);
    v(int) traversal2 = bfs(graph1,2);
    print(traversal1);
    print(traversal2);
}









v(int) dfs(v(v(int))&graph, int v){
    int n  = graph.size();
    v(bool) visited(n, false);
    stack<int> st;
    v(int) traversal;
    st.push(v);
    while(!st.empty()){
        int u = st.top();
        st.pop();
        if(!visited[u-1]){
            visited[u-1] = true;
            traversal.push_back(u);
        }
        for(int i: graph[u-1]){
            if(!visited[i-1]){
                st.push(i);
            }
        }
    }
    return traversal;
    
}
v(int) bfs(v(v(int))&graph, int v){
    int n = graph.size();
    v(bool) visited(n,false);
    queue<int> q;
    v(int)traversal;
    q.push(v);
    visited[v-1]=true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        traversal.push_back(u);
        for(int i:graph[u-1]){
            if(!visited[i-1]){
                visited[i-1] = true;
                q.push(i);
            }
        }       
    }
    return traversal;
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
void print(v(int)&arr){
    cout<<"{";
    for(auto i=arr.begin(); i!=arr.end(); i++){
        cout<<*i;
        if(i!=arr.end()-1)
            cout<<",";
    }cout<<"}"<<endl;
}




v(int) dfs1(v(v(int))&graph, int v){
    int n  = graph.size();
    v(bool) visited(n, false);
    stack<int> st;
    v(int) traversal;
    int u = v;
    
    while(true){
        
        if(!visited[u-1]){
            visited[u-1] = true;
            traversal.push_back(u);
        }
        for(int i: graph[u-1]){
            if(!visited[i-1]){
                st.push(i);
            }
        }
        if(st.empty())
            return traversal;
        u = st.top();
        st.pop();
    }
}