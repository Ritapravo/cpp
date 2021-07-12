#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#define v(x) vector<x>
#define ll long long int

using namespace std;
void print(v(int)&arr);
v(v(int)) makegraph();
v(int) bfs(v(v(int))&graph, int v);

int main(){
    cout<<"Ritoman's bfs code."<<endl;
    int s;
    cout<<"Enter the source node: ";
    cin>>s;
    v(v(int)) graph = makegraph();
    v(int) bfs_search = bfs(graph,s);
    cout<<"BFS path: ";
    print(bfs_search);
    return 0;
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

v(v(int)) makegraph(){
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    v(v(int)) graph(n,vector<int>());
    cout<<"Enter the Adjacency matrix: "<<endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j < n ; j++){
            int tmp;
            cin>>tmp;
            if(tmp==1)
                graph[i].push_back(j+1);
        }
    }        
    return graph;
}



void print(v(int)&arr){
    cout<<"{";
    for(auto i=arr.begin(); i!=arr.end(); i++){
        cout<<*i;
        if(i!=arr.end()-1)
            cout<<",";
    }cout<<"}"<<endl;
}

/* 
INPUT

Ritoman's bfs code.
Enter the source node: 1
Enter the number of nodes: 6
Enter the Adjacency matrix:
0 0 1 0 1 1
0 0 1 0 1 0
1 1 0 1 1 1
0 0 1 0 0 1
1 1 1 0 0 0
1 0 1 1 0 0

OUTPUT

BFS path: {1,3,5,6,2,4}
*/