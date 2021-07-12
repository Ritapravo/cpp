#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#define ll long long int

using namespace std;
void print2d(vector<vector<int>> *graph);
vector<vector<int>> makegraph();
vector<int> bfs(vector<vector<int>>*graph, int v, vector<bool> *visited);
vector<vector<int>> bft(vector<vector<int>> *graph);

int main(){
    cout<<"Ritoman's C++ code."<<endl;
    vector<vector<int>> graph /* = makegraph() */;
    //graph = {{2,3},{1,4,5},{1,6,7},{2,8},{2,8},{3,8},{3,8},{4,5,6,7}};
    graph = {{},{4,5},{6,7},{2},{2},{3},{3},{}};
    vector<vector<int>> components = bft(&graph);
    print2d(&components);
    return 0;
}

vector<int> bfs(vector<vector<int>>*graph, int v,vector<bool> *visited){
    int n = (*graph).size();
    //vector<bool> visited(n,false);
    queue<int> q;
    vector<int> traversal;
    int u = v;
    (*visited)[v-1]=true;
    while(true){
        traversal.push_back(u);
        //cout<<u<<" ";
        for(int i: (*graph)[u-1]){
            if(!(*visited)[i-1]){
                (*visited)[i-1]=true;
                q.push(i);
            }
        }
        if(q.empty())
            return traversal;
        else{
            u = q.front();
            q.pop();
        }
    }
}
vector<vector<int>> bft(vector<vector<int>> *graph){
    int n = (*graph).size();
    vector<bool> visited(n, false);
    vector<vector<int>> components;
    for (int i = 1; i<=n; i++){
        if(!visited[i-1])
            components.push_back(bfs(graph,i,&visited));
    }
    return components;
}

void print2d(vector<vector<int>> *graph){
    cout<<"{";
    for(vector<int> i:*graph){
        cout<<"{";
        for(int j :i){
            cout<<j;
            if(j!=*(i.end()-1))
                cout<<",";
        }
        cout<<"}";
        if(i!=*((*graph).end()-1))
            cout<<",";
    }cout<<"}";
}
vector<vector<int>> makegraph(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>> graph(n,vector<int>(0));
    for(int i=0; i<e; i++){
        int x,y;
        cin>>x>>y;
        graph[x-1].push_back(y);
        graph[y-1].push_back(x);
    }
    return graph;
}