#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;
void print(v(v(int)) &arr);
void print(v(int)&arr);
void bfs(v(v(int))&grapph,int v);
void dfs(v(v(int))&graph, int u);
int pow(int x, unsigned int y, int p);

signed main(){
    cout<<"Hello Ritoman"<<endl;
    v(v(int))graph{{2,3},{1,4,5},{1,6,7},{2,8},{2,8},{3,8},{3,8},{4,5,6,7}};
    /* 
    bfs(graph,1);
    dfs(graph,1); */
    cout<<pow(-2,60,1000000007);
    return 0;
}

void bfs(v(v(int))&graph,int v){
    int n = graph.size();
    v(bool)vis(n,false);
    queue<int> q;
    vis[v-1] = true;
    q.push(v);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout<<u<<" ";
        for(int i: graph[u-1]){
            if(!vis[i-1]){
                q.push(i);
                vis[i-1] = true;
            }
        }
    }
    cout<<endl;
}

void dfs(v(v(int))&graph, int u){
    int  n  = graph.size();
    v(bool) vis(n, false);
    stack<int> st;
    st.push(u);
    while(!st.empty()){
        int u = st.top();
        st.pop();
        if(!vis[u-1]){
            vis[u-1] = true;
            cout<<u<<" ";
        }
        for(int i : graph[u-1])
            if(!vis[i-1])
                st.push(i);
    }
    cout<<endl;
}
int pow(int x, unsigned int y, int p){
    x = x%p;
    int res = 1;
    while(y>0){
        if(y%2==1)
            res = (res*(x%p))%p;
        y = y/2;
        x = (x*x)%p;
    }
    return res;
}