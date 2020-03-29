#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;
vector<int> dfs1(vector<vector<int>> *graph, int v, vector<bool> *vis,vector<int>* traversal );
vector<vector<int>> dft(vector<vector<int>> *graph);
vector<int> dfs(vector<vector<int>> *graph, int v);//not recommended for test cases
void print2d(vector<vector<int>> *graph);



int main(){
    vector<vector<int>> graph1,graph2;
    graph1 = {{2,3},{1,4,5},{1,6,7},{2,8},{2,8},{3,8},{3,8},{4,5,6,7}};
    graph2 = {{},{4,5},{6,7},{2},{2},{3},{3},{}};
    
    vector<vector<int>> components = dft(&graph2);
    print2d(&components);
    vector<int> df1 = dfs(&graph1, 1);
    for(int i: df1)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
vector<int> dfs(vector<vector<int>> *graph, int v){
    static vector<int> traversal;
    static vector<bool> vis((*graph).size(), false);
    vis[v-1] = true;
    traversal.push_back(v);
    for (int i: (*graph)[v-1]){
        if(not vis[i-1]){
            dfs(graph,i);
        }
    }
    return traversal;
}
vector<int> dfs1(vector<vector<int>> *graph, int v, vector<bool> *vis,vector<int>* traversal ){
    //static vector<int> traversal;
    (*vis)[v-1] = true;
    (*traversal).push_back(v);
    for (int i: (*graph)[v-1]){
        if(not (*vis)[i-1]){
            dfs1(graph,i,vis,traversal);
        }
    }
    return *traversal;
}
vector<vector<int>> dft(vector<vector<int>> *graph){
    int n = (*graph).size();
    vector<bool> visited(n, false);
    vector<vector<int>> components;
    for (int i = 1; i<=n; i++){
        if(!visited[i-1]){
            vector<int> traversal;
            components.push_back(dfs1(graph,i,&visited,&traversal));
        }
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
    }cout<<"}"<<endl;
}