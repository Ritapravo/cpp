#include<bits/stdc++.h> 
using namespace std; 
# define INF 0x3f3f3f3f 

// ipair ==> Integer Pair 
typedef pair<int, int> ipair; 

// Prints shortest paths from src to all other vertices 
void shortestPath(vector<vector<ipair>> adj, int V, int src) 
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

	printf("Vertex Distance from Source\n"); 
	for (int i = 0; i < V; ++i) 
		printf("%d \t\t %d\n", i, dist[i]); 
} 

int main() 
{ 
	int V = 9; 
    vector<vector<ipair>>adj(V,vector<ipair>()); 
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    for(int i = 0; i<V; i++){
        for(int j = 0; j<V; j++){
            if(graph[i][j]>0){
                adj[i].push_back(make_pair(j, graph[i][j]));
                //adj[j].push_back(make_pair(i, graph[i][j]));
            }
        }
    }
    for (auto i: adj){
        for(auto j: i)
            cout<<j.first<<" "<<j.second<<"     ";
        cout<<endl;
    }
    shortestPath(adj, V, 0); 

	return 0; 
} 
