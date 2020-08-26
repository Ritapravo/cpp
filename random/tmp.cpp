// Program to find Dijkstra's shortest path using 
// priority_queue in STL 
#include<bits/stdc++.h> 
using namespace std; 
# define INF 0x3f3f3f3f 

// ipair ==> Integer Pair 
typedef pair<int, int> ipair; 

// To add an edge 
void addEdge(vector <pair<int, int> > adj[], int u, 
									int v, int wt) 
{ 
	adj[u].push_back(make_pair(v, wt)); 
	adj[v].push_back(make_pair(u, wt)); 
} 


// Prints shortest paths from src to all other vertices 
void shortestPath(vector<vector<ipair>> adj, int V, int src) 
{ 
	// Create a priority queue to store vertices that 
	// are being preprocessed. This is weird syntax in C++. 
	// Refer below link for details of this syntax 
	// http://geeksquiz.com/implement-min-heap-using-stl/ 
	priority_queue< ipair, vector <ipair> , greater<ipair> > pq; 

	// Create a vector for distances and initialize all 
	// distances as infinite (INF) 
	vector<int> dist(V, INF); 

	// Insert source itself in priority queue and initialize 
	// its distance as 0. 
	pq.push(make_pair(0, src)); 
	dist[src] = 0; 

	/* Looping till priority queue becomes empty (or all 
	distances are not finalized) */
	while (!pq.empty()) 
	{ 
		// The first vertex in pair is the minimum distance 
		// vertex, extract it from priority queue. 
		// vertex label is stored in second of pair (it 
		// has to be done this way to keep the vertices 
		// sorted distance (distance must be first item 
		// in pair) 
		int u = pq.top().second; 
		pq.pop(); 

		// Get all adjacent of u. 
		for (auto x : adj[u]) 
		{ 
			// Get vertex label and weight of current adjacent 
			// of u. 
			int v = x.first; 
			int weight = x.second; 

			// If there is shorted path to v through u. 
			if (dist[v] > dist[u] + weight) 
			{ 
				// Updating distance of v 
				dist[v] = dist[u] + weight; 
				pq.push(make_pair(dist[v], v)); 
			} 
		} 
	} 

	// Print shortest distances stored in dist[] 
	printf("Vertex Distance from Source\n"); 
	for (int i = 0; i < V; ++i) 
		printf("%d \t\t %d\n", i, dist[i]); 
} 

// Driver program to test methods of graph class 
int main() 
{ 
	int V = 9; 
	//vector<ipair > adj[V]; 
    
	// making above shown graph 
	/* addEdge(adj, 0, 1, 4); 
	addEdge(adj, 0, 7, 8); 
	addEdge(adj, 1, 2, 8); 
	addEdge(adj, 1, 7, 11); 
	addEdge(adj, 2, 3, 7); 
	addEdge(adj, 2, 8, 2); 
	addEdge(adj, 2, 5, 4); 
	addEdge(adj, 3, 4, 9); 
	addEdge(adj, 3, 5, 14); 
	addEdge(adj, 4, 5, 10); 
	addEdge(adj, 5, 6, 2); 
	addEdge(adj, 6, 7, 1); 
	addEdge(adj, 6, 8, 6); 
	addEdge(adj, 7, 8, 7); */
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
	//shortestPath(adj, V, 0); 
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

//g++ "tmp.cpp" && a
//g++ "F:\cpp\random\tmp.cpp" && a 