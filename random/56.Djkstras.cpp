//https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
#include<iostream>
#include<bits/stdc++.h>
#define int long int
# define INF INT_MAX 
using namespace std;

typedef pair<int, int> ipair; 
void shortestPath(vector<vector<ipair>> &adj, int V, int src) 
{ 
    
    priority_queue< ipair, vector <ipair> , greater<ipair> > pq; 
    vector<int> dist(V, INF); 
  
    pq.push(make_pair(0, src)); 
    dist[src] = 0; 
  
    while (!pq.empty()) 
    {
        int u = pq.top().second; 
        pq.pop(); 

        for (auto x : adj[u]) 
        { 
            int v = x.first; 
            int weight = x.second; 
  
            if (dist[v] > dist[u] + weight) 
            {               
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    } 

    cout<<"Vertex Distance from Source\n"; 
    for (int i = 0; i < V; ++i)
        cout<<i<<"\t\t"<<dist[i]<<endl;
} 

signed main(){
    int V = 9;
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 

    vector<vector<ipair>>adj(V,vector<ipair>());
    for(int i = 0; i<V; i++)
        for(int j = 0; j<V; j++)
            if(graph[i][j]>0)
                adj[i].push_back(make_pair(j, graph[i][j]));
            
    for (auto i: adj){
        for(auto j: i)
            cout<<j.first<<" "<<j.second<<"\t";
        cout<<endl;
    }
    shortestPath(adj, V, 0);
} 




//g++ "56.Djkstras.cpp" && a
//g++ "F:\cpp\random\56.Djkstras.cpp" && a 